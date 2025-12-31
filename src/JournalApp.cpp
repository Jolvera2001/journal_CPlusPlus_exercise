#include "JournalApp.h"
#include "JournalFrame.h"
#include "wx/xrc/xmlres.h"

bool JournalApp::OnInit()
{
    SetAppName("Journal");
    wxXmlResource::Get()->InitAllHandlers();

    if (!wxXmlResource::Get()->Load("main.xrc")) {
        wxLogError("Failed to get main.xrc");
        return false;
    }

    auto frame = new JournalFrame();
    frame->Show(true);

    return true;
}