#pragma once

// Includes
#include "gender.h"
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

public:
    Human(int age, std::string name, Gender gender, int money = 0);
    Human();
    ~Human() = default;
    virtual void work();
    int get_age() const;
    std::string get_name() const;
    int get_money() const;
};