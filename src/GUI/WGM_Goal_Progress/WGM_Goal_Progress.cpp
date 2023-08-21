#include <wx/checklst.h>
#include "include/WGM_Goal_Progress.h"
#include "../../Driver/WGM_Driver/include/WGM_Driver.h"
#include "../../Driver/Goal/include/DefaultGoal.h"
#include "../../Constants/include/Constants.h"
#include "../Components/WGM_StaticText/include/WGM_StaticText.h"

WGM_Goal_Progress::WGM_Goal_Progress(Goal* goal, wxFrame* frame)
{
	this->goal = goal;
	this->frame = frame;
	complete_percentage = 0;
	y_coor = GOAL_PROGRESS_TITLE_START_Y;
}

WGM_Goal_Progress::~WGM_Goal_Progress()
{

}

void WGM_Goal_Progress::updateProgress(bool progress_made, int goal_id)
{
	if (dynamic_cast<DefaultGoal*>(goal) != nullptr) {
		DefaultGoal* curr_goal = dynamic_cast<DefaultGoal*>(goal);
		float ratio = (float)1 / (float)curr_goal->getSubGoals()->size();
		int new_progress = static_cast<int>(ratio * 100);

		for (size_t i = 0; i < curr_goal->getSubGoals()->size(); i++) {
			if (curr_goal->getSubGoals()->at(i)->getID() == goal_id) {
				curr_goal->getSubGoals()->at(i)->setComplete(progress_made);
				break;
			}
		}

		if (progress_made) {
			complete_percentage += new_progress;
			curr_goal->setNumSubGoalsDone(curr_goal->getNumSubGoalsDone() + 1);
		} else {
			complete_percentage -= new_progress;
			curr_goal->setNumSubGoalsDone(curr_goal->getNumSubGoalsDone() - 1);
		}

		if (curr_goal->getSubGoals()->size() <= 0) {
			complete_percentage = 0;
		} else {
			if (curr_goal->getNumSubGoalsDone() == (int)curr_goal->getSubGoals()->size()) {
				complete_percentage = 100;
			}
		}

		dynamic_cast<WGM_Driver*>(frame)->updateProgressBarGUI(this);
	}
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