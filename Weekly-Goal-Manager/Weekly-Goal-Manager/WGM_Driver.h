#pragma once

#include "Goal.h"
#include "wx/menu.h"

#define ADD_GOAL_BTN_ID 10001

class WGM_Driver : public wxFrame
{
private:
	std::vector<wxButton*> btns;
	wxBoxSizer* main_sizer = nullptr;
	wxBoxSizer* top_sizer = nullptr;
	wxPanel* btn_panel = nullptr;
	wxButton* add_goal_btn = nullptr;
	wxBoxSizer* btn_sizer = nullptr;
	wxBoxSizer* center_sizer = nullptr;

	void setUpDefaultButtons();
public:
	WGM_Driver();
	~WGM_Driver();

	void onButtonClicked(wxCommandEvent& event);
	void addGoalBtnClicked(wxCommandEvent& event);
};

