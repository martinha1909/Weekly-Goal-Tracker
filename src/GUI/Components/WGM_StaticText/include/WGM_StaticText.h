#pragma once

#include <wx/wx.h>

class WGM_StaticText : public wxStaticText
{
private:
	void setDefault();
public:
	WGM_StaticText(wxPanel* panel, const wxWindowID id, const wxString& name);
	~WGM_StaticText();
};

