#pragma once

// Includes

// Includes

// STL Includes
#include <string>

// STL Includes

/*enum class MenuTypes is used in ProgrammLauncher class.
It doesn't contains any logic except function for converting it to string.*/

enum class MenuTypes
{
    Game,
    Exit
};

std::string convert_menuTypes_toString(const MenuTypes menu_type);