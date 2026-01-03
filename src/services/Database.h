#pragma once
#include <string>
#include "sqlite3.h"
#include "JournalEntryModel.h"

class Database
{
public:
    Database(std::string &dbPath);
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    sqlite3* GetHandle() { return db; }
    int FindEntries();
    int SaveEntry(JournalEntry &newEntry);
    int UpdateEntry(int id, JournalEntry &newEntry);

private:
    sqlite3 *db;
    std::string dbPath;
};