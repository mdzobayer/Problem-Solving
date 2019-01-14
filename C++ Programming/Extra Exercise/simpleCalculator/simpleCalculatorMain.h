/***************************************************************
 * Name:      simpleCalculatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Zobayer ()
 * Created:   2016-05-23
 * Copyright: Zobayer ()
 * License:
 **************************************************************/

#ifndef SIMPLECALCULATORMAIN_H
#define SIMPLECALCULATORMAIN_H

//(*Headers(simpleCalculatorFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class simpleCalculatorFrame: public wxFrame
{
    public:

        simpleCalculatorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~simpleCalculatorFrame();

    private:

        //(*Handlers(simpleCalculatorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(simpleCalculatorFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(simpleCalculatorFrame)
        wxButton* Button4;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxButton* Button3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SIMPLECALCULATORMAIN_H
