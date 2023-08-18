#include "include/WGM_TextCtrl.h"
#include "../../../Constants/include/Constants.h"

WGM_TextCtrl::WGM_TextCtrl(wxPanel* panel,
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
	this->SetBackgroundColour(DEFAULT_ITEM_BACKGROUND_COLOUR);
	this->SetForegroundColour(DEFAULT_ITEM_FOREGROUND_COLOUR);
}