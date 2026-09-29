// Includes
#include "storage_manager.h"
#include "include/errors.h"
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
bool StorageManager::add_player(const Human &player)
{
    bool result = false;
    player_data raw_data = convert_human_toData(player);

    if (is_data_valid(raw_data))
    {
        result = storage->add_data(raw_data);
    }
    else
    {
        throw Errors::StorageManagerError("Illegal data to put in database.");
    }
    return result;
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
bool StorageManager::add_player_money(int player_id, int amount)
{
    if (!(is_id_valid(player_id)))
    {
        throw Errors::StorageManagerError("Id cannot be negative.");
    }
    if (amount < 0)
    {
        throw Errors::StorageManagerError("Cannot add negative money amount.");
    }
    player_data new_human_data = storage->get_player_data(player_id);
    new_human_data[HumanStats::money] = std::get<int>(new_human_data[HumanStats::money]) + amount;
    bool result = false;
    result = storage->update_data(player_id, new_human_data);
    return result;
}
bool StorageManager::spend_player_money(int player_id, int amount)
{
    if (is_id_valid(player_id))
    {
        throw Errors::StorageManagerError("Id cannot be negative.");
    }
    if (amount < 0)
    {
        throw Errors::StorageManagerError("Cannot spend negative money amount.");
    }
    player_data new_human_data = storage->get_player_data(player_id);
    new_human_data[HumanStats::money] = std::get<int>(new_human_data[HumanStats::money]) - amount;
    bool result = false;
    result = storage->update_data(player_id, new_human_data);
    return result;
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
    Gender gender = convert_int_toGender(std::get<int>(data[HumanStats::gender]));
    int player_money = std::get<int>(data[HumanStats::money]);
}