#include "JournalPanels.h"

EditorPanel::EditorPanel(wxWindow *frame)
{
    titleEntry = XRCCTRL(*frame, "TitleEntry", wxTextCtrl);
    contentEntry = XRCCTRL(*frame, "ContentEntry", wxTextCtrl);
}

HistoryPanel::HistoryPanel(wxWindow *frame)
{
}

SettingsPanel::SettingsPanel(wxWindow *frame)
{
    dirPicker = XRCCTRL(*frame, "EntryDirPicker", wxDirPickerCtrl);
    entryGroupingChoice = XRCCTRL(*frame, "EntryGroupingChoice", wxChoice);
    fontSizeSpinner = XRCCTRL(*frame, "FontSpinner", wxSpinCtrl);
};