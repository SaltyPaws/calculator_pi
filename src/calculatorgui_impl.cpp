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

    number_of_parameters=9;
    number_of_formulas=3;
    Selected_Formula=1; //Default start formula

    testf[0].m_ShortDesc=_("Hull Speed (imperial)");
    testf[0].m_LongDesc=_("Hull speed, sometimes referred to as displacement speed, can be thought of the speed at which the wavelength of the boat's bow wave (in displacement mode) is equal to the boat length. As boat speed increases, the size of the bow wave increases, and therefore so does its wavelength. When hull speed is reached, a boat in pure displacement mode will appear trapped in a trough behind its very large bow wave.");
    testf[0].m_Result_Unit=_("Knots");
    testf[0].m_Formula=_("vhull=1.34*sqrt(LWL)");
    testf[0].m_Input_parameter[0]=_("LWL");
    testf[0].m_Input_unit[0]=_("feet");

    testf[1].m_ShortDesc=_("Hull Speed (metric)");
    testf[1].m_LongDesc=_("Hull speed, sometimes referred to as displacement speed, can be thought of the speed at which the wavelength of the boat's bow wave (in displacement mode) is equal to the boat length. As boat speed increases, the size of the bow wave increases, and therefore so does its wavelength. When hull speed is reached, a boat in pure displacement mode will appear trapped in a trough behind its very large bow wave.");
    testf[1].m_Result_Unit=_("Knots");
    testf[1].m_Formula=_("vhull=1.34*sqrt(LWL/0.3048)");
    testf[1].m_Input_parameter[0]=_("LWL");
    testf[1].m_Input_unit[0]=_("meter");

    testf[2].m_ShortDesc=_("Draft of vessel when heeled");
    testf[2].m_LongDesc=_("Draft of vessel when heeled");
    testf[2].m_Result_Unit=_("as Input units");
    testf[2].m_Formula=_("draft_heel=draft*cos(dtr*angle)");
    testf[2].m_Input_parameter[0]=_("draft");
    testf[2].m_Input_unit[0]=_("as Result Units");
    testf[2].m_Input_parameter[1]=_("angle");
    testf[2].m_Input_unit[1]=_("degree");

    testf[3].m_ShortDesc=_("test");
    testf[3].m_LongDesc=_("test 1");
    testf[3].m_Result_Unit=_("result_u");
    testf[3].m_Formula=_("draft_heel=draft*cos(dtr*angle)");
    testf[3].m_Input_parameter[0]=_("a");
    testf[3].m_Input_unit[0]=_("a_u");
    testf[3].m_Input_parameter[1]=_("b");
    testf[3].m_Input_unit[1]=_("b_u");
    testf[3].m_Input_parameter[2]=_("c");
    testf[3].m_Input_unit[2]=_("c_u");
    testf[3].m_Input_parameter[3]=_("d");
    testf[3].m_Input_unit[3]=_("d_u");
    testf[3].m_Input_parameter[4]=_("e");
    testf[3].m_Input_unit[4]=_("e_u");
    testf[3].m_Input_parameter[5]=_("f");
    testf[3].m_Input_unit[5]=_("f_u");
    testf[3].m_Input_parameter[6]=_("g");
    testf[3].m_Input_unit[6]=_("g_u");
    testf[3].m_Input_parameter[7]=_("h");
    testf[3].m_Input_unit[7]=_("h_u");
    testf[3].m_Input_parameter[8]=_("i");
    testf[3].m_Input_unit[8]=_("i_u");
    testf[3].m_Input_parameter[9]=_("j");
    testf[3].m_Input_unit[9]=_("j_u");

    for ( int count = 0; count <= number_of_formulas; count++)
	{
	 this->m_Function_Dropdown->Append(testf[count].m_ShortDesc);
	}

this->SelectItem();

}

void FunDlg::OnClose( wxCommandEvent& event ){
    this->Destroy();
}


void FunDlg::OnItemSelect( wxCommandEvent& event ){

    wxString Selected_Result=event.GetString();
    int n;
        for ( n = 0; n <= number_of_formulas; n++)
        {
            if(Selected_Result==testf[n].m_ShortDesc) break;
        }

    this->Selected_Formula=n;
    this->SelectItem();
}

void FunDlg::SelectItem(void){
    this->m_Function->SetLabel(testf[Selected_Formula].m_Formula);
    this->m_Description->SetLabel(testf[Selected_Formula].m_LongDesc);
    this->m_Output_Parameter_Unit->SetLabel(testf[Selected_Formula].m_Result_Unit);
    this->m_Output_Parameter->SetLabel(testf[Selected_Formula].m_Formula.BeforeFirst('='));

    if (!testf[Selected_Formula].m_Input_parameter[0].IsEmpty()){
        this->Parameter->SetLabel(testf[Selected_Formula].m_Input_parameter[0]);
        this->Units->SetLabel(testf[Selected_Formula].m_Input_unit[0]);}

    if (!testf[Selected_Formula].m_Input_parameter[1].IsEmpty()){
        this->Parameter1->SetLabel(testf[Selected_Formula].m_Input_parameter[1]);
        this->Units1->SetLabel(testf[Selected_Formula].m_Input_unit[1]);
        this->m_panel1->Show(true);
        } else this->m_panel1->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[2].IsEmpty()){
        this->Parameter2->SetLabel(testf[Selected_Formula].m_Input_parameter[2]);
        this->Units2->SetLabel(testf[Selected_Formula].m_Input_unit[2]);
        this->m_panel2->Show(true);
        } else this->m_panel2->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[3].IsEmpty()){
        this->Parameter3->SetLabel(testf[Selected_Formula].m_Input_parameter[3]);
        this->Units3->SetLabel(testf[Selected_Formula].m_Input_unit[3]);
        this->m_panel3->Show(true);
        } else this->m_panel3->Show(false);


    if (!testf[Selected_Formula].m_Input_parameter[4].IsEmpty()){
        this->Parameter4->SetLabel(testf[Selected_Formula].m_Input_parameter[4]);
        this->Units4->SetLabel(testf[Selected_Formula].m_Input_unit[4]);
        this->m_panel4->Show(true);
        } else this->m_panel4->Show(false);


    if (!testf[Selected_Formula].m_Input_parameter[5].IsEmpty()){
        this->Parameter5->SetLabel(testf[Selected_Formula].m_Input_parameter[5]);
        this->Units5->SetLabel(testf[Selected_Formula].m_Input_unit[5]);
        this->m_panel5->Show(true);
        } else this->m_panel5->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[6].IsEmpty()){
        this->Parameter6->SetLabel(testf[Selected_Formula].m_Input_parameter[6]);
        this->Units6->SetLabel(testf[Selected_Formula].m_Input_unit[6]);
        this->m_panel6->Show(true);
        } else this->m_panel6->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[7].IsEmpty()){
        this->Parameter7->SetLabel(testf[Selected_Formula].m_Input_parameter[7]);
        this->Units7->SetLabel(testf[Selected_Formula].m_Input_unit[7]);
        this->m_panel7->Show(true);
        } else this->m_panel7->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[8].IsEmpty()){
        this->Parameter8->SetLabel(testf[Selected_Formula].m_Input_parameter[8]);
        this->Units8->SetLabel(testf[Selected_Formula].m_Input_unit[8]);
        this->m_panel8->Show(true);
        } else this->m_panel8->Show(false);

    if (!testf[Selected_Formula].m_Input_parameter[9].IsEmpty()){
        this->Parameter9->SetLabel(testf[Selected_Formula].m_Input_parameter[9]);
        this->Units9->SetLabel(testf[Selected_Formula].m_Input_unit[9]);
        this->m_panel9->Show(true);
        } else this->m_panel9->Show(false);

    this->m_Description->Wrap(400); ///Width of description can be put in settings
    /*this->m_panel101->Fit();
    this->m_panel101->Layout();
    this->m_panel152->Fit();
    this->m_panel152->Layout();*/
    this->Fit();
}

wxString FunDlg::NotEmpty(wxString Dummy)
{
    if (Dummy.IsEmpty()) return wxT("0"); return Dummy;
}


void FunDlg::OnExtraCalculate( wxCommandEvent& event )
{

    wxString Result=testf[Selected_Formula].m_Formula.BeforeFirst('=');
    wxString Formula=testf[Selected_Formula].m_Formula.AfterFirst('=');
    if (!testf[Selected_Formula].m_Input_parameter[0].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[0],this->NotEmpty(this->Value->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[1].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[1],this->NotEmpty(this->Value1->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[2].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[2],this->NotEmpty(this->Value2->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[3].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[3],this->NotEmpty(this->Value3->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[4].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[4],this->NotEmpty(this->Value4->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[5].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[5],this->NotEmpty(this->Value5->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[6].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[6],this->NotEmpty(this->Value6->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[7].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[7],this->NotEmpty(this->Value7->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[8].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[8],this->NotEmpty(this->Value8->GetValue()),false);
    if (!testf[Selected_Formula].m_Input_parameter[9].IsEmpty()) Formula.Replace(testf[Selected_Formula].m_Input_parameter[9],this->NotEmpty(this->Value9->GetValue()),false);

    Plugin_Dialog->m_result->SetValue(Result.Append('=').Append(Formula));
    wxMessageBox(Formula);
    Plugin_Dialog->OnCalculate();
    this->m_Function_Result->SetValue(Plugin_Dialog->m_result->GetValue());
}

void FunDlg::OnFunctionSelect( wxCommandEvent& event )
{
   // m_pFunctiondialog->m_Function->SetValue(_("Function!!"));
    //m_pFunctiondialog->m_Description->SetValue(_("Desctiption!!"));
    //wxMessageBox(_("Function"));
    // Plugin_Dialog->OnFunctionCalc() ;
    int n=1;
    this->m_Function->SetLabel(testf[n].m_Formula);
    this->m_Description->SetLabel(testf[n].m_LongDesc);
    this->m_Description->SetLabel(testf[n].m_LongDesc);
    this->m_Output_Parameter_Unit->SetLabel(testf[n].m_Result_Unit);
    this->m_Output_Parameter->SetLabel(testf[n].m_Formula.BeforeFirst('='));
    this->Parameter->SetLabel(testf[n].m_Input_parameter[0]);
    this->Units->SetLabel(testf[n].m_Input_unit[0]);
    this->m_Description->Wrap(400); ///Width of description can be put in settings
    this->Fit();
}

void FunDlg::OnToggle( wxCommandEvent& event ){
    //wxMessageBox(_("toggle"));
    this->m_Description->Show(this->m_checkBox8->GetValue());
    this->Fit();
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




void Dlg::OnFunctionCalc( void )
{

        // Plugin_Dialog->OnFunctionCalc() ;
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
        m_pFunctiondialog->Plugin_Dialog = this;
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

void Dlg::set_Buttons(void)
{
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
