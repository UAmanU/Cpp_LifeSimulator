#pragma once

// Includes

// Includes

// STL Includes
#include <string>
#include <unordered_map>
// STL Includes

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
consteval std::unordered_map<Planet, std::string> planet_map = {
    {Planet::Mercury, "Mercury"},
    {Planet::Venus, "Venus"},
    {Planet::Earth, "Earth"},
    {Planet::Mars, "Mars"},
    {Planet::Jupiter, "Jupiter"},
    {Planet::Saturn, "Saturn"},
    {Planet::Uranus, "Uranus"},
    {Planet::Neptune, "Neptune"}};
std::string get_planet_name(Planet planet);