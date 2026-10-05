#pragma once

// Includes
#include "world/world.h"
#include "storage/storage_manager.h"
#include "storage/config_manager.h"
// Includes

// STL Includes
#include <memory>

// STL Includes

/*This is the ProgrammLauncher class. it owns the Database part, business logic and GUI.
It means programm_launcher doesn't call SQL .db or prints the statements by itself, it calls functions that will do this work. */
class ProgrammLauncher
{
private:
    std::unique_ptr<StorageManager> storage_manager;
    std::unique_ptr<World> world;
    ConfigManager config_manager;
    bool save();
    bool is_user_registered();
    Human create_new_human() const;
    void register_human(Human &human);

public:
    ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<World> world);
    ~ProgrammLauncher() = default;
    void start();
};