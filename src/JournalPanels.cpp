#include <wx/xrc/xmlres.h>
#include "JournalPanels.h"

EditorPanel::EditorPanel(wxWindow *frame)
{
    titleEntry = XRCCTRL(*frame, "TitleEntry", wxTextCtrl);
    contentEntry = XRCCTRL(*frame, "ContentEntry", wxTextCtrl);
    saveButton = XRCCTRL(*frame, "SaveButton", wxButton);
    clearButton = XRCCTRL(*frame, "ClearButton", wxButton);

    saveButton->Bind(wxEVT_BUTTON, &EditorPanel::OnSave, this);
    clearButton->Bind(wxEVT_BUTTON, &EditorPanel::OnClear, this);
}

void EditorPanel::OnSave(wxCommandEvent &event)
{
    auto wxTitle = this->titleEntry->GetValue();
    auto wxContent = this->contentEntry->GetValue();

    wxString combined = "Title: " + wxTitle + "\n" + "Content: " + wxContent;

    wxMessageBox(combined, "Debug");
};

void EditorPanel::OnClear(wxCommandEvent &event)
{
    this->titleEntry->Clear();
    this->contentEntry->Clear();
};

HistoryPanel::HistoryPanel(wxWindow *frame)
{
}

SettingsPanel::SettingsPanel(wxWindow *frame)
{
    dirPicker = XRCCTRL(*frame, "EntryDirPicker", wxDirPickerCtrl);
    entryGroupingChoice = XRCCTRL(*frame, "EntryGroupingChoice", wxChoice);
    fontSizeSpinner = XRCCTRL(*frame, "FontSpinner", wxSpinCtrl);
};