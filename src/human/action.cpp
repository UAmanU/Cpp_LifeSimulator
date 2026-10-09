// Includes
#include "Include/Human/action.h"
#include "Include/errors.h"
// Includes

// STL Includes
#include <random>
// STL Includes

HumanActions convert_int_toHumanActions(int number)
{
    switch (number)
    {
    case 1:
        return HumanActions::work;
    case 2:
        return HumanActions::sleep;
    case 3:
        return HumanActions::NA;
    }
    throw Errors::InvalidDataError("There is no human action with " + std::to_string(number) + " id.");
}
HumanActions choose_random_action()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 2);
    return convert_int_toHumanActions(dist(gen));
}