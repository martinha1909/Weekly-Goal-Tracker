#pragma once

#include <wx/wx.h>

class WGM_Separator : public wxPanel
{
private:
	void OnPaint(wxPaintEvent& event);
public:
	WGM_Separator(wxWindow* parent, wxWindowID id);
	~WGM_Separator();
};

