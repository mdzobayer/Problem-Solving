/***************************************************************
 * Name:      simpleCalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Zobayer ()
 * Created:   2016-05-23
 * Copyright: Zobayer ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "simpleCalculatorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(simpleCalculatorFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(simpleCalculatorFrame)
const long simpleCalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long simpleCalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long simpleCalculatorFrame::ID_TEXTCTRL3 = wxNewId();
const long simpleCalculatorFrame::ID_STATICTEXT1 = wxNewId();
const long simpleCalculatorFrame::ID_STATICTEXT2 = wxNewId();
const long simpleCalculatorFrame::ID_STATICTEXT3 = wxNewId();
const long simpleCalculatorFrame::ID_BUTTON2 = wxNewId();
const long simpleCalculatorFrame::ID_BUTTON3 = wxNewId();
const long simpleCalculatorFrame::ID_BUTTON4 = wxNewId();
const long simpleCalculatorFrame::ID_BUTTON1 = wxNewId();
const long simpleCalculatorFrame::ID_MENUITEM1 = wxNewId();
const long simpleCalculatorFrame::idMenuAbout = wxNewId();
const long simpleCalculatorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(simpleCalculatorFrame,wxFrame)
    //(*EventTable(simpleCalculatorFrame)
    //*)
END_EVENT_TABLE()

simpleCalculatorFrame::simpleCalculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(simpleCalculatorFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,225));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(56,24), wxSize(264,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(56,64), wxSize(264,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(56,144), wxSize(264,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X ="), wxPoint(24,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y ="), wxPoint(24,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Result"), wxPoint(8,152), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Subtraction"), wxPoint(104,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Multiplication"), wxPoint(200,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("Divition"), wxPoint(304,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Addition"), wxPoint(8,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleCalculatorFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleCalculatorFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleCalculatorFrame::OnButton4Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleCalculatorFrame::OnButton1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleCalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleCalculatorFrame::OnAbout);
    //*)
}

simpleCalculatorFrame::~simpleCalculatorFrame()
{
    //(*Destroy(simpleCalculatorFrame)
    //*)
}

void simpleCalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void simpleCalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void simpleCalculatorFrame::OnButton1Click(wxCommandEvent& event)
{
    long x=0, y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue().ToLong((&x)) and TextCtrl2->GetValue().ToLong((&y)))
    {
        res<<x+y;
        TextCtrl3->SetValue(res);
    }
    else wxMessageBox((wxT("There is an error!")));
}

void simpleCalculatorFrame::OnButton2Click(wxCommandEvent& event)
{
    long x=0, y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue().ToLong((&x)) and TextCtrl2->GetValue().ToLong((&y)))
    {
        res<<x-y;
        TextCtrl3->SetValue(res);
    }
    else wxMessageBox((wxT("There is an error!")));
}

void simpleCalculatorFrame::OnButton3Click(wxCommandEvent& event)
{
    long x=0, y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue().ToLong((&x)) and TextCtrl2->GetValue().ToLong((&y)))
    {
        res<<x*y;
        TextCtrl3->SetValue(res);
    }
    else wxMessageBox((wxT("There is an error!")));
}

void simpleCalculatorFrame::OnButton4Click(wxCommandEvent& event)
{
    long x=0, y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue().ToLong((&x)) and TextCtrl2->GetValue().ToLong((&y)))
    {
        if (y == 0)
        {
            wxMessageBox((wxT("Denominator can't be zero!")));
            goto End;
        }
        res<<x/y;
        TextCtrl3->SetValue(res);
    }
    else wxMessageBox((wxT("There is an error!")));
    End:
    return;
}
