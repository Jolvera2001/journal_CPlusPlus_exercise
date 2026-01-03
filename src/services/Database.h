#pragma once
#include <string>
#include <filesystem>
#include "sqlite3.h"
#include "../models/JournalEntryModel.h"

namespace fs = std::filesystem;

class Database
{
public:
    Database(const std::string &dbPath);
    ~Database();

    Database(const Database &) = delete;
    Database &operator=(const Database &) = delete;

    sqlite3 *GetHandle() { return db; }
    int FindEntries();
    int SaveEntry(JournalEntry &newEntry);
    int UpdateEntry(int id, JournalEntry &newEntry);

private:
    sqlite3 *db;
    std::string dbPath;

    void InitializeTables();
};