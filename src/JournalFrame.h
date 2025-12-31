#pragma once
#include <wx/wx.h>
#include <memory>

class wxNotebook;
class wxBookCtrlEvent;
class EditorPanel;
class SettingsPanel;

class JournalFrame : public wxFrame
{
public:
    JournalFrame();
    ~JournalFrame();

private:
    std::unique_ptr<EditorPanel> m_editorPanel;
    std::unique_ptr<SettingsPanel> m_settingsPanel;

    void OnTabChanged(wxBookCtrlEvent& event);
};