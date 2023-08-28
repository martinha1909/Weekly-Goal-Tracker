#pragma once

#include <wx/menu.h>
#include <wx/log.h>
#include <wx/wx.h>
#include <wx/gauge.h>
#include "../../../GUI/AddGoal/include/AddGoal.h"
#include "../../Goal/include/Goal.h"
#include "../../../GUI/Components/WGM_StaticText/include/WGM_StaticText.h"
#include "../../../GUI/Components/WGM_Button/include/WGM_Button.h"
#include "../../../GUI/WGM_Goal_Progress/include/WGM_Goal_Progress.h"

class WGM_Goal_Progress;
class WGM_Button;
class WGM_TextCtrl;

class WGM_Driver : public wxFrame
{
private:
	static WGM_Driver* instance;
	Goal* current_goal = nullptr;
	wxPanel* btn_panel = nullptr;
	wxPanel* goal_panel = nullptr;
	wxButton* add_goal_btn = nullptr;
	wxBoxSizer* main_sizer = nullptr;
	wxBoxSizer* top_sizer = nullptr;
	wxBoxSizer* btn_sizer = nullptr;
	wxBoxSizer* center_sizer = nullptr;
	wxMenuBar* menu_bar = nullptr;
	wxMenu* menu = nullptr;
	wxComboBox* comboBox = nullptr;
	WGM_StaticText* title = nullptr;
	wxGauge* goal_progress = nullptr;
	std::vector<WGM_CheckBox*> sub_goal_checks;
	std::vector<wxButton*> goals;
	std::vector<wxSlider*> custom_goal_sliders;
	std::vector<WGM_TextCtrl*> custom_goal_slider_values;
	std::vector< WGM_StaticText*> custom_sub_goal_titles;
	std::vector<wxGauge*> custom_sub_goal_progress;
	std::vector<wxTimer*> auto_submit_timers;
	std::vector<int> auto_submit_timer_ids;

	void setUpDefaultButtons();
	void resetUI();
	inline int getSliderIndexFromTimer(int timer_id);
	void updateCustomGoalProgressUI(int custom_sub_goal_id, int new_progress);
	WGM_Driver();
public:
	WGM_Driver(const WGM_Driver& other) = delete;
	~WGM_Driver();

	static WGM_Driver* getInstance();
	void addGoalMenuSelected(wxCommandEvent& event);
	void appendGoal(Goal* new_goal);
	void onRemoveGoal(wxCommandEvent& event);
	void updateGoalGUI(WGM_Goal_Progress* progress);
	void updateProgressBarGUI(WGM_Goal_Progress* updated_progress);
	void onSliderUpdate(wxScrollEvent& event);
	void onSliderAutoSubmit(wxTimerEvent& event);
	void onSliderTextBoxEnter(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

