#pragma once

#include <wx/wx.h>

class WGM_StaticText : public wxStaticText
{
private:
	void setDefault();
public:
	WGM_StaticText(wxPanel* panel, const wxWindowID id, const wxString& name);
	WGM_StaticText(wxFrame* frame, const wxWindowID id, const char* name, const wxPoint& loc, const wxSize& size, const wxAlignment align);
	~WGM_StaticText();
};

