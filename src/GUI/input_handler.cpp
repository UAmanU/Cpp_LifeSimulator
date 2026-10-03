// Includes
#include "input_handler.h"
#include "include/errors.h"
// Includes

// STL Includes
#include <iostream>
#include <limits>
// STL Includes

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int gender_form()
{
    int gender;
    while (true)
    {
        std::cout << "Enter:\n";
        if (!(std::cin >> gender))
        {
            clear_cin();
            std::cout << "Only numbers!";
            continue;
        };
        break;
    }
    return gender;
}
std::string name_form()
{
    std::string name;
    while (true)
    {
        std::cout << "Enter your name:\n";
        if (!(std::cin >> name))
        {
            clear_cin();
            std::cout << "Only strings!";
            continue;
        };
        break;
    }
    return name;
}