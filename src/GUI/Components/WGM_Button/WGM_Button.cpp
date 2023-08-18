#include "include/WGM_Button.h"
#include "../../../Constants/include/Constants.h"

WGM_Button::WGM_Button(wxPanel* panel, const wxWindowID id, const wxString& name) : wxButton(panel, id, name)
{
	setDefault();
}

WGM_Button::WGM_Button(wxPanel* panel, 
					   const wxWindowID id, 
					   const wxString& name, 
					   const wxPoint& loc, 
					   const wxSize& size, 
					   const wxBorder border) : wxButton(panel, id, name, loc, size, border)
{
	setDefault();
}

WGM_Button::~WGM_Button()
{

}

void WGM_Button::setDefault()
{
	this->SetBackgroundColour(BUTTON_BACKGROUND_COLOUR);
	this->SetForegroundColour(BUTTON_FOREGROUND_COLOUR);
	this->SetFont(APP_BUTTON_FONT);
}