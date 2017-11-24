#include "MainFrame.h"

#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/grid.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 600))
{
    /*wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");*/

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    auto nvrAddressSizer = new wxBoxSizer(wxHORIZONTAL);
    nvrAddressSizer->Add(new wxStaticText(panel, wxID_ANY, wxString::FromUTF8(_("Адрес NVR"))), 0, wxTOP, 6);
    nvrAddressSizer->Add(new wxTextCtrl(panel, wxID_ANY, _("")), 1, wxLEFT|wxRIGHT|wxEXPAND, 8);
    nvrAddressSizer->Add(new wxButton(panel, wxID_ANY, wxString::FromUTF8(_("Получить камеры"))), 0, 0, 0);

    auto centralSizer = new wxBoxSizer(wxHORIZONTAL);

    auto leftCentralSizer = new wxBoxSizer(wxVERTICAL);
    auto rightCentralSizer = new wxBoxSizer(wxVERTICAL);

    leftCentralSizer->Add(new wxStaticText(panel, wxID_ANY, wxString::FromUTF8(_("Камеры"))), 0, wxALIGN_LEFT|wxBOTTOM, 3);

    auto camerasGrid = new wxGrid(panel, wxID_ANY);

    camerasGrid->CreateGrid(0, 2, wxGrid::wxGridSelectRows);
    camerasGrid->SetRowLabelSize(25);
    camerasGrid->SetColLabelSize(50);
    camerasGrid->SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
    camerasGrid->SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    camerasGrid->SetColLabelValue(0, wxString::FromUTF8(_("Токен")));
    camerasGrid->SetColLabelValue(1, wxString::FromUTF8(_("Имя")));
    camerasGrid->UseNativeColHeader(true);
    camerasGrid->EnableGridLines(true);

    leftCentralSizer->Add(camerasGrid, 1, wxEXPAND|wxBOTTOM, 3);

    auto intervalStaticBox = new wxStaticBox(panel, wxID_ANY, wxString::FromUTF8(_("Интервал времени")));

    auto intervalSizer = new wxFlexGridSizer(3, 4, 10, 5);

    //intervalSizer->Add(-1, 10);
    intervalSizer->Add(new wxRadioButton(intervalStaticBox, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, wxRB_GROUP), 0, wxTOP|wxLEFT| wxALIGN_CENTER_VERTICAL, 22);
    intervalSizer->Add(new wxStaticText(intervalStaticBox, wxID_ANY, wxString::FromUTF8(_("За последние"))), 0, wxTOP|wxALIGN_LEFT| wxALIGN_CENTER_VERTICAL, 22);
    intervalSizer->Add(new wxSpinCtrl(intervalStaticBox, wxID_ANY), 0, wxTOP, 22);
    intervalSizer->Add(new wxComboBox(intervalStaticBox, wxID_ANY), 0, wxTOP|wxRIGHT, 22);

    intervalSizer->Add(new wxRadioButton(intervalStaticBox, wxID_ANY, _("")), 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 22);
    intervalSizer->Add(new wxStaticText(intervalStaticBox, wxID_ANY, wxString::FromUTF8(_("С"))), 0, wxALIGN_CENTER_VERTICAL);
    intervalSizer->Add(new wxDatePickerCtrl(intervalStaticBox, wxID_ANY), 0);
    intervalSizer->Add(new wxTimePickerCtrl(intervalStaticBox, wxID_ANY), 0);

    intervalSizer->Add(new wxStaticText(intervalStaticBox, wxID_ANY, _("")), 0, wxALIGN_CENTER_VERTICAL);
    intervalSizer->Add(new wxStaticText(intervalStaticBox, wxID_ANY, wxString::FromUTF8(_("По"))), 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM, 22);
    intervalSizer->Add(new wxDatePickerCtrl(intervalStaticBox, wxID_ANY), 0, wxBOTTOM, 22);
    intervalSizer->Add(new wxTimePickerCtrl(intervalStaticBox, wxID_ANY), 0, wxBOTTOM, 22);
    //intervalSizer->Add(-1, 10);

    intervalStaticBox->SetSizer(intervalSizer);

    leftCentralSizer->Add(intervalStaticBox, 0, 0, 0);

    rightCentralSizer->Add(new wxStaticText(panel, wxID_ANY, wxString::FromUTF8(_("Результат"))), 0, wxALIGN_LEFT|wxBOTTOM, 3);
    rightCentralSizer->Add(new wxTextCtrl(panel, wxID_ANY, _(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE), 1, wxEXPAND, 0);

    centralSizer->Add(leftCentralSizer, 1, wxEXPAND | wxRIGHT, 8);
    centralSizer->Add(rightCentralSizer, 2, wxEXPAND, 0);

    auto bottomSizer = new wxBoxSizer(wxHORIZONTAL);
    bottomSizer->Add(new wxButton(panel, wxID_ANY, wxString::FromUTF8(_("Поиск"))), 0, 0, 0);
    
    auto sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(-1, 8);
    sizer->Add(nvrAddressSizer, 0, wxEXPAND|wxLEFT|wxRIGHT, 8);
    sizer->Add(-1, 8);
    sizer->Add(centralSizer, 1, wxEXPAND|wxLEFT|wxRIGHT, 8);
    sizer->Add(-1, 8);
    sizer->Add(bottomSizer, 0, wxALIGN_RIGHT | wxBOTTOM | wxLEFT | wxRIGHT, 8);

    //sizer->Add(new wxDatePickerCtrl(panel, ID_FROM_DATE), 0, 0, 0);


    panel->SetSizer(sizer);

    Center();
}