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

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

class CFormula
{
   public:
      CFormula (void);                       // constructor
      int NumberOfFormulas;                  // size of array of formulas
      int Selected_Formula;                  // formula selected
      wxString m_ShortDesc[100];             // Short description
      wxString m_LongDesc[100];              // Long description
      wxString m_Formula[100];               // Formula in a form directly understandable by calculator
      wxString m_Result_Unit[100];           // Units of result (e.g. meter, feet, m/s etc)
      wxString m_Input_parameter[100][10];   // Input parameter (e.g. lenght, speed, etc)
      wxString m_Input_unit[100][10];        // Input unit (e.g. meter, feet, m/s etc

};


#endif //_FUNCTIONS_H_
