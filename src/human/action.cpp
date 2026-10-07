// Includes
#include "Include/Human/action.h"
#include "Include/errors.h"
// Includes

// STL Includes

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