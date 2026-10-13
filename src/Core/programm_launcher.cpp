// Includes
#include "Include/Core/programm_launcher.h"
#include "Include/GUI/display_handler.h"
#include "Include/GUI/input_handler.h"
// Includes

// STL Includes

// STL Includes

ProgrammLauncher::ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<GameLauncher> game_launcher) : storage_manager(std::move(storage_manager)), game_launcher(std::move(game_launcher)) {};
void ProgrammLauncher::redirect_user(int choice)
{
    switch (choice)
    {
    case 1:
        game_launcher->start_game();
        break;
    }
}
int ProgrammLauncher::menu_form()
{

    std::vector<std::string> raw_menu_types;
    for (const auto &menu_type : menu_types)
    {
        raw_menu_types.push_back(convert_menuTypes_toString(menu_type));
    }
    print_menu(raw_menu_types);
    int choice = number_form();
    if (choice > menu_types.size())
    {
        return -1;
    }
    return choice;
}
void ProgrammLauncher::start()
{
    greeting();
    while (true)
    {
        int choice = menu_form();
        if (choice == 2)
        {
            break;
        }
        redirect_user(choice);
    }

    goodbye();
}