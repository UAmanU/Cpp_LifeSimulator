#pragma once

// Includes

// Includes

// STL Includes
#include <string>
#include <unordered_map>
// STL Includes

/*Planet enum class isn't that useful in MVP but i'll make logic for each planet.
But at the moment, it's only enum class and function for getting std::string variant of planet.
Planet-type objects are usually owned by World.*/
enum class Planet
{
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};
std::unordered_map<Planet, std::string> planet_map = {
    {Planet::Mercury, "Mercury"},
    {Planet::Venus, "Venus"},
    {Planet::Earth, "Earth"},
    {Planet::Mars, "Mars"},
    {Planet::Jupiter, "Jupiter"},
    {Planet::Saturn, "Saturn"},
    {Planet::Uranus, "Uranus"},
    {Planet::Neptune, "Neptune"}};
std::string get_planet_name(Planet planet);