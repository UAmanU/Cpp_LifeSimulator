#pragma once

// Includes
#include "human/human.h"
#include "world/planet.h"
// Includes

// STL Includes
#include <vector>

// STL Includes

/*World class represents the game world, containing humans and a planet.
It provides methods to manage the humans and simulate a day in the world.*/
class World
{
private:
    std::vector<Human> humans;
    Planet planet;
    void add_person(Human human);
    void delete_random_person();

public:
    World();
    World(std::vector<Human> humans, Planet planet);

    bool start_day();
    void set_humans(std::vector<Human> humans);
    std::vector<Human> get_humans() const;
    Planet get_planet() const;
};