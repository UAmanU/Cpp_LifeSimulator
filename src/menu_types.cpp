// Includes
#include "Include/menu_actions.h"
#include "Include/errors.h"
// Includes

// STL Includes

// STL Includes

std::string convert_menuTypes_toString(MenuTypes menu_type)
{
    switch (menu_type)
    {
    case MenuTypes::Game:
        return "Start Game";
    case MenuTypes::Exit:
        return "Exit";
    }
    throw Errors::InvalidDataError("I don't know that MenuType.");
}