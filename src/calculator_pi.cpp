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

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_calc, _img_calc, wxITEM_NORMAL,
            _("Calculator"), _T(""), NULL,
             CALCULATOR_TOOL_POSITION, 0, this);

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
      return _("Calculator");
}

wxString calculator_pi::GetLongDescription()
{
      return _("This is a calculator & mathematical expression parsing plugin. Would you like to know your hull speed?");
}

int calculator_pi::GetToolbarToolCount(void)
{
      return 1;
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
            m_pDialog->plugin = this;
            m_pDialog->Move(wxPoint(m_calculator_dialog_x, m_calculator_dialog_y));
            if ((m_calculator_dialog_width>60)||(m_calculator_dialog_height>25))
            {
                m_pDialog->SetSize(wxSize(m_calculator_dialog_width, m_calculator_dialog_height));
                //printf("setting size to: %d %d\n", m_calculator_dialog_x,m_calculator_dialog_y);
            }

            else{
                m_pDialog->Fit();
                //printf("Just fitting window");
                }
      }

      m_pDialog->Show(!m_pDialog->IsShown());
}

bool calculator_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/Calculator" ) );
            pConf->Read ( _T ( "Opacity" ),  &m_iOpacity, 255 );
           // pConf->Read       dialog->m_cpConnectorColor->SetColour(m_sConnectorColor);
            m_calculator_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_calculator_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );
            m_calculator_dialog_width = pConf->Read ( _T ( "DialogPosW" ), 20L );
            m_calculator_dialog_height = pConf->Read ( _T ( "DialogPosH" ), 20L );

            if((m_calculator_dialog_x < 0) || (m_calculator_dialog_x > m_display_width))
                  m_calculator_dialog_x = 5;
            if((m_calculator_dialog_y < 0) || (m_calculator_dialog_y > m_display_height))
                  m_calculator_dialog_y = 5;
            if((m_calculator_dialog_width < 0) || ((m_calculator_dialog_x + m_calculator_dialog_width) > m_display_width))
                  m_calculator_dialog_width = 5;
            if((m_calculator_dialog_width < 0) || ((m_calculator_dialog_y + m_calculator_dialog_height) > m_display_height))
                  m_calculator_dialog_width = 5;


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
            pConf->Write ( _T ( "DialogPosX" ),   m_calculator_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_calculator_dialog_y );
            pConf->Write ( _T ( "DialogPosW" ),   m_calculator_dialog_width );
            pConf->Write ( _T ( "DialogPosH" ),   m_calculator_dialog_height );


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

      if(dialog->ShowModal() == wxID_OK)
      {
            m_iOpacity = dialog->m_sOpacity->GetValue();
            SaveConfig();
      }
      delete dialog;
}

