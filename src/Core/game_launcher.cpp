// Includes
#include "Include/Core/game_launcher.h"
#include "Include/GUI/display_handler.h"
#include "Include/GUI/input_handler.h"
#include "Include/errors.h"
// Includes

// STL Includes

// STL Includes

GameLauncher::GameLauncher(StorageManager &storage_manager, std::unique_ptr<World> world) : storage_manager(storage_manager), world(std::move(world)) {};
bool GameLauncher::is_user_registered()
{
    return config_manager.get_id() != -1;
}
bool GameLauncher::save()
{
    std::vector<Human> humans = world->get_humans();
    bool result = storage_manager.update_all_players(std::move(humans));
    config_manager.load_id();
    return result;
}
Job GameLauncher::job_form() const
{
    std::vector<std::string> jobs = get_all_jobNames();
    std::vector<JobType> jobs_types;
    for (const std::string &job : jobs)
    {
        jobs_types.push_back(convert_string_toJobType(job));
    }
    print_all_jobs(jobs);
    int choice = number_form();
    if (choice > jobs.size())
    {
        throw Errors::InvalidDataError("I don't know job with " + std::to_string(choice) + " id.");
    }
    JobType chosen_jobType = jobs_types[choice - 1];
    return Job(static_cast<int>(chosen_jobType), chosen_jobType);
}
Human GameLauncher::create_new_human() const
{
    std::string name = name_form();
    print_all_genders({"Male", "Female"});
    int gender_int = number_form();
    if (gender_int > 2)
    {
        throw Errors::InputError("Invalid gender id: " + std::to_string(gender_int));
    }
    Gender gender = convert_int_toGender(gender_int - 1);

    int salary = 0;
    Human player(-1, 0, name, gender);
    return player;
}
void GameLauncher::register_human(Human &human)
{
    int id = storage_manager.add_player(human);
    human.set_id(id);
}
void GameLauncher::start_game()
{
    bool need_to_continue = true;
    config_manager.load_id();

    int user_id = config_manager.get_id();
    if (!(is_user_registered()))
    {
        while (true)
        {
            try
            {
                Human human = create_new_human();
                Job job = job_form();
                human.set_job(std::move(job));
                register_human(human);
                user_id = human.get_id();
                config_manager.set_new_id(user_id);
                break;
            }
            catch (const Errors::InputError &e)
            {
                print_error(e.what());
            }
            catch (const Errors::InvalidDataError &e)
            {
                print_error(e.what());
            }
        }
    }
    std::vector<Human> humans = storage_manager.get_all_players();
    world->set_humans(std::move(humans));
    print_world_stats(*world);
    Human current_human;
    HumanActions current_action;
    std::vector<std::string> actions = {"work", "sleep"};
    while (need_to_continue)
    {
        try
        {
            // Game loop
            print_action_choices(actions);
            int choice = number_form();
            if (choice > 2)
            {
                throw Errors::InputError("I don't have any choice with this id.");
            }
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
        catch (const Errors::InputError &e)
        {
            print_error(e.what());
        }
        catch (const Errors::InvalidDataError &e)
        {
            print_error(e.what());
        }
        catch (const std::exception &e)
        {
            print_error(e.what());
            save();
            return;
        }
        catch (...)
        {
            save();
            return;
        }
    }
    bool result = save();
    print_datasave_result(result);
}
