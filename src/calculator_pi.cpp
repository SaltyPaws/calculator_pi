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

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "calculator_pi.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new calculator_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    Calculator PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

calculator_pi::calculator_pi(void *ppimgr)
      :opencpn_plugin_18(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}

int calculator_pi::Init(void)
{
      AddLocaleCatalog( _T("opencpn-calculator_pi") );

      // Set some default private member parameters
      m_calculator_dialog_x = 0;
      m_calculator_dialog_y = 0;
      m_calculator_dialog_width = 20;
      m_calculator_dialog_height = 20;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      //    This PlugIn needs a 2 toolbar icons, so request their insertion
      m_Calculator_tool_id  = InsertPlugInTool(_T(""), _img_calc, _img_calc, wxITEM_NORMAL,
            _("Calculator"), _T(""), NULL,
             CALCULATOR_TOOL_POSITION, 0, this);
     if((bool)m_bshowfunction_Open_CPN_BAR) {
      m_CalculatorFX_tool_id  = InsertPlugInTool(_T(""), _img_calc_fx, _img_calc_fx, wxITEM_NORMAL,
            _("Functions"), _T(""), NULL,
             CALCULATOR_TOOL_POSITION, 0, this);}

      m_pDialog = NULL;

      return (WANTS_TOOLBAR_CALLBACK   |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_PREFERENCES         |
              WANTS_CONFIG
           );
}

bool calculator_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pDialog)
      {
            //Capture dialog position
            wxPoint p = m_pDialog->GetPosition();
            SetCalculatorDialogX(p.x);
            SetCalculatorDialogY(p.y);
            //Capture dialog size
            wxSize q = m_pDialog->GetSize();
            SetCalculatorDialogWidth(q.x);
            SetCalculatorDialogHeight(q.y);

            m_pDialog->Close();
            delete m_pDialog;
            m_pDialog = NULL;
      }
      SaveConfig();
      return true;
}

int calculator_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int calculator_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int calculator_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int calculator_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *calculator_pi::GetPlugInBitmap()
{
      return _img_calc;
}

wxString calculator_pi::GetCommonName()
{
      return _("Calculator");
}

wxString calculator_pi::GetShortDescription()
{
      return _("Calculator Plugin");
}

wxString calculator_pi::GetLongDescription()
{
      return _("This is a light weight yet powerful calculator plugin for OpenCPN.\n  Would you like to know your hull speed?");
}

int calculator_pi::GetToolbarToolCount(void)
{
      //return 2;
      if((bool)m_bshowfunction_Open_CPN_BAR)
        {return 2;}
    else
      {return 1;}
}

void calculator_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pDialog)
            return;

      DimeWindow(m_pDialog);
}

void calculator_pi::OnToolbarToolCallback(int id)
{

    if(NULL == m_pDialog)
    {
        m_pDialog = new Dlg(m_parent_window);
        //m_pDialog->set_Parentwindow(*m_parent_window);
        this->SettingsPropagate();
        m_pDialog->set_Buttons();
        m_pDialog->set_History();

        /*printf("This is what we are sending to the window\n");
        printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
        printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
        printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
        printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
        //printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
        printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");*/


        m_pDialog->plugin = this;
        m_pDialog->Move(wxPoint(m_calculator_dialog_x, m_calculator_dialog_y));

        if ((m_calculator_dialog_width>60)&&(m_calculator_dialog_height>25))
        {
            if(m_bshowhistory)  //only set size if history is shown, otherwise we will get a gray panel
                m_pDialog->SetSize(wxSize(m_calculator_dialog_width, m_calculator_dialog_height));
        }

        else{
            m_pDialog->Fit();
            }
}
    if (id == m_Calculator_tool_id)
    {
        m_pDialog->Show(!m_pDialog->IsShown());
    }
    if (id==m_CalculatorFX_tool_id)
    {
        m_pDialog->OnFunction();
    }
    #ifdef DEBUG
    printf("Toolbar ID: %i\n",id);
    printf("Toolbar ID (from init): %i and %i\n",m_Calculator_tool_id,m_CalculatorFX_tool_id);
    #endif
}

bool calculator_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/Calculator" ) );
            pConf->Read ( _T ( "Opacity" ),  &m_iOpacity, 255 );
            pConf->Read ( _T ( "MaxResults" ),  &m_iMaxResults, 30 );
            m_calculator_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_calculator_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 170L );
            m_calculator_dialog_width = pConf->Read ( _T ( "DialogPosW" ), 300L );
            m_calculator_dialog_height = pConf->Read ( _T ( "DialogPosH" ), 540L );

            m_bshowhelpB = pConf->Read ( _T ( "m_bshowhelpB" ), 1 );
            m_bshowhistoryB = pConf->Read ( _T ( "m_bshowhistoryB" ), 1 );
            m_bCalculateB = pConf->Read ( _T ( "m_bCalculateB" ), 1 );
            m_bshowFunction = pConf->Read ( _T ( "m_bshowFunction" ), 1 );
            m_bshowhistory = pConf->Read ( _T ( "m_bshowhistory" ), 1 );
            //m_bcapturehidden = pConf->Read ( _T ( "m_bcapturehidden" ), 20L );
            m_blogresults = pConf->Read ( _T ( "m_blogresults" ), 1 );

            m_iCalc_Reporting = pConf->Read ( _T ( "m_iCalc_Reporting" ), 1 );
            m_bshowhistoryP = pConf->Read ( _T ( "m_bshowhistoryP" ), 1 );
            m_bshowfunction_Open_CPN_BAR = pConf->Read ( _T ( "m_bshowfunction_Open_CPN_BAR" ), 1 );
/*
            printf("Just got some results to the config file\n");
            printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
            printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
            printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
            printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
           // printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
            printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");*/

            if((m_calculator_dialog_x < 0) || (m_calculator_dialog_x > m_display_width))
                  m_calculator_dialog_x = 5;
            if((m_calculator_dialog_y < 0) || (m_calculator_dialog_y > m_display_height))
                  m_calculator_dialog_y = 5;
            if((m_calculator_dialog_width < 1) || ((m_calculator_dialog_x + m_calculator_dialog_width) > m_display_width))
                  m_calculator_dialog_width = 100;
            if((m_calculator_dialog_width < 1) || ((m_calculator_dialog_y + m_calculator_dialog_height) > m_display_height))
                  m_calculator_dialog_width = 40;
            if(m_iMaxResults < 1)
                   m_iMaxResults = 3;
            return true;
      }
      else
            return false;
}

bool calculator_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/Calculator" ) );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );
            pConf->Write ( _T ( "MaxResults" ), m_iMaxResults );
            //printf("Writing MaxResults %i \n",m_iMaxResults);
            pConf->Write ( _T ( "DialogPosX" ),   m_calculator_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_calculator_dialog_y );
            pConf->Write ( _T ( "DialogPosW" ),   m_calculator_dialog_width );
            pConf->Write ( _T ( "DialogPosH" ),   m_calculator_dialog_height );

            pConf->Write ( _T ( "m_bshowhelpB" ),   m_bshowhelpB );
            pConf->Write ( _T ( "m_bshowhistoryB" ),   m_bshowhistoryB );
            pConf->Write ( _T ( "m_bCalculateB" ),   m_bCalculateB );
            pConf->Write ( _T ( "m_bshowFunction" ),   m_bshowFunction );


            pConf->Write ( _T ( "m_bshowhistory" ),   m_bshowhistory );
           // pConf->Write ( _T ( "m_bcapturehidden" ),   m_bcapturehidden );
            pConf->Write ( _T ( "m_blogresults" ),   m_blogresults );

            pConf->Write ( _T ( "m_iCalc_Reporting" ),   m_iCalc_Reporting );
            pConf->Write ( _T ( "m_bshowhistoryP" ),   m_bshowhistoryP );
            pConf->Write ( _T ( "m_bshowfunction_Open_CPN_BAR" ),   m_bshowfunction_Open_CPN_BAR );

            printf("Just wrote some results to the config file\n");
            printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
            printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
            printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
            printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
            //printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
            printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");
            printf("m_iCalc_Reporting: %i\n",m_iCalc_Reporting);

            return true;
      }
      else
            return false;
}

void calculator_pi::ShowPreferencesDialog( wxWindow* parent )
{
      CfgDlg *dialog = new CfgDlg( parent, wxID_ANY, _("Calculator Preferences"), wxPoint( m_calculator_dialog_x, m_calculator_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      DimeWindow(dialog);
      dialog->m_sOpacity->SetValue(m_iOpacity);
      dialog->m_MaxResults->SetValue(m_iMaxResults);

      dialog->m_showhelpB->SetValue(m_bshowhelpB);
      dialog->m_showhistoryB->SetValue(m_bshowhistoryB);
      dialog->m_CalculateB->SetValue(m_bCalculateB);
      dialog->m_showfunction->SetValue(m_bshowFunction);
      dialog->m_showhistory->SetValue(m_bshowhistory);
      //dialog->m_capturehidden->SetValue(m_bcapturehidden);
      dialog->m_logresults->SetValue(m_blogresults);

      dialog->m_Calc_Reporting->SetSelection(m_iCalc_Reporting);
      dialog->m_showhistoryP->SetValue(m_bshowhistoryP);
      dialog->m_showfunction_Open_CPN_BAR->SetValue(m_bshowfunction_Open_CPN_BAR);

      if(dialog->ShowModal() == wxID_OK)
      {
            m_iOpacity = dialog->m_sOpacity->GetValue();
            m_iMaxResults = dialog->m_MaxResults->GetValue();
            m_bshowhelpB= dialog->m_showhelpB->GetValue();
            m_bshowhistoryB= dialog->m_showhistoryB->GetValue();
            m_bCalculateB= dialog->m_CalculateB->GetValue();
            m_bshowFunction= dialog->m_showfunction->GetValue();

            m_bshowhistory= dialog->m_showhistory->GetValue();
            //m_bcapturehidden= dialog->m_capturehidden->GetValue();
            m_blogresults= dialog->m_logresults->GetValue();


            m_iCalc_Reporting= dialog->m_Calc_Reporting->GetCurrentSelection();
            m_bshowhistoryP= dialog->m_showhistoryP->GetValue();
            m_bshowfunction_Open_CPN_BAR= dialog->m_showfunction_Open_CPN_BAR->GetValue();


            if (m_pDialog != NULL )
                this->SettingsPropagate(); //this will make a segfault if the plugin wasnt opened because the class doesn't exist yet.
            #ifdef DEBUG
            printf("Just got Results from config window\n");
            printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
            printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
            printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
            printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
            //printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
            printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");
            printf("m_iCalc_Reporting: %i\n",m_iCalc_Reporting);
            #endif

            SaveConfig();
      }
      delete dialog;
}

void calculator_pi::SettingsPropagate(void){
            m_pDialog->SetMaxResults(m_iMaxResults);
            m_pDialog->setm_bshowhelpB(m_bshowhelpB);
            m_pDialog->setm_bshowhistoryB(m_bshowhistoryB);
            m_pDialog->setm_bCalculateB(m_bCalculateB);
            m_pDialog->setm_bshowfunction(m_bshowFunction);

            m_pDialog->setm_bshowhistory(m_bshowhistory);
          //  m_pDialog->setm_bcapturehidden(m_bcapturehidden);
            m_pDialog->setm_blogresults(m_blogresults);

            m_pDialog->setm_iCalc_Reporting(m_iCalc_Reporting);
            m_pDialog->setm_bshowhistoryP(m_bshowhistoryP);

            m_pDialog->set_Buttons();
            m_pDialog->set_History();

            #ifdef DEBUG
            printf("Just propagated \n");
            printf("m_bshowhelpB: %s\n",(m_bshowhelpB)?"true":"false");
            printf("m_bshowhistoryB: %s\n",(m_bshowhistoryB)?"true":"false");
            printf("m_bCalculateB: %s\n",(m_bCalculateB)?"true":"false");
            printf("m_bshowhistory: %s\n",(m_bshowhistory)?"true":"false");
            //printf("m_bcapturehidden: %s\n",(m_bcapturehidden)?"true":"false");
            printf("m_blogresults: %s\n",(m_blogresults)?"true":"false");

            printf("m_iCalc_Reporting: %i\n",m_iCalc_Reporting);
            printf("m_bshowfunction_Open_CPN_BAR: %i\n",m_bshowfunction_Open_CPN_BAR);
            #endif // DEBUG

}


