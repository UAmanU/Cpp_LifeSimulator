// Includes
#include "Include/Storage/storage_manager.h"
#include "Include/errors.h"
// Includes

// STL Includes

// STL Includes

StorageManager::StorageManager(std::unique_ptr<IStorage> storage) : storage(std::move(storage)) {};
void StorageManager::prepare_database()
{
    storage->create_table();
}
void StorageManager::reset_database()
{
    storage->clear_database();
}
std::vector<Human> StorageManager::get_all_players()
{
    std::vector<Human> all_players;
    std::vector<int> all_ids = storage->get_all_id();
    all_players.reserve(all_ids.size());
    for (int id : all_ids)
    {
        Human player = get_player(id);
        all_players.push_back(std::move(player));
    }
    return all_players;
}
int StorageManager::add_player(const Human &player)
{
    int id = -1;
    player_data raw_data = convert_human_toData(player);

    if (is_data_valid(raw_data))
    {
        bool result = storage->add_data(std::move(raw_data));
        if (result)
        {
            id = storage->get_last_id();
        }
    }
    else
    {
        throw Errors::StorageManagerError("Illegal data to put in database.");
    }
    return id;
}
Human StorageManager::get_player(int player_id)
{
    if (!(is_id_valid(player_id)))
    {
        throw Errors::StorageManagerError("Id cannot be negative.");
    }
    player_data raw_data = storage->get_player_data(player_id);
    Human human;
    if (is_data_valid(raw_data))
    {
        human = convert_data_toHuman(raw_data);
    }
    else
    {
        throw Errors::StorageManagerError("Illegal data in database.");
    }
    return human;
}

void StorageManager::delete_player(int player_id)
{
    storage->delete_data(player_id);
}
bool StorageManager::is_id_valid(int id) const
{
    return id > 0;
}
bool StorageManager::is_data_valid(player_data &data) const
{
    if (!(data.contains(HumanStats::id) && data.contains(HumanStats::age) && data.contains(HumanStats::money) && data.contains(HumanStats::gender) && data.contains(HumanStats::name) && data.contains(HumanStats::job)))
    {
        return false;
    }
    bool is_age_valid = std::get<int>(data[HumanStats::age]) >= 0;
    bool is_money_valid = std::get<int>(data[HumanStats::money]) >= 0;
    return is_age_valid && is_money_valid;
}
Human StorageManager::convert_data_toHuman(player_data &data) const
{
    int player_id = std::get<int>(data[HumanStats::id]);
    std::string player_name = std::get<std::string>(data[HumanStats::name]);
    int player_age = std::get<int>(data[HumanStats::age]);
    Gender player_gender = convert_int_toGender(std::get<int>(data[HumanStats::gender]));
    int player_money = std::get<int>(data[HumanStats::money]);

    JobType job_type = convert_string_toJobType(std::get<std::string>(data[HumanStats::job]));
    int salary = std::get<int>(data[HumanStats::salary]);
    Job player_job = Job(salary, job_type);
    return Human(player_id, player_age, player_name, player_gender, player_job, player_money);
}
player_data StorageManager::convert_human_toData(const Human &human) const
{
    player_data data;
    data[HumanStats::id] = human.get_id();
    data[HumanStats::name] = human.get_name();
    data[HumanStats::age] = human.get_age();
    data[HumanStats::money] = human.get_money();
    data[HumanStats::gender] = static_cast<int>(human.get_gender());
    data[HumanStats::job] = convert_jobType_toString(human.get_job().job_type);
    data[HumanStats::salary] = human.get_job().salary;
    return data;
}
bool StorageManager::update_player(Human player)
{
    player_data raw_data = convert_human_toData(player);
    if (is_data_valid(raw_data))
    {
        return storage->update_data(std::get<int>(raw_data[HumanStats::id]), raw_data);
    }
    else
    {
        throw Errors::StorageManagerError("Illegal data to put in database.");
    }
}
bool StorageManager::update_all_players(std::vector<Human> players)
{
    for (Human player : players)
    {
        if (!(update_player(std::move(player))))
        {
            return false;
        }
    }
    return true;
}