///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
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
	
	m_result = new wxTextCtrl( m_Overview, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 420,40 ), 0 );
	m_result->SetFont( wxFont( 20, 70, 90, 90, false, wxEmptyString ) );
	m_result->SetMinSize( wxSize( 200,40 ) );
	m_result->SetMaxSize( wxSize( -1,40 ) );
	
	bSizer41->Add( m_result, 1, wxALL, 5 );
	
	Calculate = new wxButton( m_Overview, wxID_ANY, _("Calculate"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	Calculate->SetMinSize( wxSize( 80,30 ) );
	Calculate->SetMaxSize( wxSize( 80,40 ) );
	
	bSizer41->Add( Calculate, 0, wxALL|wxEXPAND, 5 );
	
	m_Help = new wxCheckBox( m_Overview, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Help->SetMinSize( wxSize( 58,30 ) );
	
	bSizer41->Add( m_Help, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* HelpSizer;
	HelpSizer = new wxBoxSizer( wxVERTICAL );
	
	HelpPanel = new wxPanel( m_Overview, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	HelpText = new wxStaticText( HelpPanel, wxID_ANY, _("Examples (comments are in brackets, some results depend on other example calculations):\n=========\nHull speed:\n\tLWL=48 \t\t\t\t\t(water line lenght in feet)\n\tvhull=1.34*LWL^(1/2)\t(hull speed in knots)\n\nConversions:\n\tftm=0.3048\t\t\t\t(feet to metres)\n\tkm_to_nm=0.539957\t\t(Kilometre to nautical Mile)\n\tftm*LWL\t\t\t\t\t(waterline lenght in metres)\n\nDistance to horizon\n\tR=6378.1*1000\t\t\t(Radius of the earth in m)\n\tH=2.5\t\t\t\t\t\t(Height of the eye above sealevel in m)\n\td = R * acos(R/(R + h))\t(Distance to horizon in m)\t\n\tans*km_to_nm\t\t\t(Distance to horizon in nm)\n\nDistance to lighthouse\n\tH1=200\t\t\t\t\t(height of lighthouse in m)\n\td1 = R*acos(R/(R + H1))\t(Distance to horizon in m)\n\tdistance=d1+d\t\t\t(visability range of lighthouse in m)\n\nOperators:\n          & | << >> \n          = <> < > <= >=\n          + -\n          * / % ||\n          ^ (NB use ^(1/2) for square root)\n          ! (Factorial)\n \nFunctions:\n          Abs, Exp, Sign, Sqrt, Log, Log10\n          Sin, Cos, Tan, ASin, ACos, Atan (default entry is in radians use e.g. sin(dtr*90) to calculate in degree)\n          Factorial\n \nVariables:\n          Pi, e\n\t  dtr is the conversion factor from degrees to radians\n\t  Ans is the result of the previous calulation\t\t\n          you can define your own variables (e.g. myvariable=10/8*cos(dtr*90) or yourvariable=Ans)"), wxDefaultPosition, wxDefaultSize, 0 );
	HelpText->Wrap( -1 );
	bSizer11->Add( HelpText, 0, wxALL, 5 );
	
	
	HelpPanel->SetSizer( bSizer11 );
	HelpPanel->Layout();
	bSizer11->Fit( HelpPanel );
	HelpSizer->Add( HelpPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer45->Add( HelpSizer, 1, wxEXPAND, 5 );
	
	
	m_Overview->SetSizer( bSizer45 );
	m_Overview->Layout();
	bSizer45->Fit( m_Overview );
	bSizer7->Add( m_Overview, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Calculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	HelpText->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( DlgDef::OnToggle ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	Calculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	HelpText->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( DlgDef::OnToggle ), NULL, this );
	
}

CfgDlgDef::CfgDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General settings") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	sbSizer4->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	sbSizer4->Add( m_staticText17, 0, wxALL, 5 );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer4->Add( m_sOpacity, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	
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
