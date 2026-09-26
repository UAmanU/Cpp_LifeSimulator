#pragma once

// Includes
#include "gender.h"
#include "job.h"
// Includes

// STL Includes
#include <string>

// STL Includes

enum class HumanStats
{
    age,
    name,
    gender,
    money
};
class Human
{
protected:
    int age;
    std::string name;
    Gender gender;
    int money;
    Job job;
    int energy;

public:
    Human(int age, std::string name, Gender gender, int money = 0, Job job);
    Human();
    ~Human() = default;
    virtual void work();
    virtual void sleep();
    int get_age() const;
    std::string get_name() const;
    int get_money() const;
    bool need_to_rest() const;
};