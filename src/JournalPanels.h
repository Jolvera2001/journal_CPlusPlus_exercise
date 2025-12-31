#pragma once
#include <wx/wx.h>
#include <wx/filepicker.h>

class EditorPanel : public wxPanel
{
public:
    EditorPanel(wxWindow *parent);

private:
    wxTextCtrl* titleEntry;
    wxTextCtrl* contentEntry;
};

class HistoryPanel : public wxPanel
{
public:
    HistoryPanel(wxWindow *parent);
};

class SettingsPanel : public wxPanel
{
public:
    SettingsPanel(wxWindow *parent);

private:
    wxDirPickerCtrl* dirPicker;
    wxChoice* EnterCriticalSection;
    wxSpinCtrl* fontSizeSpinner;
};