#include "Database.h"

Database::Database(std::string &dbPath)
{
    const std::string dbName = "JournalEntries.db";

    fs::path fullPath = fs::path(dbPath) / dbName;
    int rc = sqlite3_open(fullPath.string().c_str(), &this->db);

    if (rc != SQLITE_OK)
    {
        const std::string errorMessage = "Error initializing or connecting to database";
        sqlite3_close(this->db);
        this->db = nullptr;
        throw std::runtime_error(errorMessage);
    }

    InitializeTables();
};

Database::~Database()
{
    if (this->db)
    {
        sqlite3_close(db);
    }
};

void Database::InitializeTables()
{
    const char *sql =
        "CREATE TABLE IF NOT EXISTS entries ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT"
        "created_at TEXT NOT NULL"
        "updated_at TEXT NOT NULL"
        "title TEXT NOT NULL"
        "content TEXT NOT NULL"
        ");";

    char *errMsg = nullptr;
    int rc = sqlite3_exec(this->db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        sqlite3_free(errMsg);
    }
}