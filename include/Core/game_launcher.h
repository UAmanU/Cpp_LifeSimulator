#pragma once

// Includes
#include "Include/Storage/storage_manager.h"
#include "Include/World/world.h"
#include "Include/Storage/config_manager.h"
// Includes

// STL Includes
#include <memory>
// STL Includes

/*This is a planned class for managing the game loop. It is owned by ProgrammLauncher.
It owns storage_manager, world.*/
class GameLauncher
{
private:
    StorageManager &storage_manager;
    std::unique_ptr<World> world;
    ConfigManager config_manager;
    Human create_new_human() const;
    void register_human(Human &human);
    Job job_form() const;
    bool is_user_registered();
    bool save();

public:
    GameLauncher(StorageManager &storage_manager, std::unique_ptr<World> world);
    ~GameLauncher() = default;
    void start_game();
};