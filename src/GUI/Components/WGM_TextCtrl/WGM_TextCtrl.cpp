#include "include/WGM_TextCtrl.h"
#include "../../../Constants/include/Constants.h"

WGM_TextCtrl::WGM_TextCtrl(wxWindow* panel,
						   const wxWindowID id,
						   const wxChar* name,
						   const wxPoint loc,
						   const wxSize& size,
						   const long border) : wxTextCtrl(panel, id, name, loc, size, border)
{
	setDefault();
}

WGM_TextCtrl::~WGM_TextCtrl()
{

}

void WGM_TextCtrl::setDefault()
{
	this->SetBackgroundColour(TEXT_BOX_BACKGROUND_COLOUR);
	this->SetForegroundColour(TEXT_BOX_FOREGROUND_COLOUR);
}