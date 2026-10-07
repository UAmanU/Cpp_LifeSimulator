// Includes
#include "Include/Human/human.h"
#include "Include/errors.h"
// Includes

// STL Includes
#include <unordered_map>

// STL Includes

Human::Human() : age(0), gender(Gender::NA), job(Job()) {};
Human::Human(int id, int age, std::string name, Gender gender, Job job, int money) : id(id), age(age), name(std::move(name)), gender(gender), money(money), job(std::move(job)) {};
void Human::work()
{
    int new_energy = energy - job.energy_per_day;
    int perfomance = energy / job.energy_per_day;
    energy = (new_energy > 0 ? new_energy : 1);
    money += (job.salary * (perfomance < 1 ? perfomance : 1));
}
void Human::sleep()
{
    energy = (energy >= 50 ? 100 : energy + 20);
}
player_data_types Human::get_stat(HumanStats stat) const
{
    switch (stat)
    {
    case HumanStats::id:
        return id;
    case HumanStats::name:
        return name;
    case HumanStats::age:
        return age;
    case HumanStats::money:
        return money;
    case HumanStats::salary:
        return job.salary;
    }
    throw Errors::InvalidDataError("Invalid stat requested.");
}
bool Human::need_to_rest() const
{
    return energy < (job.energy_per_day / 2);
}
void Human::set_id(int new_id)
{
    id = new_id;
}