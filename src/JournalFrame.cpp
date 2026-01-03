#include "JournalFrame.h"
#include "JournalPanels.h"

JournalFrame::JournalFrame()
    : settings()
{
    this->database = std::make_unique<Database>(GetDatabasePath());

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

std::string JournalFrame::GetDatabasePath()
{
    std::string appDataDir = wxStandardPaths::Get().GetUserDataDir().ToStdString();
    return appDataDir;
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

// void LoadEntries(wxCommandEvent &event)
// {
//      load data when navigating to History page (probably 1)
//      means it could be very simple to load entries
//      maybe. The panel itself should have some method to accept a new list or something
// }
