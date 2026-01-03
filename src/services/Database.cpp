#include "Database.h"

Database::Database(std::string &dbPath)
{
    int rc = sqlite3_open(dbPath.c_str(), &this->db);
    // create handle based on default path
    // instantiate tables
    // assign handle to this->db
};

Database::~Database()
{
    if (this->db) {
        sqlite3_close(db);
    }
};