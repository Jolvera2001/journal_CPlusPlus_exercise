#include "JournalApp.h"
#include "JournalFrame.h"
#include "wx/xrc/xmlres.h"

bool JournalApp::OnInit()
{
    wxXmlResource::Get()->InitAllHandlers();

    wxXmlResource::Get()->Load("Main.xrc");

    SetAppName("Journal");

    auto frame = new JournalFrame();
    frame->Show(true);

    return true;
}