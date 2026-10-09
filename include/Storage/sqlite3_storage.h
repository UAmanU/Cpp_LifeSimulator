#pragma once
// Includes
#include "Storage/storage.h"

// Includes

// API Includes
#include <sqlite3.h>

// API Includes

// STL Includes
#include <vector>
// STL Includes

/*SQLITE3_STORAGE is a IStorage's child class, which uses SQLITE3 API for working with database.
SQLITE3_STORAGE owns an pointer to sqlite3 db.*/

class SQLITE3_Storage : public IStorage
{
private:
    sqlite3 *db = nullptr;
    sqlite3_stmt *stmt = nullptr;

public:
    SQLITE3_Storage() = default;
    ~SQLITE3_Storage();
    void create_table() override;
    std::vector<int> get_all_id() override;
    bool add_data(player_data player_stats) override;
    bool delete_data(int id) override;
    bool clear_database() override;
    player_data get_player_data(int id) override;
    bool update_data(int id, const player_data player_stats) override;
    void close_database();
    int get_last_id() override;
};
