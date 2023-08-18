#pragma once

#include <wx/wx.h>

class WGM_Button : public wxButton
{
private:
	void setDefault();
public:
	WGM_Button(wxPanel* panel, const wxWindowID id, const wxString& name);
	WGM_Button(wxPanel* panel, 
			   const wxWindowID id, 
			   const wxString& name, 
			   const wxPoint& loc, 
			   const wxSize& size, 
			   const wxBorder border);
	~WGM_Button();
};

