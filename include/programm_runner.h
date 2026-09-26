#pragma once

// Includes
#include "world.h"
#include "storage_manager.h"
// Includes

// STL Includes
#include <memory>

// STL Includes

class ProgrammLauncher
{
private:
    std::unique_ptr<StorageManager> storage_manager;
    std::unique_ptr<World> world;

public:
    ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<World> world);
    ~ProgrammLauncher() = default;
    void start();
};