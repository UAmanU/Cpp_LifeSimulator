// Includes
#include "programm_launcher.h"
#include "include/GUI/input_handler.h"
#include "include/GUI/display_handler.h"
// Includes

// STL Includes

// STL Includes

ProgrammLauncher::ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<World> world) : storage_manager(std::move(storage_manager)), world(std::move(world)) {};
bool ProgrammLauncher::is_user_registered()
{
    return config_manager.get_id() != -1;
}
bool ProgrammLauncher::save()
{
    std::vector<Human> humans = world->get_humans();
    bool result = storage_manager->update_all_players(std::move(humans));
    return result;
}
Human ProgrammLauncher::create_new_human() const
{
    std::string name = name_form();
    int gender_int = gender_form();
    Gender gender = convert_int_toGender(gender_int);
    JobType job_type = JobType::NA;
    int salary = 0;
    Job job = Job(salary, job_type);
    Human player(-1, 0, name, gender, 0, job);
    return player;
}
void ProgrammLauncher::register_human(Human &human)
{
    int id = storage_manager->add_player(human);
    human.set_id(id);
}
void ProgrammLauncher::start()
{
    bool need_to_continue = true;
    greeting();

    if (!(is_user_registered()))
    {
        Human human = create_new_human();
        register_human(human);
        config_manager.set_new_id(std::get<int>(human.get_stat(HumanStats::id)));
    }
    std::vector<Human> humans = storage_manager->get_all_players();
    world->set_humans(std::move(humans));
    while (need_to_continue)
    {
        need_to_continue = world->start_day();
    }
    bool result = save();
    print_datasave_result(result);
    goodbye();
}