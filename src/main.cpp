// Includes
#include "programm_runner.h"
#include "sqlite3_storage.h"
// Includes

// STL Includes

// STL Includes

int main()
{
    // Code
    std::unique_ptr<IStorage> storage = std::make_unique<SQLITE3_Storage>();
    std::unique_ptr<StorageManager> storage_manager = std::make_unique<StorageManager>(std::move(storage));
    std::unique_ptr<World> world = std::make_unique<World>();

    std::unique_ptr<ProgrammLauncher> programm_launcher = std::make_unique<ProgrammLauncher>(std::move(storage_manager), std::move(world));
    programm_launcher->start();
    // Code
    return 0;
}