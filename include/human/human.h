#pragma once

// Includes
#include "Human/gender.h"
#include "Job/job.h"
// Includes

// STL Includes
#include <string>
#include <variant>
// STL Includes

/*This file declares the most complex object in this project - Human.
enum class HumanStats is used for cleaner and more readable code, instead of creating unreadable system.
player_data_types - is a using statement for all class Human's attributes types.
class Human is an abstract class with a lot of attributes (id,name,Gender,job,energy,money and age).*/

enum class HumanStats
{
    id,
    age,
    name,
    gender,
    money,
    job,
    salary
};
using player_data_types = std::variant<int, std::string, Gender, Job>;
class Human
{
protected:
    int id;
    int age;
    std::string name;
    Gender gender;
    int money;
    Job job;
    int energy;

public:
    Human(int id, int age, std::string name, Gender gender, int money = 0, Job job);
    Human();
    virtual ~Human() = default;
    virtual void work();
    virtual void sleep();
    player_data_types get_stat(HumanStats stat) const;
    bool need_to_rest() const;
    void set_id(int new_id);
};