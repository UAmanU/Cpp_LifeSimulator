#pragma once

// Includes
#include "storage.h"
// Includes

// STL Includes
#include <memory>

// STL Includes

class StorageManager
{
private:
    std::unique_ptr<IStorage> storage;

public:
    StorageManager(std::unique_ptr<IStorage> storage);
    ~StorageManager() = default;
    void prepare_database();
    void reset_database();
    bool add_player(Human player);
    Human get_player(const std::string &player_name);
    bool add_player_money(const std::string &player_name, int amount);
    bool spend_player_money(const std::string &player_name, int amount);
    void delete_player(const std::string &player_name);
};