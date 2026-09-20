#pragma once
// Includes

// Includes

// STL Includes
#include <string>

// STL Includes

class Human
{
private:
    int age;
    std::string name;

public:
    Human();
    Human(int age, const std::string &name);
    ~Human() = default;
    virtual void work();
};