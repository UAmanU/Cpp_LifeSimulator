#pragma once

// Includes
#include "human/human.h"
#include "world/planet.h"
#include "human/action.h"
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
    auto choose_random_human() const;
    Human *find_human_withId(int id) const;

public:
    World();
    World(std::vector<Human> humans, Planet planet);
    Human human_action(HumanActions action = HumanActions::NA, int id = -1);
    void end_day();
    void set_humans(std::vector<Human> new_humans);
    std::vector<Human> get_humans() const;
    Planet get_planet() const;
};