#pragma once

#include <wx/menu.h>
#include <wx/log.h>
#include <wx/wx.h>
#include <wx/gauge.h>
#include "../../../GUI/AddGoal/include/AddGoal.h"
#include "../../Goal/include/Goal.h"
#include "../../../GUI/Components/WGM_StaticText/include/WGM_StaticText.h"
#include "../../../GUI/WGM_Goal_Progress/include/WGM_Goal_Progress.h"

class WGM_Goal_Progress;

class WGM_Driver : public wxFrame
{
private:
	std::vector<WGM_CheckBox*> sub_goal_checks;
	std::vector<wxButton*> goals;
	wxBoxSizer* main_sizer = nullptr;
	wxBoxSizer* top_sizer = nullptr;
	wxPanel* btn_panel = nullptr;
	wxButton* add_goal_btn = nullptr;
	wxBoxSizer* btn_sizer = nullptr;
	wxBoxSizer* center_sizer = nullptr;
	wxMenuBar* menu_bar = nullptr;
	wxMenu* menu = nullptr;
	wxComboBox* comboBox = nullptr;
	WGM_StaticText* title = nullptr;
	wxGauge* goal_progress = nullptr;

	void setUpDefaultButtons();
public:
	WGM_Driver();
	~WGM_Driver();

	void addGoalMenuSelected(wxCommandEvent& event);
	void appendGoal(Goal* new_goal);
	void onRemoveGoal(wxCommandEvent& event);
	void updateGoalGUI(WGM_Goal_Progress* progress);
	void updateProgressBarGUI(int percentage);

	wxDECLARE_EVENT_TABLE();
};

