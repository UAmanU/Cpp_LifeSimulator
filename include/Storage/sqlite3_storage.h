#pragma once
// Includes
#include "storage.h"

// Includes

// STL Includes

// STL Includes

class SQLITE3_Storage : public IStorage
{
public:
    SQLITE3_Storage() = default;
    ~SQLITE3_Storage() = default;
    void create_table() override;
    bool add_data(player_data) override;
    bool delete_data(int id) override;
    void clear_database() override;
    player_data_types get_player_stat(const std::string &name, HumanStats stat) override;
    void set_player_money(const std::string &name, int delta) override;
};