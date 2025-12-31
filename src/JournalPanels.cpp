#include "JournalPanels.h"

EditorPanel::EditorPanel(wxWindow *frame)
{
    titleEntry = XRCCTRL(*frame, "TitleEntry", wxTextCtrl);
    contentEntry = XRCCTRL(*frame, "ContentEntry", wxTextCtrl);
}

SettingsPanel::SettingsPanel(wxWindow *frame)
{
    dirPicker = XRCCTRL(*frame, "EntryDirPicker", wxDirPickerCtrl);
    entryGroupingChoice = XRCCTRL(*frame, "EntryGroupingChoice", wxChoice);
    fontSizeSpinner = XRCCTRL(*frame, "FontSpinner", wxSpinCtrl);
};