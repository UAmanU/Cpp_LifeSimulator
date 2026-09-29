#pragma once

// Includes

// Includes

// STL Includes
#include <string>
#include <variant>
#include <map>
#include "gender.h"
#include "human.h"
// STL Includes

using player_data_types = std::variant<std::string, int>;
using player_data = std::map<HumanStats, player_data_types>;
class IStorage
{
public:
    IStorage() = default;
    virtual ~IStorage() = default;
    virtual void create_table();
    virtual bool add_data(player_data player_stats) = 0;
    virtual bool delete_data(int id) = 0;
    virtual bool clear_database() = 0;
    virtual player_data get_player_data(int id) = 0;
    virtual bool update_data(int id, const player_data player_stats) = 0;
};