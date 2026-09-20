// Includes
#include "human.h"
// Includes

// STL Includes

// STL Includes
Human::Human() : age(0), gender(Gender::NA) {};
Human::Human(int age, std::string name, Gender gender, int money = 0) : age(age), name(std::move(name)), gender(gender), money(money) {};
void Human::work()
{
    money += 100;
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