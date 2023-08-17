#pragma once

#include "Constants.h"
#include "WGM_Driver.h"

class WGM_Driver;

class AddGoal : public wxFrame
{
private:
	WGM_Driver* driver;
	wxBoxSizer* main_sizer = nullptr;
	wxPanel* panel = nullptr;
	wxBoxSizer* panel_sizer = nullptr;
	wxStaticText* goal_category_title = nullptr;
	wxTextCtrl* text_box = nullptr;
public:
	AddGoal(WGM_Driver* driver);
	~AddGoal();

	void addGoalClicked(wxCommandEvent& event);
};

