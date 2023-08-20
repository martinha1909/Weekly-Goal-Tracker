#pragma once

#include <wx/wx.h>
#include <wx/gauge.h>
#include <wx/checkbox.h>
#include "../../../Driver/Goal/include/Goal.h"
#include "../../Components/WGM_CheckList/include/WGM_CheckBox.h"

class Goal;
class WGM_CheckBox;

class WGM_Goal_Progress
{
private:
	int num_sub_goals_done;
	int y_coor;
	Goal* goal = nullptr;
	wxFrame* frame = nullptr;
	wxGauge* progress = nullptr;
	std::vector<WGM_CheckBox*> sub_goal_checks;
public:
	WGM_Goal_Progress(Goal* goal, wxFrame* frame);
	~WGM_Goal_Progress();
	void show();
	void updateProgress(bool progress_made);
};

