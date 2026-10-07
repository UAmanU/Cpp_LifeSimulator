// Includes
#include "include/world/world.h"

// Includes

// STL Includes

// STL Includes

World::World() : humans(std::vector<Human>()), planet(Planet()) {};
World::World(std::vector<Human> humans, Planet planet) : humans(std::move(humans)), planet(planet) {};
std::vector<Human> World::get_humans() const
{
    return humans;
}
void World::set_humans(std::vector<Human> humans)
{
    humans = std::move(humans);
}

void World::add_person(Human human)
{
    humans.push_back(std::move(human));
}
Planet World::get_planet() const
{
    return planet;
}