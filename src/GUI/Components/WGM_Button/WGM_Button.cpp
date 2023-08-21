#include "include/WGM_Button.h"
#include "../../../Constants/include/Constants.h"

WGM_Button::WGM_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, const wxString& name) : wxButton(panel, id, name)
{
	this->frame = frame;
	setDefault();
}

WGM_Button::WGM_Button(wxFrame* frame,
					   wxPanel* panel, 
					   const wxWindowID id, 
					   const wxString& name, 
					   const wxPoint& loc, 
					   const wxSize& size, 
					   const wxBorder border) : wxButton(panel, id, name, loc, size, border)
{
	this->frame = frame;
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
	this->Bind(wxEVT_ENTER_WINDOW, &WGM_Button::onMouseEnter, this);
	this->Bind(wxEVT_LEAVE_WINDOW, &WGM_Button::onMouseLeave, this);
}

void WGM_Button::onMouseEnter(wxMouseEvent& event)
{
	this->SetBackgroundColour(BUTTON_HOVER_BACKGROUND_COLOUR);
	event.Skip();
}
void WGM_Button::onMouseLeave(wxMouseEvent& event)
{
	this->SetBackgroundColour(BUTTON_BACKGROUND_COLOUR);
	event.Skip();
}