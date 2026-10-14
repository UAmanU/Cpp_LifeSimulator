#pragma once

// Includes
#include "game_launcher.h"
#include "Include/menu_actions.h"
// Includes

// STL Includes

// STL Includes

/*This is the ProgrammLauncher class.
it handles menu, owns GameLauncher, Settings class and storage_manager smart pointer*/
class ProgrammLauncher
{
private:
    std::unique_ptr<StorageManager> storage_manager;
    std::unique_ptr<GameLauncher> game_launcher;
    std::vector<MenuTypes> menu_types = {MenuTypes::Game, MenuTypes::ResetDatabase, MenuTypes::ReadAllPlayers, MenuTypes::AddNewPlayer, MenuTypes::Exit};
    int menu_form();
    void redirect_user(int choice);

public:
    ProgrammLauncher(std::unique_ptr<StorageManager> storage_manager, std::unique_ptr<GameLauncher> game_launcher);
    ~ProgrammLauncher() = default;
    void start();
};