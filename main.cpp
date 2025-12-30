#include <wx/wx.h>
#include <wx/notebook.h>

class JournalApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(JournalApp);

// Main UI

class JournalPanel : public wxPanel
{
public:
    JournalPanel(wxWindow *parent) : wxPanel(parent)
    {
        wxBoxSizer* vBox = new wxBoxSizer(wxVERTICAL);

        wxTextCtrl* textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_WORDWRAP);

        vBox->Add(textCtrl, 1, wxEXPAND | wxALL, 5);

        this->SetSizer(vBox);
    }
};


class JournalFrame : public wxFrame
{
public:
    JournalFrame() : wxFrame(nullptr, wxID_ANY, "Hello world", wxDefaultPosition, wxSize(700, 500))
    {
        wxNotebook *notebook = new wxNotebook(this, wxID_ANY);

        notebook->AddPage(new JournalPanel(notebook), "Editor", true);

        notebook->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, &JournalFrame::OnTabChanged, this);
    }

private:
    void OnTabChanged(wxBookCtrlEvent& event)
    {
        int page = event.GetSelection();
        wxLogMessage("Switched to tab %d", page);
    }
};


bool JournalApp::OnInit()
{
    JournalFrame* frame = new JournalFrame();
    frame->Show();
    return true;
}