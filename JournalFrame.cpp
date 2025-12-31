#include "JournalFrame.h"
#include "JournalPanel.h"
#include <wx/notebook.h>

JournalFrame::JournalFrame() : wxFrame(nullptr, wxID_ANY, "Hello world", wxDefaultPosition, wxSize(700, 500))
{
    auto notebook = new wxNotebook(this, wxID_ANY);

    notebook->AddPage(new JournalPanel(notebook), "Editor", true);
    notebook->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, &JournalFrame::OnTabChanged, this);
}

void JournalFrame::OnTabChanged(wxBookCtrlEvent &event)
{
    int page = event.GetSelection();
    wxLogMessage("Switched to tab %d", page);
}