///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "calculatorgui.h"

///////////////////////////////////////////////////////////////////////////

DlgDef::DlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_Overview = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	m_result = new wxTextCtrl( m_Overview, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 420,40 ), wxTE_PROCESS_ENTER );
	m_result->SetMaxLength( 0 ); 
	m_result->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_result->SetMinSize( wxSize( 200,40 ) );
	m_result->SetMaxSize( wxSize( -1,40 ) );
	
	bSizer41->Add( m_result, 8, wxALL|wxEXPAND, 5 );
	
	Calculate = new wxButton( m_Overview, wxID_ANY, _("Calculate"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	Calculate->SetMinSize( wxSize( 80,30 ) );
	Calculate->SetMaxSize( wxSize( 80,40 ) );
	
	bSizer41->Add( Calculate, 0, wxALL|wxEXPAND, 5 );
	
	m_Help = new wxCheckBox( m_Overview, wxID_ANY, _("History"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_Help, 0, wxALL|wxEXPAND, 5 );
	
	m_HelpButton = new wxButton( m_Overview, wxID_ANY, _("?"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_HelpButton, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* HelpPanel;
	HelpPanel = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl = new wxListCtrl( m_Overview, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_AUTOARRANGE|wxLC_LIST|wxLC_SINGLE_SEL );
	m_listCtrl->Hide();
	
	HelpPanel->Add( m_listCtrl, 3, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( HelpPanel, 1, wxEXPAND, 5 );
	
	
	m_Overview->SetSizer( bSizer45 );
	m_Overview->Layout();
	bSizer45->Fit( m_Overview );
	bSizer7->Add( m_Overview, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_result->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_result->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	Calculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	m_HelpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnHelp ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	m_result->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_result->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	Calculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	m_HelpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnHelp ), NULL, this );
	
}

CfgDlgDef::CfgDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Show/Hide Buttons") ), wxVERTICAL );
	
	m_showhelpB = new wxCheckBox( this, wxID_ANY, _("Help Button"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhelpB->SetToolTip( _("Show/Hide help button (you can always type \"help\" from input window).") );
	
	sbSizer3->Add( m_showhelpB, 0, wxALL, 5 );
	
	m_showhistoryB = new wxCheckBox( this, wxID_ANY, _("History Toggle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhistoryB->SetValue(true); 
	m_showhistoryB->SetToolTip( _("Show/Hide history toggle (you can always type \"history\" from input window).") );
	
	sbSizer3->Add( m_showhistoryB, 0, wxALL, 5 );
	
	m_CalculateB = new wxCheckBox( this, wxID_ANY, _("Calculate Button"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CalculateB->SetValue(true); 
	m_CalculateB->SetToolTip( _("Show/Hide Calculate button (you can always press enter at the end of input).") );
	
	sbSizer3->Add( m_CalculateB, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("History Settings") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_Font_Size_txt = new wxStaticText( this, wxID_ANY, _("Max Results"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Font_Size_txt->Wrap( -1 );
	m_Font_Size_txt->SetToolTip( _("More results use up more memory. Memory is only allocated if required (e.g. if number is 30000, corresponding memory will only be used after this many calculations).") );
	
	fgSizer3->Add( m_Font_Size_txt, 0, wxALL, 5 );
	
	m_MaxResults = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 30000, 30000 );
	m_MaxResults->SetToolTip( _("More results use more memory. Memory will be cleared if Max Results is reached. NB variables are kept") );
	
	fgSizer3->Add( m_MaxResults, 0, wxALL, 5 );
	
	
	sbSizer4->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->Hide();
	
	sbSizer4->Add( m_staticText17, 0, wxALL, 5 );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_sOpacity->Hide();
	
	sbSizer4->Add( m_sOpacity, 0, wxALL|wxEXPAND, 5 );
	
	m_showhistory = new wxCheckBox( this, wxID_ANY, _("Show History Window"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhistory->SetToolTip( _("Show/Hide history") );
	
	sbSizer4->Add( m_showhistory, 0, wxALL, 5 );
	
	m_capturehidden = new wxCheckBox( this, wxID_ANY, _("Capture when Hidden"), wxDefaultPosition, wxDefaultSize, 0 );
	m_capturehidden->SetValue(true); 
	m_capturehidden->SetToolTip( _("Capture results in history, even when the history box is hidden. Uncheck this box to save some memory when history is hidden.") );
	
	sbSizer4->Add( m_capturehidden, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Other") ), wxVERTICAL );
	
	m_logresults = new wxCheckBox( this, wxID_ANY, _("Log results to opencpn"), wxDefaultPosition, wxDefaultSize, 0 );
	m_logresults->SetToolTip( _("Log calculator results in OpenCPN log file") );
	
	sbSizer41->Add( m_logresults, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer41, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

CfgDlgDef::~CfgDlgDef()
{
}

HlpDlgDef::HlpDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	HelpPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl3 = new wxTextCtrl( HelpPanel, wxID_ANY, _("Calculator Plugin for OpenCPN by SaltyPaws aka Walbert Schulpen\n=======================================\n\nThis is a light weight yet powerful calculator plugin for OpenCPN.  Would you like to know your hull speed?\n\nKey features are:\n* Storing results in variables\n* Shows historic calculations\n* Full scientific functions\n* Screen footprint can be optimised & minimised as required\n\nExamples of expression that work in the calculator are: (comments are in brackets, some results depend on other example calculations):\n=========\nHull speed:\n\tLWL=48\t\t\t(water line lenght in feet)\n\tvhull=1.34*LWL^(1/2)\t(hull speed in knots)\n\nConversions:\n\tftm=0.3048\t\t\t(feet to meters)\n\tkm_to_nm=0.539957\t\t(Kilometers to nautical Mile)\n\tftm*LWL\t\t\t(waterline length in meters)\n\nDistance to horizon\n\tR=6378.1*1000\t\t(Radius of the earth in m)\n\tH=2.5\t\t\t(Height of the eye above sea-level in m)\n\td = R * acos(R/(R + h))\t(Distance to horizon in m)   \n\tans*km_to_nm\t\t(Distance to horizon in nm)\n\nDistance to lighthouse\n\tH1=200\t\t\t(height of lighthouse in m)\n\td1 = R*acos(R/(R + H1))\t(Distance to horizon in m)\n\tdistance=d1+d\t\t(visibility range of lighthouse in m)\n\nOperators:\n\t+ - * / ^ (NB use ^(1/2) for square root)         \n\t% & | << >> = <> < > <= >= ||\n\t! (Factorial)\n \nFunctions:\n\tAbs, Exp, Sign, Sqrt, Log, Log10\n\tSin, Cos, Tan, ASin, ACos, Atan (default entry is in radians use e.g. sin(dtr*90) to calculate in degree)\n\tFactorial\n \nVariables:\n\tPi, e\n\tAns is the result of the previous calulation\n\tdtr is the conversion factor from degrees to radians\t\t\n\tyou can define your own variables (e.g. myvariable=10/8*cos(dtr*90) or yourvariable=Ans)\n\tclear removes results in the history, but leaves your defined variables in tact\n\nUser Interface - type these commands in the command window:\n\thistory - Toggle the history panel\n\tshowhelp - Show/Hide the Help button\n\tshowcalculate - Show/Hide the Calculate button\n\tshowhistory - Show/Hide the history toggle\n\thelp - show the help menu\n\nSettings/Plugins/Preferences:\n\tShow/Hide Calculate, Help and History toggle buttons\n\tHistory Settings: max Results - History will be cleared after this many results have been stored to save memory. Max 30000.\n\tShow history window: Show/Hide default state\n\tCapture when hidden: disable capturing of history when history panel is hidden - this will save some memory\n\tLog to opencpn: Enable/Disable logging of results to opencpn logfile."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_textCtrl3->SetMinSize( wxSize( 600,400 ) );
	
	bSizer10->Add( m_textCtrl3, 100, wxALL|wxEXPAND, 5 );
	
	
	bSizer11->Add( bSizer10, 5, wxEXPAND, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( HelpPanel, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2->Realize();
	
	bSizer11->Add( m_sdbSizer2, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	HelpPanel->SetSizer( bSizer11 );
	HelpPanel->Layout();
	bSizer11->Fit( HelpPanel );
	bSizer7->Add( HelpPanel, 3, wxALL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HlpDlgDef::OnClose ), NULL, this );
}

HlpDlgDef::~HlpDlgDef()
{
	// Disconnect Events
	m_sdbSizer2OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HlpDlgDef::OnClose ), NULL, this );
	
}
