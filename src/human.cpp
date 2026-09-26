// Includes
#include "human.h"
// Includes

// STL Includes

// STL Includes
Human::Human() : age(0), gender(Gender::NA), job(Job()) {};
Human::Human(int age, std::string name, Gender gender, int money, Job job) : age(age), name(std::move(name)), gender(gender), money(money), job(std::move(job)) {};
void Human::work()
{
    int new_energy = energy - job.energy_per_day;
    int perfomance = energy / job.energy_per_day;
    energy = (new_energy > 0 ? new_energy : 1);
    money += (job.salary * (perfomance < 1 ? perfomance : 1));
}
void Human::sleep(){
    energy = (energy >= 50 ? 100 : energy+20);
}
int Human::get_age() const
{
    return age;
}
std::string Human::get_name() const
{
    return name;
}
int Human::get_money() const
{
    return money;
}
bool Human::need_to_rest() const{
    return energy<(job.energy_per_day/2);
}