#pragma once
// Includes
#include "storage.h"

// Includes

// STL Includes

// STL Includes

class SQLITE3_Storage : public IStorage
{
private:
    sqlite3 *db = nullptr;

public:
    SQLITE3_Storage() = default;
    ~SQLITE3_Storage() = default;
    void create_table() override;
    bool add_data(player_data player_data) override;
    bool delete_data(int id) override;
    bool clear_database() override;
    player_data get_player_data(int id) override;
    bool update_data(int id, player_data data);
    int get_player_id(const std::string &name) override;
    void close_database();
};