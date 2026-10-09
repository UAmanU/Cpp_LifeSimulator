// Includes
#include "Include/Storage/config_manager.h"
#include "Include/errors.h"
// Includes

// STL Includes
#include <fstream>

// STL Includes

void ConfigManager::load_id()
{
    std::ifstream file("current_player_id.txt");
    if (!(file.is_open()))
    {
        player_id = -1;
        file.close();
        throw Errors::FileError("file doesn't exist!");
    }
    else
    {
        if (file.peek() == std::ifstream::traits_type::eof())
        {
            player_id = -1;
            file.close();
        }
        file >> player_id;
        file.close();
    }
}
void ConfigManager::set_new_id(int new_id)
{
    std::ofstream file("current_player_id.txt");
    if (file.is_open())
    {
        player_id = new_id;
        file << player_id;

        file.close();
    }
}
int ConfigManager::get_id() const
{
    return player_id;
}