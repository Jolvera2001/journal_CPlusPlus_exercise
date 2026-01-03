#include "Settings.h"

Settings::Settings() 
{
    std::string appDataDir = wxStandardPaths::Get().GetUserDataDir().ToStdString();
    fs::path setPath = fs::path(appDataDir) / "settings.json";

    this->settingsPath = setPath;

    LoadSettings();
}

void Settings::SaveSettings()
{
    json j = appSettings.ToJson();
    std::ofstream file(this->settingsPath);
    file << j.dump(4);
}

void Settings::LoadSettings() 
{
    if (fs::exists(this->settingsPath)) {
        std::ifstream file(this->settingsPath);
        json j = json::parse(file);
        appSettings = JournalAppSettings::FromJson(j);
    } else {
        std::string appDataDir = wxStandardPaths::Get().GetUserDataDir().ToStdString();
        fs::path databaseLocation = fs::path(appDataDir) / "JournalEntries.db";

        appSettings.dbPath = databaseLocation.string();
        appSettings.entryFontSize = 12;

        SaveSettings();
    }
}