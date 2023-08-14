#pragma once

#include "wx/wx.h"

class WGM_Driver : public wxFrame
{
private:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btns = nullptr;
	int* nField = nullptr;
	bool bFirstClick = true;
public:
	WGM_Driver();
	~WGM_Driver();

	void onButtonClicked(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

