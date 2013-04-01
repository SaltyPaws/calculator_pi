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
    this->m_Overview->Fit();
    this->m_Overview->Layout();
     this->SetSize(wh);
    i_buffer=0;
    i_counter=0;
    item_counter=0;
    MemoryFull=false;
    /*this->OnToggle(true);
    this->OnToggle(false);*/
    //Max_Results=calculator_pi.GetMaxResults();

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
    if ((Text.StartsWith(_("clear"))) || (Text.StartsWith(_("Clear")))|| (Text.StartsWith(_("CLEAR")))){
        //wxMessageBox(_("User entered erroneous text:\n") + Text);
        m_listCtrl->ClearAll();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("HideHelp"))) || (Text.StartsWith(_("hidehelp")))|| (Text.StartsWith(_("HIDEHELP")))){
       // wxMessageBox(_("Hiding Help:\n") + Text);
        m_HelpButton->Show(false);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("ShowHelp"))) || (Text.StartsWith(_("showhelp")))|| (Text.StartsWith(_("SHOWHELP")))){
        //wxMessageBox(_("Hiding Help:\n") + Text);
        m_HelpButton->Show(true);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
        if ((Text.StartsWith(_("HideHistory"))) || (Text.StartsWith(_("hidehistory")))|| (Text.StartsWith(_("HIDEHISTORY")))){
       // wxMessageBox(_("Hiding Help:\n") + Text);
        m_Help->Show(false);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("ShowHistory"))) || (Text.StartsWith(_("showhistory")))|| (Text.StartsWith(_("SHOWHISTORY")))){
        //wxMessageBox(_("Hiding Help:\n") + Text);
        m_Help->Show(true);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("HideCalculate"))) || (Text.StartsWith(_("hidecalculate")))|| (Text.StartsWith(_("HIDECALCULATE")))){
       // wxMessageBox(_("Hiding Help:\n") + Text);
        Calculate->Show(false);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("ShowCalculate"))) || (Text.StartsWith(_("showcalculate")))|| (Text.StartsWith(_("SHOWCALCULATE")))){
        //wxMessageBox(_("Hiding Help:\n") + Text);
        Calculate->Show(true);
    	this->m_listCtrl->Fit();
        this->m_Overview->Layout();
        m_result->SetValue(_(""));
        error_check=true;
    }
    if ((Text.StartsWith(_("Help"))) || (Text.StartsWith(_("HELP")))|| (Text.StartsWith(_("help")))){
       // wxMessageBox(_("Hiding Help:\n") + Text);
        this->OnHelp (event);
        m_result->SetValue(_(""));
        error_check=true;
    }

    if ((Text.StartsWith(_("history"))) || (Text.StartsWith(_("History")))|| (Text.StartsWith(_("HISTORY")))){
        if(this->m_Help->GetValue()) {
            this->m_Help->SetValue(false);}
        else {
            this->m_Help->SetValue(true);}

        this->OnToggle(event);
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
        //wxLogMessage(mystring);
        if (!mystring.StartsWith(_("Error")))
            {
            //if (MemoryFull)
            //     m_listCtrl->DeleteItem(item_counter);

            itemIndex = m_listCtrl->InsertItem(item_counter, Text + wxT(" = ") + mystring); //want this for col. 1

            item_counter++;
            if (item_counter>Max_Results){
                item_counter=0;
                //m_listCtrl->ClearAll();
                }
            printf("Item counter:%d, Max results: %d, ItemIndex: %ld\n",item_counter,Max_Results,itemIndex);
            }
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

void Dlg::i_plus(int &counter_test){
    counter_test++;
    if (counter_test>40) counter_test=0;
}

void Dlg::i_min(int &counter_test){
    counter_test--;
    if (counter_test<0) counter_test=40;
}
