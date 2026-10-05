#pragma once

// Includes

// Includes

// STL Includes

// STL Includes


/* ConfigManager - is a simple class and current_player_id.txt manager.
 This file contains the last user's id in database.
 It makes sense for checking the last user's id.*/
 
class ConfigManager
{
private:
    int player_id;

public:
    ConfigManager() = default;
    ~ConfigManager() = default;
    void load_id();
    void set_new_id(int new_id);
    int get_id() const;
};