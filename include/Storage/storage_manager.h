#pragma once

// Includes
#include "storage.h"
// Includes

// STL Includes
#include <memory>
#include <vector>
// STL Includes

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
    bool add_player(const Human &player);
    std::vector<Human> get_all_players();
    Human get_player(int player_id);
    void delete_player(int player_id);
    bool update_all_players(std::vector<Human> players);
};