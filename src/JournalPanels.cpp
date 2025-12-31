#include "JournalPanels.h"

EditorPanel::EditorPanel(wxWindow *parent) : wxPanel(parent)
{
    auto vBox = new wxBoxSizer(wxVERTICAL);
    auto textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_WORDWRAP);

    vBox->Add(textCtrl, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(vBox);
}

SettingsPanel::SettingsPanel(wxWindow *parent) : wxPanel(parent)
{
    auto vBox = new wxBoxSizer(wxVERTICAL);

    this->SetSizer(vBox);
};