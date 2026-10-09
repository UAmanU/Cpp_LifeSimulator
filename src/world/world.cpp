// Includes
#include "Include/World/world.h"
#include "Include/errors.h"
// Includes

// STL Includes
#include <random>
// STL Includes

World::World() : humans(std::vector<Human>()), planet(Planet()) {};
World::World(std::vector<Human> humans, Planet planet) : humans(std::move(humans)), planet(planet) {};
std::vector<Human> World::get_humans() const
{
    return humans;
}
void World::set_humans(std::vector<Human> new_humans)
{
    humans = std::move(new_humans);
}

void World::add_person(Human human)
{
    humans.push_back(std::move(human));
}
auto World::choose_random_human() const
{
    if (humans.empty())
    {
        throw Errors::InvalidDataError("There're no humans - i can't choose the random one.");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, humans.size() - 1);
    return humans[dist(gen)];
}

void World::end_day()
{
    for (auto &human : humans)
    {
        human.sleep();
    }
}
int World::find_humanIndex_withId(int id) const
{
    if (humans.empty())
    {
        throw Errors::InvalidDataError("There're no humans - i can't find human with this id.");
    }
    for (int index = 0; index < humans.size(); index++)
    {
        Human current_human = humans[index];
        if (current_human.get_id() == id)
        {
            return index;
        }
    }
    throw Errors::InvalidDataError("There is not player with this id.");
}
Human World::human_action(HumanActions action, int id)
{
    Human *human_ptr;
    if (action == HumanActions::NA)
    {
        action = choose_random_action();
    }
    if (id == -1)
    {
        *human_ptr = choose_random_human();
    }
    else
    {
        *human_ptr = humans[find_humanIndex_withId(id)];
    }
    if (action == HumanActions::work)
    {
        human_ptr->work();
    }
    else if (action == HumanActions::sleep)
    {
        human_ptr->sleep();
    }
    human_ptr = nullptr;
}
Planet World::get_planet() const
{
    return planet;
}