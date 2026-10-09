#pragma once

// Includes

// Includes

// STL Includes
#include <string>
#include <map>
// STL Includes

/*action.h file isn't that useful for MVP but it will make the code more readable.*/
enum class HumanActions : int
{
    work = 1,
    sleep = 2,
    NA = 3,
};
HumanActions convert_int_toHumanActions(int number);
HumanActions choose_random_action();