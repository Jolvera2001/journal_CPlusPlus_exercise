#pragma once
#include <string>
#include <wx/wx.h>

struct JournalEntry 
{
    int id;
    wxDateTime createdAt;
    wxDateTime updatedAt;
    wxString title;
    wxString content;
};