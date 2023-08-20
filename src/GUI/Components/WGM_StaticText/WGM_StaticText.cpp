#include "include/WGM_StaticText.h"
#include "../../../Constants/include/Constants.h"

WGM_StaticText::WGM_StaticText(wxPanel* panel, const wxWindowID id, const wxString& name) : wxStaticText(panel, id, name)
{
	setDefault();
}

WGM_StaticText::WGM_StaticText(wxFrame* frame, 
							   const wxWindowID id, 
							   const char* name, 
							   const wxPoint& loc, 
							   const wxSize& size, 
							   const wxAlignment align) : wxStaticText(frame, id, name, loc, size, align)
{
	setDefault();
}

WGM_StaticText::~WGM_StaticText()
{

}

void WGM_StaticText::setDefault()
{
	this->SetForegroundColour(TEXT_BOX_FOREGROUND_COLOUR);
	this->SetFont(APP_TEXT_BOX_FONT);
}