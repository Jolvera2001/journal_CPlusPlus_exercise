#pragma once
#include "sqlite3.h"
#include "JournalEntryModel.h"

class Database
{
public:
    Database();
    int FindEntries();
    int SaveEntry(JournalEntry &newEntry);
    int UpdateEntry(int id, JournalEntry &newEntry);

private:
    sqlite3 *db;
};