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
void print_genders()
{
    std::vector<Gender> genders = {Gender::Male, Gender::Female, Gender::NA};
    for (const auto &gender : genders)
    {
        std::cout << static_cast<int>(gender) << ": " << convert_gender_toString(gender) << "\n";
    }
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
void print_work_message(const Human &human)
{
    std::string name = std::get<std::string>(human.get_stat(HumanStats::name));
    std::string job_name = convert_jobType_toString(std::get<Job>(human.get_stat(HumanStats::job)).job_type);
    std::cout << name + " is working as a " + job_name + ". Current energy after work: " << std::get<Job>(human.get_stat(HumanStats::job)).energy_per_day << "\n";
}
void print_sleep_message(const Human &human)
{
    std::string name = std::get<std::string>(human.get_stat(HumanStats::name));
    std::cout << name + " is sleeping. Current energy after sleep: " << std::get<Job>(human.get_stat(HumanStats::job)).energy_per_day << "\n";
}
void print_datasave_result(bool result)
{
    std::cout << (result ? "Data saved successfully." : "Data saving failed.") << "\n";
}