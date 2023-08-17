#pragma once

#include "Goal.h"
#include "wx/menu.h"


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
	wxMenuBar* menu_bar = nullptr;
	wxMenu* menu = nullptr;

	void setUpDefaultButtons();
public:
	WGM_Driver();
	~WGM_Driver();

	void addGoalMenuSelected(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

