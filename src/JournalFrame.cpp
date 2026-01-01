#include "JournalFrame.h"
#include "JournalPanels.h"
#include <wx/notebook.h>

JournalFrame::JournalFrame()
{
    wxXmlResource::Get()->LoadFrame(this, nullptr, "MainFrame");

    m_editorPanel = std::make_unique<EditorPanel>(this);
    m_historyPanel = std::make_unique<HistoryPanel>(this);
    m_settingsPanel = std::make_unique<SettingsPanel>(this);

    Bind(wxEVT_MENU, [=](wxCommandEvent &)
         { Close(true); }, XRCID("ExitSubItem"));
    Bind(wxEVT_MENU, &JournalFrame::OnInfo, this, XRCID("InfoSubItem"));
    Bind(wxEVT_MENU, &JournalFrame::OnHelloWorld, this, XRCID("HelloWorldSubItem"));
}

JournalFrame::~JournalFrame()
{
}

void JournalFrame::OnHelloWorld(wxCommandEvent &event)
{
    wxMessageBox("Hello world! This was made using wxFormBuilder and c++!",
                 "Enjoy your stay");
};

void JournalFrame::OnInfo(wxCommandEvent &event)
{
    wxMessageBox("This journal app is just a way for me to practice C++.",
                 "Yippee", wxOK | wxICON_INFORMATION);
}
