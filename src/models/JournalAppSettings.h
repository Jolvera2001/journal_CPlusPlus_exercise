#pragma once
#include <string>
#include "json.hpp"

using json = nlohmann::json;

struct JournalAppSettings
{
    std::string dbPath;
    int entryFontSize;

    json ToJson() const
    {
        return json{
            {"dbPath", this->dbPath},
            {"entryFontSize", this->entryFontSize}
        };
    }

    static JournalAppSettings FromJson(const json &j)
    {
        JournalAppSettings settings;

        settings.dbPath = j.value("dbPath", "");
        settings.entryFontSize = j.value("entryFontSize", 12);
        
        return settings;
    }
};