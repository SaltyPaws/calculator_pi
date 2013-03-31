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
	
	m_result = new wxTextCtrl( m_Overview, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 420,40 ), wxTE_DONTWRAP|wxTE_PROCESS_ENTER );
	m_result->SetMaxLength( 0 ); 
	m_result->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_result->SetMinSize( wxSize( 200,40 ) );
	m_result->SetMaxSize( wxSize( -1,40 ) );
	
	bSizer41->Add( m_result, 1, wxALL|wxEXPAND, 5 );
	
	Calculate = new wxButton( m_Overview, wxID_ANY, _("Calculate"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	Calculate->SetMinSize( wxSize( 80,30 ) );
	Calculate->SetMaxSize( wxSize( 80,40 ) );
	
	bSizer41->Add( Calculate, 0, wxALL|wxEXPAND, 5 );
	
	m_Help = new wxCheckBox( m_Overview, wxID_ANY, _("History"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_Help, 0, wxALL|wxEXPAND, 5 );
	
	m_HelpButton = new wxButton( m_Overview, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_HelpButton, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* HelpSizer;
	HelpSizer = new wxBoxSizer( wxVERTICAL );
	
	HelpPanel = new wxPanel( m_Overview, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	HelpSizer->Add( HelpPanel, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl = new wxListCtrl( m_Overview, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_listCtrl, 3, wxALL|wxEXPAND, 5 );
	
	
	HelpSizer->Add( bSizer8, 1, wxEXPAND, 5 );
	
	
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
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General settings") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_Font_Size_txt = new wxStaticText( this, wxID_ANY, _("Font Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Font_Size_txt->Wrap( -1 );
	fgSizer3->Add( m_Font_Size_txt, 0, wxALL, 5 );
	
	m_FontSize = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99, 20 );
	fgSizer3->Add( m_FontSize, 0, wxALL, 5 );
	
	
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
