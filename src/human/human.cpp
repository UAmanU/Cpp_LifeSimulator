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
    int perfomance;
    int new_energy = energy - job.energy_per_day;
    if (job.energy_per_day == 0)
    {
        perfomance = energy;
    }
    else
    {
        perfomance = energy / job.energy_per_day;
    }
    energy = (new_energy > 0 ? new_energy : 1);
    money += (job.salary * (perfomance < 1 ? perfomance : 1));
}
void Human::sleep()
{
    energy = (energy >= 65 ? 100 : energy + 20);
}
int Human::get_id() const
{
    return id;
}
std::string Human::get_name() const
{
    return name;
}
int Human::get_age() const
{
    return age;
}
Gender Human::get_gender() const
{
    return gender;
}
int Human::get_money() const
{
    return money;
}
Job Human::get_job() const
{
    return job;
}
int Human::get_energy() const
{
    return energy;
}
bool Human::need_to_rest() const
{
    return energy < (job.energy_per_day / 2);
}
void Human::set_id(int new_id)
{
    id = new_id;
}