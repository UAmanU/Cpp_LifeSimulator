// Includes
#include "include/world/planet.h"

// Includes

// STL Includes
#include <unordered_map>

// STL Includes

std::string get_planet_name(Planet planet)
{
    return planet_map.at(planet);
}