// Includes
#include "sqlite3_storage.h"
#include "include/errors.h"
// Includes

// STL Includes

// STL Includes

void SQLITE3_Storage::create_table()
{
    int result = sqlite3_open("players.db", &db);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot create player database.");
    }
    const char *command = "CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY AUTOINCREMENT, age INTEGER, name TEXT NOT NULL, money INTEGER, gender INTEGER NOT NULL, job TEXT NOT NULL, salary INTEGER)";
    result = sqlite3_exec(db, command, nullptr, nullptr, nullptr);
    if (result != SQLITE_OK)
    {
        throw Errors::StorageError("Cannot executive a player database.");
    }
}
std::vector<int> SQLITE3_Storage::get_all_id()
{
    std::vector<int> all_ids;
    const char *select_id_command = "SELECT id FROM players";

    int result = sqlite3_prepare_v2(db, select_id_command, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot select data from players database.");
    }

    sqlite3_step(stmt);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        all_ids.push_back(id);
    }
    return all_ids;
}
bool SQLITE3_Storage::add_data(player_data player_stats)
{
    const char *insert_command = "INSERT INTO players(name, age, money,gender, job, salary) VALUES(?,?,?,?,?,?)";

    std::string player_name = std::get<std::string>(player_stats[HumanStats::name]);
    int player_age = std::get<int>(player_stats[HumanStats::age]);
    int player_money = std::get<int>(player_stats[HumanStats::money]);
    int player_gender = std::get<int>(player_stats[HumanStats::gender]);
    std::string player_job = std::get<std::string>(player_stats[HumanStats::job]);
    int player_salary = std::get<int>(player_stats[HumanStats::salary]);

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
    sqlite3_bind_text(stmt, 5, player_job.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, player_salary);
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
    std::string raw_command = "SELECT name,age,money,gender,job,salary FROM players WHERE id = ?";

    int result = sqlite3_prepare_v2(db, raw_command.c_str(), -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot select data from players database.");
    }

    sqlite3_bind_int(stmt, 1, id);

    player_data data;
    int age;
    int money;
    std::string name;
    int gender;
    std::string job;
    int salary;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *raw_name = sqlite3_column_text(stmt, 0);
        name = reinterpret_cast<const char *>(raw_name);
        age = sqlite3_column_int(stmt, 1);
        money = sqlite3_column_int(stmt, 2);
        gender = sqlite3_column_int(stmt, 3);
        const unsigned char *raw_job = sqlite3_column_text(stmt, 4);
        job = reinterpret_cast<const char *>(raw_job);
        salary = sqlite3_column_int(stmt, 5);
    }

    data[HumanStats::name] = name;
    data[HumanStats::age] = age;
    data[HumanStats::money] = money;
    data[HumanStats::gender] = gender;
    data[HumanStats::job] = job;
    data[HumanStats::salary] = salary;
    sqlite3_finalize(stmt);
    return data;
}
bool SQLITE3_Storage::update_data(int id, player_data data)
{
    std::string raw_command = "UPDATE players SET name = ?, age = ?, money = ?, gender = ?, job = ?, salary = ? WHERE id = ?";

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
    sqlite3_bind_text(stmt, 5, std::get<std::string>(data[HumanStats::job]).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, std::get<int>(data[HumanStats::salary]));
    sqlite3_bind_int(stmt, 7, id);
    sqlite3_step(stmt);

    sqlite3_finalize(stmt);
    return true;
}
void SQLITE3_Storage::close_database()
{
    if (db)
    {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }
}
int SQLITE3_Storage::get_last_id()
{
    const char *select_last_id_command = "SELECT id FROM players ORDER BY id DESC LIMIT 1";

    int result = sqlite3_prepare_v2(db, select_last_id_command, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw Errors::StorageError("Cannot select data from players database.");
    }

    int last_id = -1;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        last_id = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return last_id;
}