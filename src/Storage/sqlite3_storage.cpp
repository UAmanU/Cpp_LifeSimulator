// Includes
#include "sqlite3_storage.h"
#include "include/errors.h"
// Includes

// API Includes
#include <sqlite3.h>

// API Includes

// STL Includes

// STL Includes

using sql_storage = SQLITE3_Storage;

void sql_storage::create_table()
{
    int result = sqlite3_open("players.db", &db);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot create player database.");
    }
    const char *command = "CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY AUTOINCREMENT, age INTEGER, name TEXT NOT NULL, money INTEGER, gender INTEGER NOT NULL)";
    result = sqlite3_exec(db, command, nullptr, nullptr, nullptr);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot executive a player database.");
    }
}
bool sql_storage::add_data(player_data player_data)
{
    std::string player_name = std::get<std::string>(player_data[HumanStats::name]);
    int player_gender = std::get<int>(player_data[HumanStats::gender]);
    int player_money = std::get<int>(player_data[HumanStats::money]);
    int player_age = std::get<int>(player_data[HumanStats::age]);
    const char *insert_command = "INSERT INTO players(name, age, money,gender) VALUES(?,?,?,?)";
    sqlite3_stmt *stmt = nullptr;
    int result = sqlite3_prepare_v2(db, insert_command, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot insert data to player database.");
    }
    sqlite3_bind_text(stmt, 1, player_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, player_age);
    sqlite3_bind_int(stmt, 3, player_money);
    sqlite3_bind_int(stmt, 4, player_gender);

    result = sqlite3_step(stmt);
    bool success = false;
    if (result != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot insert data to player database");
    }
    else
    {
        success = true;
    }
    sqlite3_finalize(stmt);

    return success;
}
bool SQLITE3_Storage::delete_data(int id)
{
    const char *delete_command = "DELETE FROM players WHERE id = ?";
    sqlite3_stmt *stmt = nullptr;

    int result = sqlite3_prepare_v2(db, delete_command, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot delete data from player database.");
    }
    sqlite3_bind_int(stmt, 1, id);
    result = sqlite3_step(stmt);
    bool success = false;
    if (result != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot delete data from player database");
    }
    else
    {
        success = true;
    }
    sqlite3_finalize(stmt);
    return success;
}
bool SQLITE3_Storage::clear_database()
{
    const char *clear_command = "DELETE FROM players";
    int result = sqlite3_exec(db, clear_command, nullptr, nullptr, nullptr);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot clear the database.");
    }
    return result == SQLITE_OK;
}
player_data SQLITE3_Storage::get_player_data(int id)
{
    std::string raw_command = "SELECT name,age,money,gender FROM players WHERE id = ?";
    sqlite3_stmt *stmt = nullptr;
    player_data data;
    int result = sqlite3_prepare_v2(db, raw_command.c_str(), -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot select data from players database.");
    }
    sqlite3_bind_int(stmt, 1, id);
    int age;
    int money;
    std::string name;
    int gender;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *raw_name = sqlite3_column_text(stmt, 0);
        name = reinterpret_cast<const char *>(raw_name);
        age = sqlite3_column_int(stmt, 1);
        money = sqlite3_column_int(stmt, 2);
        gender = sqlite3_column_int(stmt, 3);
    }
    data[HumanStats::name] = name;
    data[HumanStats::age] = age;
    data[HumanStats::money] = money;
    data[HumanStats::gender] = gender;
    sqlite3_finalize(stmt);
    return data;
}
bool SQLITE3_Storage::update_data(int id, player_data data)
{
    std::string raw_command = "UPDATE players SET name = ?, age = ?, money = ?, gender = ? WHERE id = ?";
    sqlite3_stmt *stmt = nullptr;
    int result = sqlite3_prepare_v2(db, raw_command.c_str(), -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot update data from players database.");
    }
    sqlite3_bind_text(stmt, 1, std::get<std::string>(data[HumanStats::name]).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, std::get<int>(data[HumanStats::age]));
    sqlite3_bind_int(stmt, 3, std::get<int>(data[HumanStats::money]));
    sqlite3_bind_int(stmt, 4, std::get<int>(data[HumanStats::gender]));
    sqlite3_bind_int(stmt, 5, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return true;
}
int SQLITE3_Storage::get_player_id(const std::string &name)
{
    std::string raw_command = "SELECT id FROM players WHERE name = ?";
    sqlite3_stmt *stmt = nullptr;
    int result = sqlite3_prepare_v2(db, raw_command.c_str(), -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot get id from players database.");
    }
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return id;
    }
    sqlite3_finalize(stmt);
    return -1;
}