// Includes
#include "Include/programm_launcher.h"
#include "Include/Storage/sqlite3_storage.h"
// Includes

// STL Includes

// STL Includes

/*
src/main.cpp launches the code : creates a smart pointers for storage_manager, world and programm_launcher.
The World and storage_manager are owned by programm launcher.
Then, main.cpp calls programm_launcher::start() method , which is like the core of programm.
*/
int main()
{
    // Code
    std::unique_ptr<IStorage> storage = std::make_unique<SQLITE3_Storage>();
    std::unique_ptr<StorageManager> storage_manager = std::make_unique<StorageManager>(std::move(storage));
    storage_manager->prepare_database();
    std::unique_ptr<World> world = std::make_unique<World>();

    std::unique_ptr<ProgrammLauncher> programm_launcher = std::make_unique<ProgrammLauncher>(std::move(storage_manager), std::move(world));
    programm_launcher->start();

    // Code
    return 0;
}