#include "App.h"

#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    auto frame = new MainFrame(wxString::FromUTF8(_("Программа тестирования NVR")));
    frame->Show(true);

    return true;
}