#pragma once
#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include <memory>

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
    std::unique_ptr<EditorPanel> m_editorPanel;
    std::unique_ptr<HistoryPanel> m_historyPanel;
    std::unique_ptr<SettingsPanel> m_settingsPanel;

    wxMenuItem *helloWorldMenuItem, *exitMenuItem, *infoMenuItem;

    void OnTabChanged(wxBookCtrlEvent &event);
};