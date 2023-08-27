#pragma once

#include <wx/wx.h>
#include "../../../../Driver/WGM_Driver/include/WGM_Driver.h"

class WGM_Button : public wxButton
{
protected:
	wxFrame* frame;

	void setDefault();
public:
	WGM_Button(wxFrame* frame, wxWindow* panel, const wxWindowID id, const wxString& name);
	WGM_Button(wxFrame* frame,
			   wxWindow* panel,
			   const wxWindowID id, 
			   const wxString& name, 
			   const wxPoint& loc, 
			   const wxSize& size, 
			   const wxBorder border);
	void onMouseEnter(wxMouseEvent& event);
	void onMouseLeave(wxMouseEvent& event);
	void onButtonSelected(wxFocusEvent& event);
	void onButtonDeSelected(wxFocusEvent& event);
	virtual ~WGM_Button();
};

