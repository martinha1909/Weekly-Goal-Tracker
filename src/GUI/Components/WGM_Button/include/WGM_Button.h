#pragma once

#include <wx/wx.h>
#include "../../../../Driver/WGM_Driver/include/WGM_Driver.h"

class WGM_Button : public wxButton
{
protected:
	wxFrame* frame;

	void setDefault();
public:
	WGM_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, const wxString& name);
	WGM_Button(wxFrame* frame,
			   wxPanel* panel, 
			   const wxWindowID id, 
			   const wxString& name, 
			   const wxPoint& loc, 
			   const wxSize& size, 
			   const wxBorder border);
	virtual ~WGM_Button();
};

