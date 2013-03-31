/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   SaltyPaws
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Brazil BrokeTail                                *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "calculatorgui_impl.h"

CfgDlg::CfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : CfgDlgDef( parent, id, title, pos, size, style )
{
}


Dlg::Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DlgDef( parent, id, title, pos, size, style )
{
    prs.parse("dtr=0.0174532925"); //define degree to radians conversion factor
    this->m_listCtrl->Show(false);
    this->m_Overview->Layout();
    this->Layout();
    this->Fit();
    i_buffer=0;
    i_counter=0;
    item_counter=0;

}
void Dlg::OnHelp( wxCommandEvent& event )
{
    wxMessageBox(_("Use up and down keys, while cursor is in input box, to recall previous input and results.\nExamples of expression that work in the calculator are: (comments are in brackets, some results depend on other example calculations):\n=========\nHull speed:\n    LWL=48\t\t\t\t\t(water line lenght in feet)\n    vhull=1.34*LWL^(1/2)\t(hull speed in knots)\n\nConversions:\n    ftm=0.3048\t\t\t\t(feet to meters)\n    km_to_nm=0.539957\t(Kilometers to nautical Mile)\n    ftm*LWL\t\t\t\t(waterline length in meters)\n\nDistance to horizon\n    R=6378.1*1000\t\t\t(Radius of the earth in m)\n    H=2.5\t\t\t\t\t(Height of the eye above sea-level in m)\n    d = R * acos(R/(R + h))\t(Distance to horizon in m)   \n    ans*km_to_nm\t\t\t(Distance to horizon in nm)\n\nDistance to lighthouse\n    H1=200\t\t\t\t\t(height of lighthouse in m)\n    d1 = R*acos(R/(R + H1))(Distance to horizon in m)\n    distance=d1+d\t\t\t(visibility range of lighthouse in m)\n\nOperators:\n          & | << >> \n          = <> < > <= >=\n          + -\n          * / % ||\n          ^ (NB use ^(1/2) for square root)\n          ! (Factorial)\n \nFunctions:\n          Abs, Exp, Sign, Sqrt, Log, Log10\n          Sin, Cos, Tan, ASin, ACos, Atan (default entry is in radians use e.g. sin(dtr*90) to calculate in degree)\n          Factorial\n \nVariables:\n          Pi, e\n\t  dtr is the conversion factor from degrees to radians\n\t  Ans is the result of the previous calulation\t\t\n          you can define your own variables (e.g. myvariable=10/8*cos(dtr*90) or yourvariable=Ans)"));

}
void Dlg::OnToggle( wxCommandEvent& event )
{
    if(this->m_Help->GetValue())
    {
        //Capture dialog position
        xy=this->GetPosition();
        //Capture dialog size
        wh=this->GetSize();
        wh.y=-1; //Set default dialog height
    	this->m_listCtrl->Show(true);
    	this->m_listCtrl->Show(true);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        this->Fit();
        this->Layout();
    }
    else
    {
    	this->m_listCtrl->Show(false);
    	this->m_listCtrl->Show(false);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        this->Fit();
        this->Layout();
        this->SetPosition(xy);
        //Capture dialog size
        this->SetSize(wh);
    }
    wxMilliSleep(50);
}


void Dlg::OnCalculate( wxCommandEvent& event )
{
    //this->m_result->SetDefaultStyle(wxTextAttr(*wxBLUE));
    //m_result->SetNewStyle(wxTextAttr(*wxRED));
    //m_result->AppendText("Red text\n");


    char* test;
    wxString Text = m_result->GetValue();

    buffer[i_buffer]=Text; //store input
    i_plus(i_buffer);
    i_counter=i_buffer;

    bool error_check=false;
    if ((Text.StartsWith(_("Error"))) || (Text.StartsWith(_("Ans")))){
        //wxMessageBox(_("User entered erroneous text:\n") + Text);
        m_result->SetValue(_(""));
        error_check=true;
    }
    if (!error_check)
        {
        test = prs.parse((const char*)Text.mb_str());
        //printf("\t%s\n", test);
        wxString mystring = wxString::FromUTF8(test);
        wxLogMessage(_("Calculator output:") + mystring);
        //wxString Foobar;

        buffer[i_buffer]=mystring; //store input
        i_plus(i_buffer);
        i_counter=i_buffer;

        m_result->SetValue(mystring.c_str());
        //m_listCtrl->SetItem(itemIndex, item_counter, "hallo"); //want this for col. 2
        Text.Right(Text.Length()-3);
        //wxLogMessage(_("test") + Text.Length());
        //wxLogMessage(Text.Length());
        //mystring.replace(_("Ans"),_(""));
        //wxLogMessage(mystring);
        if (!mystring.StartsWith(_("Error"))) {
        itemIndex = m_listCtrl->InsertItem(item_counter, Text + wxT(" = ") + mystring); //want this for col. 1
        item_counter++;}
        //event.Skip();
        }
}

void Dlg::key_shortcut(wxKeyEvent& event) {
    // of course, it doesn't have to be the control key. You can use others:
    // http://docs.wxwidgets.org/stable/wx_wxkeyevent.html
   // if(event.GetModifiers() == wxMOD_CONTROL) {
        switch(event.GetKeyCode()) {
            case WXK_DOWN: // can return the upper ASCII value of a key
                // do whatever you like for a Ctrl+G event here!
                //wxMessageBox(_("down") );
                down();
                //OnCursor();
                break;
            case WXK_UP: // we also have special keycodes for non-ascii values.
                // get a full list of special keycodes here:
                // http://docs.wxwidgets.org/stable/wx_keycodes.html
                //wxMessageBox(_("up") );
                up();

                break;
            default: // do nothing

                break;
      //  }
   }
   event.Skip();
}

void Dlg::up()
{
    i_plus(i_counter);
    if (buffer[i_counter].Len()>1) {
        m_result->SetValue(buffer[i_counter].c_str());
                        //wxMessageBox(_("Not Empty") );
    }
    else{
        i_min(i_counter);
        //wxMessageBox(_("Empty") );

    }

}

void Dlg::down()
{
    i_min(i_counter);
    if (buffer[i_counter].Len()>1) {
        m_result->SetValue(buffer[i_counter].c_str());
                        //wxMessageBox(_("Not Empty") );
    }
    else{
        i_plus(i_counter);
       // wxMessageBox(_("Empty") );

    }

}
/*
void Dlg::down()
{
    //printf("Down");
    int count_this=0;
    do {
    i_min(i_counter);
    count_this++;

    } while ( buffer[i_counter].IsEmpty() || count_this>40 );

    if (buffer[i_counter].Len() >1) {
        m_result->SetValue(buffer[i_counter].c_str());
                                wxMessageBox(_("Not Empty") );
    }
    else{
        i_plus(i_counter);
                wxMessageBox(_("Empty") );
    }
}*/
/*
void Dlg::i_plus(bool buffer_test){
 if (buffer_test){
    i_buffer++;
    if (i_buffer>40) i_counter=0;
 }
 else
    i_counter++;
    if (i_counter>40) i_counter=0;
}

void Dlg::i_min(void){
    i_counter--;
    if (i_counter<0) i_counter=40;
}*/

void Dlg::i_plus(int &counter_test){
    counter_test++;
    if (counter_test>40) counter_test=0;
}

void Dlg::i_min(int &counter_test){
    counter_test--;
    if (counter_test<0) counter_test=40;
}
