#pragma once
#include <fstream>
#include <filesystem>
#include <wx/stdpaths.h>
#include "json.hpp"
#include "../models/JournalAppSettings.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Settings
{
public:
    Settings();
    ~Settings();

    void SaveSettings();
    JournalAppSettings &GetSettings() { return this->appSettings; }

private:
    JournalAppSettings appSettings;
    fs::path settingsPath;

    void LoadSettings();
};