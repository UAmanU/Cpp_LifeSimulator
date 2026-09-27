// Includes
#include "programm_launcher.h"
#include "input_handler.h"
// Includes

// STL Includes

// STL Includes

ProgrammLauncher::ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<World> world) : storage_manager(std::move(storage_manager)), world(std::move(world)) {};
void ProgrammLauncher::reg(){
    std::string name = reg_form();
}