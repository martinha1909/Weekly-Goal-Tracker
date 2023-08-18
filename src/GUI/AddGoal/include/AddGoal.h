#pragma once

#include "../../../Driver/WGM_Driver/include/WGM_Driver.h"
#include "../../Components/WGM_StaticText/include/WGM_StaticText.h"
#include <wx/wx.h>

class WGM_Driver;

class AddGoal : public wxFrame
{
private:
	WGM_Driver* driver;
	wxBoxSizer* main_sizer = nullptr;
	wxPanel* panel = nullptr;
	wxBoxSizer* panel_sizer = nullptr;
	WGM_StaticText* goal_category_title = nullptr;
	wxTextCtrl* text_box = nullptr;
public:
	AddGoal(WGM_Driver* driver);
	~AddGoal();

	void addGoalClicked(wxCommandEvent& event);
};

