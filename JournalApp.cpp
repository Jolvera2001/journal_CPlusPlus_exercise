#include "JournalApp.h"

bool JournalApp::OnInit()
{
    SetAppName("Journal");

    auto frame = new JournalFrame();
    frame->Show(true);

    return true;
}