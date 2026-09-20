#pragma once
// Includes
#include "gender.h"
// Includes

// STL Includes
#include <string>

// STL Includes

class Human
{
private:
    int age;
    std::string name;
    Gender gender;

public:
    Human();
    Human(int age, const std::string &name, Gender gender);
    ~Human() = default;
    virtual void work();
};