#pragma once

#include <wx/wx.h>

class WGM_TextCtrl : public wxTextCtrl
{
private:
	void setDefault();
public:
	WGM_TextCtrl(wxWindow* panel, 
				 const wxWindowID id, 
				 const wxChar* name, 
				 const wxPoint loc, 
				 const wxSize& size, 
				 const long border);
	~WGM_TextCtrl();
};

