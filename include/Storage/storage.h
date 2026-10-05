#pragma once

// Includes
#include "human/gender.h"
#include "human/human.h"
// Includes

// STL Includes
#include <string>
#include <variant>
#include <map>

// STL Includes

/*IStorage - is an abstract class for Database part.
IStorage's child classes are owned by StorageManager class.
So for data transformation beetween storage and StorageManager, there're 2 using statements.
As you can see, Storage returns and takes std::map with player's data for connecting with the Database.*/

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