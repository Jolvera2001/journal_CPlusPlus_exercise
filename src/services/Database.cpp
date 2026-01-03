#include "Database.h"

Database::Database(const std::string &dbPath)
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

std::vector<JournalEntry> Database::FindEntries()
{

    const char *sql =
        "SELECT * FROM entries;";
    std::vector<JournalEntry> entries;
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        // put somethere here for error
        return entries;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        JournalEntry entry;

        entry.id = sqlite3_column_int(stmt, 0);

        wxDateTime createdTime;
        auto createdTimeStr = GetColumnText(stmt, 1);
        createdTime.ParseISOCombined(createdTimeStr);
        entry.createdAt = createdTime;

        wxDateTime updatedTime;
        auto updatedTimeStr = GetColumnText(stmt, 2);
        updatedTime.ParseISOCombined(updatedTimeStr);
        entry.updatedAt = updatedTime;

        auto titleStr = GetColumnText(stmt, 3);
        entry.title = wxString(titleStr);

        auto contentStr = GetColumnText(stmt, 4);
        entry.content = wxString(contentStr);

        entries.push_back(entry);
    }

    sqlite3_finalize(stmt);

    return entries;
}

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

std::string GetColumnText(sqlite3_stmt *stmt, int col) {
    const unsigned char *text = sqlite3_column_text(stmt, col);
    return text ? std::string(reinterpret_cast<const char*>(text)) : "";
}