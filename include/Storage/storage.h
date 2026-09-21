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

using player_data_types = std::variant<int, Gender, std::string>;
using player_data = std::map<HumanStats, player_data_types>;
class IStorage
{
public:
    IStorage() = default;
    ~IStorage() = default;
    virtual void create_table();
    virtual bool add_data(player_data) = 0;
    virtual bool delete_data(int id) = 0;
    virtual void clear_database() = 0;
    virtual player_data_types get_player_stat(const std::string &name, HumanStats stat) = 0;
    virtual void set_player_money(const std::string &name, int delta) = 0;
};