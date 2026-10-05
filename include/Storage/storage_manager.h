#pragma once

// Includes
#include "storage.h"
// Includes

// STL Includes
#include <memory>
#include <vector>
// STL Includes

/*StorageManager controls the Storage and makes it actually safer.
For example, there's a new player Alex. StorageManager will check Alex data's validality,
convert human's stats to player_data type (which is declared in include/Storage/storage.h) and call Storage's method for adding a new player.
StorageManager makes sense because Storage shouldn't know about business logic, it needs to only work with database and raw data.*/

class StorageManager
{
private:
    std::unique_ptr<IStorage> storage;
    Human convert_data_toHuman(player_data &data) const;
    player_data convert_human_toData(const Human &human) const;
    bool is_data_valid(player_data &data) const;
    bool is_id_valid(int id) const;
    bool update_player(Human player);

public:
    StorageManager(std::unique_ptr<IStorage> storage);
    ~StorageManager() = default;
    void prepare_database();
    void reset_database();
    int add_player(const Human &player);
    std::vector<Human> get_all_players();
    Human get_player(int player_id);
    void delete_player(int player_id);
    bool update_all_players(std::vector<Human> players);
};