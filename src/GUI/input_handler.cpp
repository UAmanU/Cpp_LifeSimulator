// Includes
#include "Include/GUI/input_handler.h"
#include "Include/errors.h"
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
    int choice;
    while (true)
    {
        std::cout << "Enter the id of Gender you want to be:\n";
        if (!(std::cin >> choice))
        {
            clear_cin();
            std::cout << "Only numbers!";
            continue;
        };
        if (choice <= 0)
        {
            std::cout << "Only positive numbers!\n";
            continue;
        }
        break;
    }
    return choice;
}
std::string name_form()
{
    std::string name;
    while (true)
    {
        std::cout << "Enter your name:\n";
        if (std::getline(std::cin, name))
        {
            std::cout << "Only strings!\n";
            continue;
        }

        if (name.length() >= 40 || name.length() <= 2)
        {
            std::cout << "name length must be from 3 to 40.\n";
            continue;
        }
        break;
    }
    return name;
}
int choose_job()
{
    int choice;
    while (true)
    {
        std::cout << "Enter id of job you want to work:\n";
        if (!(std::cin >> choice))
        {
            clear_cin();
            std::cout << "Only numbers!\n";
            continue;
        }
        else if (choice <= 0)
        {
            std::cout << "Only positive numbers!\n";
            continue;
        }
        break;
    }
    return choice;
}
bool continue_form()
{
    std::cout << "Continue?\n1 - yes;\n2 - no;\n";
    int choice;
    while (true)
    {
        std::cout << "Enter:\n";
        if (!(std::cin >> choice))
        {
            clear_cin();
            std::cout << "Only numbers!\n";
            continue;
        }
        else if (choice < 1 || choice > 2)
        {
            std::cout << "I don't know choice with " + std::to_string(choice) + " id.\n";
            continue;
        }
        break;
    }
    return choice == 1;
}
int choose_action()
{
    int choice;
    while (true)
    {
        std::cout << "Enter the number of your choice:\n";
        if (!(std::cin >> choice))
        {
            clear_cin();
            std::cout << "Only numbers!\n";
            continue;
        }
        else if (choice <= 0)
        {
            std::cout << "Only positive numbers!\n";
        }
        break;
    }
    return choice;
}