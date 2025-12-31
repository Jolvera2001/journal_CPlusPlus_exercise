#pragma once
#include <wx/wx.h>

class wxNotebook;
class wxBookCtrlEvent;

class JournalFrame : public wxFrame
{
public:
    JournalFrame();

private:
    void OnTabChanged(wxBookCtrlEvent& event);
};