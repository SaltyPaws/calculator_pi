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
    this->LoadCategories();
    this->LoadFunctions(wxT("All"),wxT("All"));
}

void FunDlg::LoadFunctions(wxString Category, wxString Unit)
{
    //Clear Pulldown
    this->m_Function_Dropdown->Clear();
    //Load functions into pulldown
    for ( unsigned int count = 0; count < testf.m_Formula.GetCount() ; count++)
	{
        if (Category.IsSameAs(testf.m_Category[count], false) || Category.IsSameAs(wxT("all"), false)   ) this->m_Function_Dropdown->Append(testf.m_ShortDesc[count]);
	}
    this->m_Function_Dropdown->SetSelection(0);
    //Load default function in the menu
    this->OnItemSelect();
}

void FunDlg::LoadCategories(void)
{
    wxArrayString Categories;
    //Clear Pulldown
    this->m_Function_Categories->Clear();
    this->m_Function_Categories->Append(_("All"));
    //Cycle through functions
    for ( unsigned int count = 0; count < testf.m_Formula.GetCount() ; count++)
	{
        if (Categories.Index(testf.m_Category[count], false, false)==wxNOT_FOUND)
        {
            //Add Category to Wxarraystring
            Categories.Add(testf.m_Category[count]);
            //Add category to pulldown
            this->m_Function_Categories->Append(testf.m_Category[count]);
            //printf("Just added: %s\n",(const char*) testf.m_Category[count].mb_str() );
        }
	}
	this->m_Function_Categories->SetSelection(0);
}

void FunDlg::OnCategorySelect( wxCommandEvent& event )
{
    this->LoadFunctions(event.GetString(),wxT("All"));
}

void FunDlg::OnClose( wxCommandEvent& event )
{
    this->Destroy();
}

void FunDlg::OnItemSelect( wxCommandEvent& event )
{
    this->OnItemSelect();
}

void FunDlg::OnItemSelect(void)
    {
    wxString Selected_Result=	this->m_Function_Dropdown->GetString( this->m_Function_Dropdown->GetCurrentSelection()); // Return selected formula
    unsigned int n;
    for ( n = 0; n < testf.m_Formula.GetCount() ; n++)
    {
        if(Selected_Result==testf.m_ShortDesc[n]) break;//find out number of formula
    }
    this->testf.Selected_Formula=n;
    this->m_Function->SetLabel(testf.m_Formula[testf.Selected_Formula]);
    this->m_Description->SetLabel(testf.m_LongDesc[testf.Selected_Formula]);
    this->m_Output_Parameter->SetLabel(testf.m_Formula[testf.Selected_Formula].BeforeFirst('='));
    PopulatePuldown(testf.m_Result_Unit[testf.Selected_Formula],this->m_Output_Parameter_UnitC, m_panel9);//Populate output units. Needs to be expanded for multiple. note m_panel 9 needs to be updated.
//Multiple return values update

    this->Parameter->SetLabel(testf.m_Input_parameter[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit[testf.Selected_Formula],this->Units, m_panel9);

    this->Parameter1->SetLabel(testf.m_Input_parameter1[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit1[testf.Selected_Formula],this->Units1, m_panel1);

    this->Parameter2->SetLabel(testf.m_Input_parameter2[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit2[testf.Selected_Formula],this->Units2, m_panel2);

    this->Parameter3->SetLabel(testf.m_Input_parameter3[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit3[testf.Selected_Formula],this->Units3, m_panel3);

    this->Parameter4->SetLabel(testf.m_Input_parameter4[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit4[testf.Selected_Formula],this->Units4, m_panel4);

    this->Parameter5->SetLabel(testf.m_Input_parameter5[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit5[testf.Selected_Formula],this->Units5, m_panel5);

    this->Parameter6->SetLabel(testf.m_Input_parameter6[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit6[testf.Selected_Formula],this->Units6, m_panel6);

    this->Parameter7->SetLabel(testf.m_Input_parameter7[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit7[testf.Selected_Formula],this->Units7, m_panel7);

    this->Parameter8->SetLabel(testf.m_Input_parameter8[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit8[testf.Selected_Formula],this->Units8, m_panel8);

    this->Parameter9->SetLabel(testf.m_Input_parameter9[testf.Selected_Formula]);
    PopulatePuldown(testf.m_Input_unit9[testf.Selected_Formula],this->Units9, m_panel9);

    this->m_Function->Wrap(400); ///Width of description can be put in settings
    this->m_Description->Wrap(400); ///Width of description can be put in settings
    this->Fit();
    this->m_Function_Result->SetValue(_(""));
    }

    void FunDlg::PopulatePuldown(wxString& Input_Units, wxChoice* Pulldown, wxPanel *Panel)
    {
        if (Input_Units.IsEmpty())
            {
            Panel->Show(false);
            }
        else
            {
            //Clear Pulldown
            Pulldown->Clear();

            //Show panel
            Panel->Show(true);
            //Determine output units
            int unit_index=this->Units_conv.m_Unit.Index(Input_Units, false, false);
            if (unit_index==wxNOT_FOUND)
                {
                //Unit not found
              //  printf("Cannot find unit: %s\n",(const char*) Input_Units.mb_str() );
                Pulldown->Append(Input_Units);
                }
            else
                {
                //unit found
               // printf("Found unit: %s",(const char*) Input_Units.mb_str() );
               // printf(" of category: %s\n",(const char*) this->Units_conv.m_Unit_category[unit_index].mb_str() );

                for ( unsigned int count = 0; count < this->Units_conv.m_Unit.GetCount() ; count++)
                    {
                    if (Units_conv.m_Unit_category[unit_index].IsSameAs(this->Units_conv.m_Unit_category[count], false) )
                        {
                           // printf("Other units found in category: %s\n",(const char*) Units_conv.m_Unit[count].mb_str() );
                            if (Units_conv.m_Display[count].IsSameAs(wxT("TRUE"), false) ) Pulldown->Append(Units_conv.m_Unit[count]);
                        }
                    }
                }
            Pulldown->SetSelection(0);
            }
    }

wxString FunDlg::Unit_Conversion( wxString Output_Unit,wxString Input_Unit, wxString Var)
{
//This function returns the factor to convert from input to output unit
#ifdef DEBUG
printf("\n\n------------------------------------------------------\n");
printf("Input_Unit: %s\n",(const char*) Input_Unit.mb_str() );
printf("Output_Unit: %s\n",(const char*) Output_Unit.mb_str() );
printf("Var: %s\n",(const char*) Var.mb_str() );
#endif // DEBUG

//If Var is empty, return 0, nothing else to do
if (Var.IsEmpty()) return wxT("0");

if (Input_Unit.CmpNoCase(Output_Unit)!=0) //Convert if input unit is not output unit
    {
     //find input unit factor
     int to_base = this->Units_conv.m_Unit.Index(Input_Unit, false);
     int to_output = this->Units_conv.m_Unit.Index(Output_Unit, false);
     if (to_base==wxNOT_FOUND || to_output==wxNOT_FOUND)
        {
         #ifdef DEBUG
         printf("not found unit, end conversion\n");
         #endif // DEBUG
         return( Var );
        }
    else
        {
        #ifdef DEBUG
        printf("Conversion to base: %s\n",(const char*) this->Units_conv.m_Conversion[to_base].mb_str() );
        printf("Conversion to output: 1/%s\n",(const char*) this->Units_conv.m_Conversion[to_output].mb_str() );
        #endif // DEBUG
            //Check if to_base contains VAR, if yes to_base= replace VAR with Var else to_base=Var*to_base
            if (Units_conv.m_Conversion[to_base].Contains(wxT("VAR")))
                {
                Input_Unit = wxT("(")+Units_conv.m_Conversion[to_base].BeforeFirst('=')+wxT(")");
                Input_Unit.Replace(wxT("VAR"), Var);
                #ifdef DEBUG
                printf("Replace mode.... Input_Unit: -->%s<--\n",(const char*) Input_Unit.mb_str() );
                #endif // DEBUG
                }
            else
            {
                Input_Unit =wxT("(")+Var+wxT("*")+Units_conv.m_Conversion[to_base]+wxT(")");
                #ifdef DEBUG
                printf("Normal Mode: Input_Unit: -->%s<--\n",(const char*) Input_Unit.mb_str() );
                #endif // DEBUG
            }


            //Check if to_output contains VAR, if yes, replace VAR with to_base string, if not devide by to_output
            if (Units_conv.m_Conversion[to_output].Contains(wxT("VAR")))
                {
                Output_Unit = Units_conv.m_Conversion[to_output].AfterLast('=');
                Output_Unit.Replace(wxT("VAR"), Input_Unit);
                #ifdef DEBUG
                printf("Replace mode.... Output_Unit: -->%s<--\n",(const char*) Input_Unit.mb_str() );
                {wxString returnf=wxT("(")+Output_Unit+wxT(")");
                printf("Returning: -->%s<--\n",(const char*) returnf.mb_str() );}
                #endif
                return (wxT("(")+Output_Unit+wxT(")"));
                }
            else
            {
                Output_Unit =Input_Unit+wxT("/")+Units_conv.m_Conversion[to_output];
                #ifdef DEBUG
                printf("Normal Mode: Input_Unit: -->%s<--\n",(const char*) Output_Unit.mb_str() );
                {wxString returnf=wxT("(")+Output_Unit+wxT(")");
                printf("Returning: -->%s<--\n",(const char*) returnf.mb_str() );}
                #endif
                return (wxT("(")+Output_Unit+wxT(")"));
            }
        }
    }
else
    {
    #ifdef DEBUG
    printf("Nothing to do, return input variable\n");
    #endif
    return (Var);
    }
}

void FunDlg::OnExtraCalculate( wxCommandEvent& event )
{
    //Calculate the result of the function
    /*
    To implement for multiple return values
    1)find out if there are multiple return values, and if so, how many (e.g. via number of output units)
    2)extract substring for each function
    3)loop over routine below, with exeption, that result has to end up in the right result box


    */


    wxString Result=testf.m_Formula[testf.Selected_Formula].BeforeFirst('=');
    wxString Formula=testf.m_Formula[testf.Selected_Formula].AfterFirst('=');
    /*
    if (!testf.m_Input_parameter[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter[testf.Selected_Formula],this->NotEmpty(this->Value->GetValue()),true);
    if (!testf.m_Input_parameter1[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter1[testf.Selected_Formula],this->NotEmpty(this->Value1->GetValue()),true);
    if (!testf.m_Input_parameter2[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter2[testf.Selected_Formula],this->NotEmpty(this->Value2->GetValue()),true);
    if (!testf.m_Input_parameter3[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter3[testf.Selected_Formula],this->NotEmpty(this->Value3->GetValue()),true);
    if (!testf.m_Input_parameter4[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter4[testf.Selected_Formula],this->NotEmpty(this->Value4->GetValue()),true);
    if (!testf.m_Input_parameter5[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter5[testf.Selected_Formula],this->NotEmpty(this->Value5->GetValue()),true);
    if (!testf.m_Input_parameter6[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter6[testf.Selected_Formula],this->NotEmpty(this->Value6->GetValue()),true);
    if (!testf.m_Input_parameter7[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter7[testf.Selected_Formula],this->NotEmpty(this->Value7->GetValue()),true);
    if (!testf.m_Input_parameter8[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter8[testf.Selected_Formula],this->NotEmpty(this->Value8->GetValue()),true);
    if (!testf.m_Input_parameter9[testf.Selected_Formula].IsEmpty()) Formula.Replace(testf.m_Input_parameter9[testf.Selected_Formula],this->NotEmpty(this->Value9->GetValue()),true);
    */
    //Add input parameters converted for unit
    if (!testf.m_Input_parameter [testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit[testf.Selected_Formula],this->Units->GetString( this->Units->GetCurrentSelection()),this->Value->GetValue()),true);
    if (!testf.m_Input_parameter1[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter1[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit1[testf.Selected_Formula],this->Units1->GetString( this->Units1->GetCurrentSelection()),this->Value1->GetValue()),true);
    if (!testf.m_Input_parameter2[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter2[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit2[testf.Selected_Formula],this->Units2->GetString( this->Units2->GetCurrentSelection()),this->Value2->GetValue()),true);
    if (!testf.m_Input_parameter3[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter3[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit3[testf.Selected_Formula],this->Units3->GetString( this->Units3->GetCurrentSelection()),this->Value3->GetValue()),true);
    if (!testf.m_Input_parameter4[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter4[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit4[testf.Selected_Formula],this->Units4->GetString( this->Units4->GetCurrentSelection()),this->Value4->GetValue()),true);
    if (!testf.m_Input_parameter5[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter5[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit5[testf.Selected_Formula],this->Units5->GetString( this->Units5->GetCurrentSelection()),this->Value5->GetValue()),true);
    if (!testf.m_Input_parameter6[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter6[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit6[testf.Selected_Formula],this->Units6->GetString( this->Units6->GetCurrentSelection()),this->Value6->GetValue()),true);
    if (!testf.m_Input_parameter7[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter7[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit7[testf.Selected_Formula],this->Units7->GetString( this->Units7->GetCurrentSelection()),this->Value7->GetValue()),true);
    if (!testf.m_Input_parameter8[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter8[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit8[testf.Selected_Formula],this->Units8->GetString( this->Units8->GetCurrentSelection()),this->Value8->GetValue()),true);
    if (!testf.m_Input_parameter9[testf.Selected_Formula].IsEmpty())  Formula.Replace(testf.m_Input_parameter9[testf.Selected_Formula],Unit_Conversion(testf.m_Input_unit9[testf.Selected_Formula],this->Units9->GetString( this->Units9->GetCurrentSelection()),this->Value9->GetValue()),true);

    //Convert formula to desired output unit
    Formula=Unit_Conversion(this->m_Output_Parameter_UnitC->GetString( this->m_Output_Parameter_UnitC->GetCurrentSelection()),testf.m_Result_Unit[testf.Selected_Formula],Formula);

    Plugin_Dialog->m_result->SetValue(Result.Append('=').Append(Formula));
    //wxMessageBox(Formula);
    //Plugin_Dialog->OnCalculate();
    this->m_Function_Result->SetValue(Plugin_Dialog->OnCalculate());
}

void FunDlg::OnToggle( wxCommandEvent& event ){
    //wxMessageBox(_("toggle"));
    this->m_Description->Show(this->m_checkBox8->GetValue());
    this->Fit();
}

Dlg::Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DlgDef( parent, id, title, pos, size, style )
{

    MuParser.ClearConst();
    MuParser.DefineConst("pi", 3.141592653589793238462643);
    MuParser.DefineConst("e", 2.718281828459045235360287);
    MuParser.DefineConst("dtr",0.0174532925199433) ;
    MuParser.SetVarFactory(AddVariable,&MuParser);

    this->m_listCtrl->Show(false);

    this->m_Overview->Layout();
    this->Layout();
    this->Fit();
    this->m_Overview->Fit();
    this->m_Overview->Layout();
    this->SetSize(wh);
    i_counter=0;
    item_counter=0;
    MemoryFull=false;
    m_pHelpdialog=NULL;
    m_pFunctiondialog=NULL; //So we can check that the Function Function dialog has been opened.
}

void Dlg::OnFunctionCalc( void )
{

        // Plugin_Dialog->OnFunctionCalc() ;
}

void Dlg::OnHelp( wxCommandEvent& event ){
    OnHelp();}

void Dlg::OnHelp( void )
{
    if (NULL==m_pHelpdialog)
    {
        //HlpDlg *m_pHelpdialog = new HlpDlg(this);m_pHelpdialog->Show(true);
        m_pHelpdialog = new HlpDlg(this);
        m_pHelpdialog->HelpPanel->Fit();
        m_pHelpdialog->m_textCtrl3->Fit();
        m_pHelpdialog->m_textCtrl3->Layout();
    }
    m_pHelpdialog->Show(!m_pHelpdialog->IsShown());

}

void Dlg::OnFunction( wxCommandEvent& event )
{
    OnFunction();
}

void Dlg::OnFunction( void )
{
        if(NULL == m_pFunctiondialog){
            //FunDlg *m_pFunctiondialog = new FunDlg(this);
            m_pFunctiondialog = new FunDlg(this);
            m_pFunctiondialog->Plugin_Dialog = this;
        }
        m_pFunctiondialog->Show(!m_pFunctiondialog->IsShown());
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

#ifdef DEBUG
void Dlg::OnTest(wxCommandEvent& event){
   wxMessageBox(_("Test"));
}

void Dlg::OnTest(wxMouseEvent& event){
   wxMessageBox(_("Mouse"));
}

void Dlg::OnTest(wxListEvent& event){
   wxMessageBox(_("List"));
}
#endif // DEBUG
void Dlg::OnItem(wxListEvent& event){
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
        ItemText=ItemText.BeforeFirst('=');
        //ItemText=ItemText.BeforeFirst(' ');
        m_result->AppendText(ItemText);
    }
}

void Dlg::OnToggle( wxCommandEvent& event )
{
        this->set_History();
}

void Dlg::set_Buttons(void)
{
    this->m_HelpButton->Show(m_bshowhelpB);
    this->m_Help->Show(m_bshowhistoryB);
    this->Calculate->Show(m_bCalculateB);
    this->m_Function->Show(m_bshowFunction);
    this->m_HistoryPulldown->Show(m_HistoryPulldown);
    this->m_Overview->Fit();
    this->m_Overview->Layout();
    this->m_Help->SetValue(m_bshowhistory);

    this->set_History();
}

void Dlg::OnCalculate( wxCommandEvent& event )
{
    OnCalculate();
}

wxString Dlg::OnCalculate( void )
{
    //char* test;
    wxString Text = m_result->GetValue();

    bool error_check=false;
    if ((Text.StartsWith(_("Error"))) ){
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

    if ((Text.StartsWith(_("HideFunction"))) || (Text.StartsWith(_("hidefunction")))|| (Text.StartsWith(_("HIDEFUNCTION"))) || (Text.StartsWith(_("showfunction")))|| (Text.StartsWith(_("ShowFunction")))|| (Text.StartsWith(_("SHOWFUNCTION")))){
        m_bshowFunction=(!m_bshowFunction);
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
        {
        m_result->SetValue(_(""));
        return wxT("");
        }
    else
        {
        wxString mystring;
        #ifdef DEBUG
        printf("Input: %s\n",(const char*) Text.mb_str() );
        #endif // DEBUG

        MuParser.SetExpr(static_cast<const char*>(Text.mb_str())); //Typecast to mu::stringtype
        double Muparser_result=0;
        try
        {
            Muparser_result = MuParser.Eval();//Get the result
            mystring=wxT("ans=")+double2wxT(Muparser_result);//set ans string (borrow the mystring);
            mystring.Replace(wxT(","),wxT("."),TRUE);
           // MuParser.SetExpr((mu::string_type) mystring.mb_str()); //This works in linux, but causes compiler error in windows
            MuParser.SetExpr(static_cast<const char*>(mystring.mb_str())); //Store the answer in ans
            mystring=Report_Value(Muparser_result,m_iCalc_Reporting);//Format result as per setting.
            Muparser_result = MuParser.Eval();//Evaluate for ans

        }
        //catch(...)
        catch(mu::Parser::exception_type &e)
        {
            {
            mu::string_type sLine;
            sLine=e.GetMsg();
            wxString tempstring(sLine.c_str(), wxConvUTF8);
            mystring=wxT("Error: ")+tempstring;
            }
            error_check=true;
            //printf("Message: %s\n",(const char*) mystring.mb_str() );
        }
        if (m_blogresults) wxLogMessage(_("Calculator INPUT:") + Text + _(" Calculator output:") + mystring); //log into OpenCPN

        if((!this->m_Help->GetValue()) || (error_check)) //print result in messagebox if not history box or error
            m_result->SetValue(mystring.c_str());
        else
            m_result->SetValue(_(""));

        Text.Right(Text.Length()-3);

        if (!error_check )
            {
            if ((this->m_Help->GetValue())) //if ((this->m_Help->GetValue()) || (m_bcapturehidden))
                {
                if ((int)(this->m_HistoryPulldown->GetCount())<(int)Max_Results){//Items in pulldown memory less than X
                    HistoryPulldownitemIndex=m_HistoryPulldown->Append(Text + wxT(" = ") + mystring); //Append
                }
                else
                {
                    HistoryPulldownitemIndex++;
                    if (HistoryPulldownitemIndex>=Max_Results) HistoryPulldownitemIndex=0;
                    this->m_HistoryPulldown->SetString(HistoryPulldownitemIndex,Text + wxT(" = ") + mystring);//Overwrite previous value
                }

                m_HistoryPulldown->SetSelection(HistoryPulldownitemIndex); //Activate lastest result in pulldown

                item_counter++;
                if (this->m_listCtrl->GetItemCount()<Max_Results*5){//Items in pulldown memory less than 5*max results
                //do nothing
                }
                else{
                    if (item_counter>=Max_Results*5) item_counter=0;
                    m_listCtrl->DeleteItem(item_counter);
                }
                itemIndex = m_listCtrl->InsertItem(item_counter, Text + wxT(" = ") + mystring); //Here input+result are stored in the memory box

                //printf("Total items in m_listctr %ld\n",m_listCtrl->GetItemCount());
                m_listCtrl->EnsureVisible(itemIndex); //make sure latest result is visible in history box
                //printf("Item counter:%d, Max results: %d, ItemIndex: %ld\n",HistoryPulldownitemIndex,Max_Results,itemIndex);
                }
            //event.Skip();
            }
            return mystring;
        }
        return wxT("");//Just in case, should not be required
}

void Dlg::OnKey (wxKeyEvent& event)
{
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
    i_counter--;
    if (i_counter<0) i_counter=this->HistoryPulldownitemIndex;
    m_result->SetValue(this->m_HistoryPulldown->GetString(i_counter ));


}

void Dlg::down()
{
    i_counter++;
    if (i_counter>this->HistoryPulldownitemIndex) i_counter=0;
    m_result->SetValue(this->m_HistoryPulldown->GetString(i_counter ));




}

wxString Dlg::Report_Value(double in_Value, int in_mode){
    wxString Temp_String=wxT("");
    int human_magnitude=0;
    double result=0;
    switch(in_mode) {
        case 0:
            //printf("Precise (Default)\n");
            return wxString::Format(wxT("%15.15g"), in_Value);
            break;
        case 1:
            //printf("Precise, thousands separator\n");
            //setlocale(LC_ALL,""); //Causes Serious errors in OPENCPN, rounding all tracks waypoints and incoming data.
            return ThousandSeparator(wxString::Format(wxT("%'.15g"), in_Value));
            //return Temp_String;
            break;



        case 2:
            //printf("Succinct\n");
            return wxString::Format(wxT("%15.7g"), in_Value);
            break;
        case 3:
            //printf("Succinct, thousands separator\n");
            return ThousandSeparator(wxString::Format(wxT("%15.7g"), in_Value));
            break;
        case 4:
            //printf("Scientific\n");
            return wxString::Format(wxT("%.15le"), in_Value);
            break;
        case 5:
            //printf("Humanise\n");
            try{
                Temp_String=wxT("log10(abs(")+double2wxT(in_Value)+wxT("))/3");
                MuParser.SetExpr(static_cast<const char*>(Temp_String.mb_str()));
                human_magnitude=(int) MuParser.Eval();
                if (in_Value<1) {human_magnitude--;}
                Temp_String=double2wxT(in_Value)+wxT("*10^(-3*")+double2wxT((double)human_magnitude)+wxT(")");
                MuParser.SetExpr(static_cast<const char*>(Temp_String.mb_str()));
                result=MuParser.Eval();
                if (in_Value==0) {human_magnitude=0;}
                switch(human_magnitude){
                    case 8:Temp_String=wxT("yotta");break;
                    case 7:Temp_String=wxT("zetta");break;
                    case 6:Temp_String=wxT("exa");break;
                    case 5:Temp_String=wxT("peta");break;
                    case 4:Temp_String=wxT("tera");break;
                    case 3:Temp_String=wxT("giga");break;
                    case 2:Temp_String=wxT("mega");break;
                    case 1:Temp_String=wxT("kilo");break;
                    case 0:Temp_String=wxT("");break;
                    case -1:Temp_String=wxT("milli");break;
                    case -2:Temp_String=wxT("micro");break;
                    case -3:Temp_String=wxT("nano");break;
                    case -4:Temp_String=wxT("pico");break;
                    case -5:Temp_String=wxT("femto");break;
                    case -6:Temp_String=wxT("atto");break;
                    case -7:Temp_String=wxT("zepto");break;
                    case -8:Temp_String=wxT("yocto");break;

                    default: // do nothing
                        Temp_String=wxT("result out of SI prefixes range");
                        result=in_Value;
                    break;
                }
            }
            catch(mu::Parser::exception_type &e) {
                #ifdef DEBUG
                printf("Error Humanising number!!\n");
                #endif // DEBUG
                }
            return double2wxT(result) + wxT(" ") + Temp_String;
            break;
        default: // do nothing
            return wxT("Mode not Implemented");
            break;
        }
}

wxString Dlg::double2wxT(double in_Value){
    return wxString::Format(wxT("%15.15g"), in_Value);
}

wxString Dlg::ThousandSeparator(wxString Number_in){
    wxString Decimal_part=wxT("");
    //int i = Number_in.find(wxT("."));
    if((int)Number_in.find(wxT("."))<0) {Decimal_part=wxT("");} else {Decimal_part=wxT(".")+Number_in.AfterFirst('.');}
    Number_in=Number_in+wxT("."); //Add decimal point at the end
    wxString Temp_String=Number_in.BeforeFirst('.'); //Extract part before decimal point
    wxString Temp_String2=wxT("");

    while (Temp_String.length()>3) {
        Temp_String2=wxT(" ")+Temp_String.Right(3)+Temp_String2;
        printf("Temp String2:%s\n",(const char*)Temp_String2.mb_str());
        Temp_String=Temp_String.Left(Temp_String.length()-3);
        printf("Temp String:%s\n",(const char*)Temp_String.mb_str());
        }
    return Temp_String+Temp_String2+Decimal_part;
}


void Dlg::OnHistoryPulldown ( wxCommandEvent& event ){
    wxString Selected_Result=	this->m_HistoryPulldown->GetString( this->m_HistoryPulldown->GetCurrentSelection());
    Selected_Result=Selected_Result.BeforeFirst('=');
    //ItemText=ItemText.BeforeFirst(' ');
    this->m_result->AppendText(Selected_Result);
}
