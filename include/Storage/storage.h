#pragma once

// Includes
#include "gender.h"
#include "human.h"
// Includes

// STL Includes
#include <string>
#include <variant>
#include <map>

// STL Includes

using raw_data_types = std::variant<std::string, int>;
using player_data = std::map<HumanStats, raw_data_types>;
class IStorage
{
public:
    IStorage() = default;
    virtual ~IStorage() = default;
    virtual void create_table();
    virtual std::vector<int> get_all_id() = 0;
    virtual bool add_data(player_data player_stats) = 0;
    virtual bool delete_data(int id) = 0;
    virtual bool clear_database() = 0;
    virtual player_data get_player_data(int id) = 0;
    virtual bool update_data(int id, const player_data player_stats) = 0;
    virtual int get_last_id() = 0;
};