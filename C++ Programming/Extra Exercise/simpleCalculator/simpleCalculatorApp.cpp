/***************************************************************
 * Name:      simpleCalculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Zobayer ()
 * Created:   2016-05-23
 * Copyright: Zobayer ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "simpleCalculatorApp.h"

//(*AppHeaders
#include "simpleCalculatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(simpleCalculatorApp);

bool simpleCalculatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	simpleCalculatorFrame* Frame = new simpleCalculatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
