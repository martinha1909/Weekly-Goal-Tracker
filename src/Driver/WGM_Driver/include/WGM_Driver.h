#pragma once

#include <wx/menu.h>
#include <wx/log.h>
#include <wx/wx.h>
#include "../../../GUI/AddGoal/include/AddGoal.h"
#include "../../Goal/include/Goal.h"

class WGM_Driver : public wxFrame
{
private:
	std::vector<wxButton*> goals;
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
	void appendGoal(Goal* new_goal);
	void onRemoveGoal(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

