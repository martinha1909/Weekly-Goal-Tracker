#include "include/WGM_StaticText.h"
#include "../../../Constants/include/Constants.h"

WGM_StaticText::WGM_StaticText(wxPanel* panel, const wxWindowID id, const wxString& name) : wxStaticText(panel, id, name)
{
	setDefault();
}

WGM_StaticText::~WGM_StaticText()
{

}

void WGM_StaticText::setDefault()
{
	this->SetForegroundColour(DEFAULT_ITEM_FOREGROUND_COLOUR);
	this->SetFont(APP_TEXT_BOX_FONT);
}