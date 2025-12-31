#include "JournalFrame.h"
#include "JournalPanels.h"
#include <wx/notebook.h>

JournalFrame::JournalFrame()
{
    wxXmlResource::Get()->LoadFrame(this, nullptr, "MainFrame");

    m_editorPanel = std::make_unique<EditorPanel>(this);
    m_historyPanel = std::make_unique<HistoryPanel>(this);
    m_settingsPanel = std::make_unique<SettingsPanel>(this);
}

void JournalFrame::OnTabChanged(wxBookCtrlEvent &event)
{
    int page = event.GetSelection();
    wxLogMessage("Switched to tab %d", page);
}