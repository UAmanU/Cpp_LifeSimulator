#pragma once

// Includes

// Includes

// STL Includes

// STL Includes

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