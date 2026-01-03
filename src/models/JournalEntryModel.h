#pragma once
#include <string>
#include <wx/wx.h>

struct JournalEntry 
{
    int id;
    wxDateTime createdAt;
    wxDateTime updatedAt;
    std::string title;
    std::string content;
};