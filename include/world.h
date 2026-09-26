#pragma once

// Includes
#include "human.h"
#include "planet.h"
// Includes

// STL Includes
#include <vector>

// STL Includes

class World
{
private:
    std::vector<Human> humans;
    Planet planet;

public:
    World();
    World(std::vector<Human> humans, Planet planet);
    World(std::vector<Human> humans);
    void start_day();
    void add_person(Human human);
    void delete_random_person();
    void set_humans(std::vector<Human> humans);
};