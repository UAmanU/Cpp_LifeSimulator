// Includes
#include "programm_launcher.h"
#include "Include/GUI/input_handler.h"
#include "Include/GUI/display_handler.h"
#include "Include/errors.h"
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
    config_manager.load_id();
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
    config_manager.load_id();
    int user_id = config_manager.get_id();
    if (!(is_user_registered()))
    {
        while (true)
        {
            try
            {
                Human human = create_new_human();
                register_human(human);
                user_id = std::get<int>(human.get_stat(HumanStats::id));
                config_manager.set_new_id(user_id);
            }
            catch (const Errors::InputError &e)
            {
                print_error(e.what());
            }
        }
    }
    std::vector<Human> humans = storage_manager->get_all_players();
    world->set_humans(std::move(humans));
    while (need_to_continue)
    {
        // Game loop
        int choice = choose_action();
        world->human_action(convert_int_toHumanActions(choice), user_id);
        world->human_action();
        world->end_day();
        need_to_continue = continue_form();
        // Game loop
    }
    bool result = save();
    print_datasave_result(result);
    goodbye();
}