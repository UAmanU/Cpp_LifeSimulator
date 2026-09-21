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
    bool add_character(player_data);
    void clear_database();
    int get_player_id(const std::string &name);
    int get_player_money(const std::string &name);
};