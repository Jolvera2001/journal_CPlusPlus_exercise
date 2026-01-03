#pragma once
#include <wx/wx.h>
#include <wx/filepicker.h>
#include <wx/xrc/xmlres.h>
#include <wx/spinctrl.h>

class EditorPanel
{
public:
    EditorPanel(wxWindow *frame);

    void Clear();

private:
    wxTextCtrl *titleEntry, *contentEntry;
    wxButton *saveButton, *clearButton;

    void OnSave(wxCommandEvent &event);
    void OnClear(wxCommandEvent &event);
};

class HistoryPanel
{
public:
    HistoryPanel(wxWindow *frame);
};

class SettingsPanel
{
public:
    SettingsPanel(wxWindow *frame);

private:
    wxDirPickerCtrl *dirPicker;
    wxChoice *entryGroupingChoice;
    wxSpinCtrl *fontSizeSpinner;
};