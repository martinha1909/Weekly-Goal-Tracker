#include <wx/checklst.h>
#include "include/WGM_Goal_Progress.h"
#include "../../Driver/WGM_Driver/include/WGM_Driver.h"
#include "../../Constants/include/Constants.h"
#include "../Components/WGM_StaticText/include/WGM_StaticText.h"

WGM_Goal_Progress::WGM_Goal_Progress(Goal* goal, wxFrame* frame)
{
	this->goal = goal;
	this->frame = frame;
	num_sub_goals_done = 0;
	complete_percentage = 0;
	y_coor = GOAL_PROGRESS_TITLE_START_Y;
}

WGM_Goal_Progress::~WGM_Goal_Progress()
{

}

void WGM_Goal_Progress::updateProgress(bool progress_made)
{
	float ratio = (float)1 / (float)goal->getSubGoals()->size();
	int new_progress = static_cast<int>(ratio * 100);

	if (progress_made) {
		complete_percentage += new_progress;
		num_sub_goals_done++;
	} else {
		complete_percentage -= new_progress;
		num_sub_goals_done--;
	}

	if (goal->getSubGoals()->size() <= 0) {
		complete_percentage = 0;
	} else {
		if (num_sub_goals_done == goal->getSubGoals()->size()) {
			complete_percentage = 100;
		}
	}

	dynamic_cast<WGM_Driver*>(frame)->updateProgressBarGUI(complete_percentage);
}

int WGM_Goal_Progress::getYCoor()
{
	return y_coor;
}

int WGM_Goal_Progress::getCompletePercentage()
{
	return complete_percentage;
}

Goal* WGM_Goal_Progress::getGoal()
{
	return goal;
}

void WGM_Goal_Progress::setYCoor(int coor)
{
	y_coor = coor;
}