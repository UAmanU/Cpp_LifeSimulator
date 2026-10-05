#pragma once

// Includes

// Includes

// STL Includes
#include <string>
#include <map>
// STL Includes

/*action.h file isn't that useful for MVP but it will make the code more readable.*/
enum class HumanActions
{
    work = 1,
    sleep = 2,
    NA = 3,
};
consteval std::map<int, HumanActions> int_HumanActions_map = {{static_cast<int>(HumanActions::work), HumanActions::work}, {static_cast<int>(HumanActions::sleep), HumanActions::sleep}};
HumanActions convert_int_toHumanActions(int number);
