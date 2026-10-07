// Includes
#include "Include/GUI/display_handler.h"
#include "Include/Job/job_types.h"
// Includes

// STL Includes
#include <iostream>
#include <vector>
// STL Includes

void greeting()
{
    std::cout << "Hello! This is a Life Simulator project.\n";
}
void goodbye()
{
    std::cout << "Bye bye!\n";
}
void print_error(const std::string &msg)
{
    std::cout << "Oops! " + msg << "\n";
}
void print_all_jobs(const std::vector<std::string> &jobs)
{
    std::cout << "Choose your job:\n";
    print_string_vector(jobs);
}
void print_string_vector(const std::vector<std::string> &vector)
{

    for (int index = 1; index < vector.size() + 1; index++)
    {
        std::string string = vector[index - 1];
        std::cout << std::to_string(index) + ": " + string + ";\n";
    }
}
void print_action_choices(const std::vector<std::string> &actions)
{
    std::cout << "Choose your action:\n";
    print_string_vector(actions);
}
void print_all_genders(const std::vector<std::string> &genders)
{
    std::cout << "What Gender do you want to be?\n";
    print_string_vector(genders);
}
void print_world_stats(const World &world)
{
    std::cout << "World stats:\n";
    std::cout << "Planet: " << get_planet_name(world.get_planet()) << "\n";
    std::cout << "Number of humans: " << world.get_humans().size() << "\n";
}
void print_character_stats(const Human &human)
{
    std::string name = std::get<std::string>(human.get_stat(HumanStats::name));
    int age = std::get<int>(human.get_stat(HumanStats::age));
    int money = std::get<int>(human.get_stat(HumanStats::money));
    Gender gender = std::get<Gender>(human.get_stat(HumanStats::gender));
    std::string job_name = convert_jobType_toString(std::get<Job>(human.get_stat(HumanStats::job)).job_type);
    int salary = std::get<Job>(human.get_stat(HumanStats::job)).salary;
    std::cout << name + "'s stats:\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Money: " << money << "\n";
    std::cout << "Gender: " + convert_gender_toString(gender) << "\n";
    std::cout << "Job: " << job_name << "\n";
    std::cout << "Salary: " << salary << "\n";
}
void print_action_message(const Human &human, HumanActions action)
{
    std::string name = std::get<std::string>(human.get_stat(HumanStats::name));
    std::string energy_state = "Current energy: " + std::to_string(std::get<int>(human.get_stat(HumanStats::energy)));
    std::string action_state;
    if (action == HumanActions::work)
    {
        std::string money = std::to_string(std::get<int>(human.get_stat(HumanStats::money)));
        action_state = name + " was working all day; his current money is: " + money;
    }
    else if (action == HumanActions::sleep)
    {
        action_state = name + "slept;";
    }
    std::cout << action_state + energy_state + "\n";
}

void print_datasave_result(bool result)
{
    std::cout << (result ? "Data saved successfully." : "Data saving failed.") << "\n";
}