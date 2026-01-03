#pragma once
#include <memory>
#include <wx/wx.h>
#include <filesystem>
#include <wx/notebook.h>
#include <wx/stdpaths.h>
#include <wx/xrc/xmlres.h>
#include "services/Database.h"
#include "services/Settings.h"

namespace fs = std::filesystem;

class wxNotebook;
class wxBookCtrlEvent;
class EditorPanel;
class HistoryPanel;
class SettingsPanel;

class JournalFrame : public wxFrame
{
public:
    JournalFrame();
    ~JournalFrame();

private:
    Settings settings;
    std::unique_ptr<Database> database;

    std::unique_ptr<EditorPanel> m_editorPanel;
    std::unique_ptr<HistoryPanel> m_historyPanel;
    std::unique_ptr<SettingsPanel> m_settingsPanel;

    std::string GetDatabasePath();

    void OnHelloWorld(wxCommandEvent &event);
    void OnInfo(wxCommandEvent &event);
};