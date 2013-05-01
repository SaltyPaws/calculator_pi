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

 #include "functions.h"

 CFormula::CFormula(void)
{
    this->Selected_Formula = 1;
    this->NumberOfFormulas = 3;

    this->m_ShortDesc[0]=_("Hull Speed (imperial)");
    this->m_LongDesc[0]=_("Hull speed, sometimes referred to as displacement speed, can be thought of the speed at which the wavelength of the boat's bow wave (in displacement mode) is equal to the boat length. As boat speed increases, the size of the bow wave increases, and therefore so does its wavelength. When hull speed is reached, a boat in pure displacement mode will appear trapped in a trough behind its very large bow wave.");
    this->m_Result_Unit[0]=_("Knots");
    this->m_Formula[0]=_("vhull=1.34*sqrt(LWL)");
    this->m_Input_parameter[0][0]=_("LWL");
    this->m_Input_unit[0][0]=_("feet");

    this->m_ShortDesc[1]=_("Hull Speed (metric)");
    this->m_LongDesc[1]=_("Hull speed, sometimes referred to as displacement speed, can be thought of the speed at which the wavelength of the boat's bow wave (in displacement mode) is equal to the boat length. As boat speed increases, the size of the bow wave increases, and therefore so does its wavelength. When hull speed is reached, a boat in pure displacement mode will appear trapped in a trough behind its very large bow wave.");
    this->m_Result_Unit[1]=_("Knots");
    this->m_Formula[1]=_("vhull=1.34*sqrt(LWL/0.3048)");
    this->m_Input_parameter[1][0]=_("LWL");
    this->m_Input_unit[1][0]=_("meter");

    this->m_ShortDesc[2]=_("Draft of vessel when heeled");
    this->m_LongDesc[2]=_("Draft of vessel when heeled");
    this->m_Result_Unit[2]=_("as Input units");
    this->m_Formula[2]=_("draft_heel=draft*cos(dtr*angle)");
    this->m_Input_parameter[2][0]=_("draft");
    this->m_Input_unit[2][0]=_("as Result Units");
    this->m_Input_parameter[2][1]=_("angle");
    this->m_Input_unit[2][1]=_("degree");

    this->m_ShortDesc[3]=_("test");
    this->m_LongDesc[3]=_("Yes siree");
    this->m_Result_Unit[3]=_("result_u");
    this->m_Formula[3]=_("draft_heel=draft*cos(dtr*angle)");
    this->m_Input_parameter[3][0]=_("a");
    this->m_Input_unit[3][0]=_("a_u");
    this->m_Input_parameter[3][1]=_("b");
    this->m_Input_unit[3][1]=_("b_u");
    this->m_Input_parameter[3][2]=_("c");
    this->m_Input_unit[3][2]=_("c_u");
    this->m_Input_parameter[3][3]=_("d");
    this->m_Input_unit[3][3]=_("d_u");
    this->m_Input_parameter[3][4]=_("e");
    this->m_Input_unit[3][4]=_("e_u");
    this->m_Input_parameter[3][5]=_("f");
    this->m_Input_unit[3][5]=_("f_u");
    this->m_Input_parameter[3][6]=_("g");
    this->m_Input_unit[3][6]=_("g_u");
    this->m_Input_parameter[3][7]=_("h");
    this->m_Input_unit[3][7]=_("h_u");
    this->m_Input_parameter[3][8]=_("i");
    this->m_Input_unit[3][8]=_("i_u");
    this->m_Input_parameter[3][9]=_("j");
    this->m_Input_unit[3][9]=_("j_u");
}
