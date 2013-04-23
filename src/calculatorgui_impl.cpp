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

HlpDlg::HlpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : HlpDlgDef( parent, id, title, pos, size, style )
{
}

FunDlg::FunDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : FunDlgDef( parent, id, title, pos, size, style )
{

    testf.m_ShortDesc=_("Hull Speed (imperial)");
    testf.m_LongDesc=_("Hull speed, sometimes referred to as displacement speed, can be thought of the speed at which the wavelength of the boat's bow wave (in displacement mode) is equal to the boat length. As boat speed increases, the size of the bow wave increases, and therefore so does its wavelength. When hull speed is reached, a boat in pure displacement mode will appear trapped in a trough behind its very large bow wave.");
    testf.m_Result_Unit=_("Knots");
    testf.m_Formula=_("vhull=1.34*sqrt(LWL)");
    testf.m_Input_parameter[0]=_("LWL");
    testf.m_Input_unit[0]=_("feet");

}


Dlg::Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DlgDef( parent, id, title, pos, size, style )
{
    prs.parse("dtr=0.0174532925"); //define degree to radians conversion factor



    /*printf("This is what the Dialog got\n");
    printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
    printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
    printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
    printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
    printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
    printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");*/

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
    m_pHelpdialog=NULL;

}


void FunDlg::OnExtraCalculate( wxCommandEvent& event )
{

    wxMessageBox(_("Calculate"));
    // kut->OnFunctionCalc() ;
    kut->m_result->SetValue(_("Calculate"));
    // kut->OnHelp();
}

void FunDlg::OnFunctionSelect( wxCommandEvent& event )
{
   // m_pFunctiondialog->m_Function->SetValue(_("Function!!"));
    //m_pFunctiondialog->m_Description->SetValue(_("Desctiption!!"));
    //wxMessageBox(_("Function"));
    // kut->OnFunctionCalc() ;
    this->m_Function->SetLabel(testf.m_Formula);
    this->m_Description->SetLabel(testf.m_LongDesc);
    this->m_Description->SetLabel(testf.m_LongDesc);
    this->m_Output_Parameter_Unit->SetLabel(testf.m_Result_Unit);
    this->Parameter->SetLabel(testf.m_Input_parameter[0]);
    this->Units->SetLabel(testf.m_Input_unit[0]);
    this->m_Description->Wrap(400); ///Width of description can be put in settings
    /*this->m_panel101->Fit();
    this->m_panel101->Layout();
    this->m_panel152->Fit();
    this->m_panel152->Layout();*/
    this->Fit();


    // kut->OnHelp();
    }



void Dlg::OnFunctionCalc( void )
{
    //m_pFunctiondialog->m_staticText73->SetLabel(_("Dikke Piemel"));
        // kut->OnFunctionCalc() ;
}

void Dlg::OnHelp( wxCommandEvent& event ){
    OnHelp();}

void Dlg::OnHelp( void )
{
        HlpDlg *m_pHelpdialog = new HlpDlg(this);m_pHelpdialog->Show(true);
        m_pHelpdialog->HelpPanel->Fit();
        m_pHelpdialog->m_textCtrl3->Fit();
        m_pHelpdialog->m_textCtrl3->Layout();
}

void Dlg::OnFunction( void )
{
        FunDlg *m_pFunctiondialog = new FunDlg(this);m_pFunctiondialog->Show(true);
        m_pFunctiondialog->kut = this;
//m_staticText27->SetValue(_("dIKKERE PENIS"));



 /*       m_pHelpdialog->HelpPanel->Fit();
        m_pHelpdialog->m_textCtrl3->Fit();
        m_pHelpdialog->m_textCtrl3->Layout();*/
}

void Dlg::set_History(void)
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

void Dlg::OnTest(wxCommandEvent& event){
   wxMessageBox(_("Test"));
}

void Dlg::OnTest(wxMouseEvent& event){
   wxMessageBox(_("Mouse"));
}

void Dlg::OnTest(wxListEvent& event){
   wxMessageBox(_("List"));
}

void Dlg::OnItem(wxListEvent& event){

   //wxMessageBox(_("Test"));

   long item = -1;
    wxString ItemText;
    for ( ;; )
    {
        item = this->m_listCtrl->GetNextItem(item,
                                     wxLIST_NEXT_ALL,
                                     wxLIST_STATE_SELECTED);
        if ( item == -1 )
            break;

        ItemText=this->m_listCtrl->GetItemText(item);
        ItemText=ItemText.AfterLast('=');
        ItemText=ItemText.AfterLast(' ');
        m_result->AppendText(ItemText);
    }
}

void Dlg::OnToggle( wxCommandEvent& event )
{
        this->set_History();
}

void Dlg::set_Buttons(void){
        m_HelpButton->Show(m_bshowhelpB);
        m_Help->Show(m_bshowhistoryB);
        Calculate->Show(m_bCalculateB);
        this->m_Overview->Fit();
        this->m_Overview->Layout();
        this->m_Help->SetValue(m_bshowhistory);
        this->set_History();

}
void Dlg::OnCalculate( wxCommandEvent& event )
{
    OnCalculate();
}
void Dlg::OnCalculate( void )
{

    char* test;
    wxString Text = m_result->GetValue();

    buffer[i_buffer]=Text; //store input
    i_plus(i_buffer);
    i_counter=i_buffer;

    bool error_check=false;
    if ((Text.StartsWith(_("Error"))) || (Text.StartsWith(_("Ans")))){
        error_check=true;
    }


    if ((Text.StartsWith(_("clear"))) || (Text.StartsWith(_("Clear")))|| (Text.StartsWith(_("CLEAR")))){ //clear old results
        m_listCtrl->ClearAll();
        error_check=true;
    }
    if ((Text.StartsWith(_("HideHelp"))) || (Text.StartsWith(_("hidehelp")))|| (Text.StartsWith(_("HIDEHELP"))) ||(Text.StartsWith(_("ShowHelp"))) || (Text.StartsWith(_("showhelp")))|| (Text.StartsWith(_("SHOWHELP"))) ){
        m_bshowhelpB=(!m_bshowhelpB);
        this->set_Buttons();
        error_check=true;
    }

    if ((Text.StartsWith(_("HideHistory"))) || (Text.StartsWith(_("hidehistory")))|| (Text.StartsWith(_("HIDEHISTORY")))||(Text.StartsWith(_("ShowHistory"))) || (Text.StartsWith(_("showhistory")))|| (Text.StartsWith(_("SHOWHISTORY")))){
        m_bshowhistoryB=(!m_bshowhistoryB);
        this->set_Buttons();
        error_check=true;
    }

    if ((Text.StartsWith(_("HideCalculate"))) || (Text.StartsWith(_("hidecalculate")))|| (Text.StartsWith(_("HIDECALCULATE"))) || (Text.StartsWith(_("ShowCalculate"))) || (Text.StartsWith(_("showcalculate")))|| (Text.StartsWith(_("SHOWCALCULATE")))){
        m_bCalculateB=(!m_bCalculateB);
        this->set_Buttons();
        error_check=true;
    }

    if ((Text.StartsWith(_("Help"))) || (Text.StartsWith(_("HELP")))|| (Text.StartsWith(_("help")))){
        this->OnHelp ();
        error_check=true;
    }

    if ((Text.StartsWith(_("Function"))) || (Text.StartsWith(_("function")))|| (Text.StartsWith(_("FUNCTION")))){
        this->OnFunction ();
        error_check=true;
    }

    if ((Text.StartsWith(_("history"))) || (Text.StartsWith(_("History")))|| (Text.StartsWith(_("HISTORY")))){
        m_bshowhistory=(!m_bshowhistory);
        this->m_Help->SetValue(m_bshowhistory);
        this->set_History();

        error_check=true;
    }

if (error_check)
     m_result->SetValue(_(""));
    if (!error_check)
        {
        test = prs.parse((const char*)Text.mb_str());
        //printf("\t%s\n", test);
        wxString mystring = wxString::FromUTF8(test);
        if (m_blogresults) wxLogMessage(_("Calculator INPUT:") + Text + _(" Calculator output:") + mystring);
        //wxString Foobar;

        buffer[i_buffer]=mystring; //store input
        i_plus(i_buffer);
        i_counter=i_buffer;

        if((!this->m_Help->GetValue()) || (mystring.StartsWith(_("Error")) )) //print result in messagebox if not history box or error
            m_result->SetValue(mystring.c_str());
        else
            m_result->SetValue(_(""));
        //m_listCtrl->SetItem(itemIndex, item_counter, "hallo"); //want this for col. 2
        Text.Right(Text.Length()-3);
        //wxLogMessage(mystring);
        //mhelp  capture hidden
        //false  false  --dont capture
        /*printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
        printf("this->m_Help->GetValue(): %s\n",(this->m_Help->GetValue())?"true":"false");*/


        if (!mystring.StartsWith(_("Error")) )
            {
            if ((this->m_Help->GetValue()) || (m_bcapturehidden)){
            //     m_listCtrl->DeleteItem(item_counter);

            itemIndex = m_listCtrl->InsertItem(item_counter, Text + wxT(" = ") + mystring); //want this for col. 1
            m_listCtrl->EnsureVisible(itemIndex);

            item_counter++;
            if (item_counter>Max_Results){
                item_counter=0;
                m_listCtrl->ClearAll();
                }
            //printf("Item counter:%d, Max results: %d, ItemIndex: %ld\n",item_counter,Max_Results,itemIndex);
            }
        //event.Skip();
        }}
}

void Dlg::OnKey (wxKeyEvent& event){
 wxChar uc = event.GetUnicodeKey();

// It's a "normal" character. Notice that this includes
// control characters in 1..31 range, e.g. WXK_RETURN or
// WXK_BACK, so check for them explicitly.
    if ( ((uc >= 32) && (uc<=127))  )
        m_result->AppendText(uc);
    else if ( uc == 13 )
        OnCalculate();
    else if ( uc == 8 ){
    wxString Text = m_result->GetValue();
    m_result->SetValue(Text.Left(Text.Len()-1 ));
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
