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
    int result = sqlite3_open("../players.db", &db);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot create player database.");
    }
    const char *command = "CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, money INTEGER, gender INTEGER NOT NULL)";
    int result = sqlite3_exec(db, command, nullptr, nullptr, nullptr);
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
    const char *insert_command = "INSERT INTO players(name, money,gender) VALUES(?,?,?)";
    sqlite3_stmt *stmt = nullptr;
    int result = sqlite3_prepare_v2(db, insert_command, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot insert data to player database.");
    }
    sqlite3_bind_text(stmt, 1, player_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, player_money);
    sqlite3_bind_int(stmt, 3, player_gender);

    result = sqlite3_step(stmt);
    bool success = false;
    if (result != SQLITE_DONE)
    {
        throw Errors::StorageError("Cannot insert data to player database");
    }
    else
    {
        success = false;
    }
    sqlite3_finalize(stmt);

    return true;
}
