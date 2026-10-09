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
Job ProgrammLauncher::job_form() const
{
    std::vector<std::string> jobs = get_all_jobNames();
    std::vector<JobType> jobs_types;
    jobs_types.reserve(6);
    for (const std::string &job : jobs)
    {
        jobs_types.push_back(convert_string_toJobType(job));
    }
    print_all_jobs(jobs);
    int choice = choose_job();
    JobType chosen_jobType = jobs_types[choice];
    return Job(static_cast<int>(chosen_jobType), chosen_jobType);
}
Human ProgrammLauncher::create_new_human() const
{
    std::string name = name_form();
    int gender_int = gender_form();
    Gender gender = convert_int_toGender(gender_int);

    int salary = 0;
    Job job = job_form();
    Human player(-1, 0, name, gender, std::move(job));
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
                user_id = human.get_id();
                config_manager.set_new_id(user_id);
                break;
            }
            catch (const Errors::InputError &e)
            {
                print_error(e.what());
            }
        }
    }
    std::vector<Human> humans = storage_manager->get_all_players();
    world->set_humans(std::move(humans));
    print_world_stats(*world);
    Human current_human;
    HumanActions current_action;
    std::vector<std::string> actions = {"work", "sleep"};
    while (need_to_continue)
    {
        // Game loop
        print_action_choices(actions);
        int choice = choose_action();
        current_action = convert_int_toHumanActions(choice);
        current_human = world->human_action(current_action, user_id);
        print_action_message(current_human, current_action);
        current_action = choose_random_action();
        current_human = world->human_action(current_action);
        print_action_message(current_human, current_action);
        world->end_day();
        need_to_continue = continue_form();
        // Game loop
    }
    bool result = save();
    print_datasave_result(result);
    goodbye();
}