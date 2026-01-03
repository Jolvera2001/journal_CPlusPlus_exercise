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
    std::vector<JournalEntry> FindEntries();
    void SaveEntry(JournalEntry &newEntry);
    void UpdateEntry(int id, JournalEntry &newEntry);
    void DelelteEntry(int id);

private:
    sqlite3 *db;
    std::string dbPath;

    void InitializeTables();
};