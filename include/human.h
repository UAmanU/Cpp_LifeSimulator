#pragma once

// Includes
#include "gender.h"
#include "job.h"
// Includes

// STL Includes
#include <string>
#include <variant>
// STL Includes

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
    ~Human() = default;
    virtual void work();
    virtual void sleep();
    player_data_types get_stat(HumanStats stat) const;
    bool need_to_rest() const;
    void set_id(int new_id);
};