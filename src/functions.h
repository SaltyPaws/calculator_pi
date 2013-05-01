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

//#include <vector>

class CFormula
{
   public:
      CFormula (void);                       // constructor
      int Selected_Formula;                  // formula selected
      wxArrayString m_ShortDesc;             // Short description of function for pulldown menu
      wxArrayString m_LongDesc;              // Long description
      wxArrayString m_Formula;               // Formula in a form directly understandable by calculator
      wxArrayString m_Result_Unit;           // Units of result (e.g. meter, feet, m/s etc)
      wxArrayString m_Category;               // Category of formula
      wxArrayString m_Source;                 // Source of formula

      // Input parameters (e.g. lenght, speed, etc)
      wxArrayString m_Input_parameter;
      wxArrayString m_Input_parameter1;
      wxArrayString m_Input_parameter2;
      wxArrayString m_Input_parameter3;
      wxArrayString m_Input_parameter4;
      wxArrayString m_Input_parameter5;
      wxArrayString m_Input_parameter6;
      wxArrayString m_Input_parameter7;
      wxArrayString m_Input_parameter8;
      wxArrayString m_Input_parameter9;

      // Input unit (e.g. meter, feet, m/s etc
      wxArrayString m_Input_unit;
      wxArrayString m_Input_unit1;
      wxArrayString m_Input_unit2;
      wxArrayString m_Input_unit3;
      wxArrayString m_Input_unit4;
      wxArrayString m_Input_unit5;
      wxArrayString m_Input_unit6;
      wxArrayString m_Input_unit7;
      wxArrayString m_Input_unit8;
      wxArrayString m_Input_unit9;
};


#endif //_FUNCTIONS_H_
