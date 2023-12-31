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
	Goal* goal = nullptr;
	wxFrame* frame = nullptr;
	float complete_percentage;
	int y_coor;
public:
	WGM_Goal_Progress(Goal* goal, wxFrame* frame);
	~WGM_Goal_Progress();
	void updateProgress(bool progress_made, int goal_id);
	int getYCoor();
	Goal* getGoal();
	int getCompletePercentage();
	void setYCoor(int coor);
};

