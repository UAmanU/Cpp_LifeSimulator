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
    case MenuTypes::ResetDatabase:
        return "Reset Database";
    case MenuTypes::ReadAllPlayers:
        return "Read all players";
    case MenuTypes::Exit:
        return "Exit";
    case MenuTypes::AddNewPlayer:
        return "Add new player";
    }
    throw Errors::InvalidDataError("I don't know that MenuType.");
}