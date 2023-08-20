#include <wx/checklst.h>
#include "include/WGM_Goal_Progress.h"
#include "../../Constants/include/Constants.h"
#include "../Components/WGM_StaticText/include/WGM_StaticText.h"

WGM_Goal_Progress::WGM_Goal_Progress(Goal* goal, wxFrame* frame)
{
	this->goal = goal;
	this->frame = frame;
	num_sub_goals_done = 0;
	y_coor = GOAL_PROGRESS_TITLE_START_Y;
}

WGM_Goal_Progress::~WGM_Goal_Progress()
{

}

void WGM_Goal_Progress::show()
{
	if (frame) {
		int sub_goal_x_coor = 450;
		std::vector<Goal*>* sub_goals = goal->getSubGoals();
		
		y_coor = GOAL_PROGRESS_TITLE_START_Y;

		if (goal_title != nullptr) {
			goal_title->SetLabel(goal->getName());
			goal_title->Refresh();
		} else {
			goal_title = new WGM_StaticText(frame, wxID_ANY, goal->getName().c_str(), wxPoint(GOAL_PROGRESS_TITLE_START_X, y_coor), wxDefaultSize, wxALIGN_CENTER);
		}

		wxLogMessage("%s", goal->getName());

		y_coor = 120;
		
		progress = new wxGauge(frame, wxID_ANY, 100, wxPoint(450, 80), wxSize(300, 20), wxGA_HORIZONTAL);
		progress->SetValue(0); // Set progress to 20%

		/*int num = (int)sub_goal_checks.size();
		wxLogMessage("%d", num);*/
		for (size_t i = 0; i < sub_goals->size(); i++) {
			sub_goal_checks.push_back(new WGM_CheckBox(this, frame, wxID_ANY, sub_goals->at(i)->getName().c_str(), wxPoint(sub_goal_x_coor, y_coor), wxSize(300, 25)));
			y_coor += 35;
		}
	}
}

void WGM_Goal_Progress::updateProgress(bool progress_made)
{
	float ratio = (float)1 / (float)goal->getSubGoals()->size();
	int new_progress = static_cast<int>(ratio * 100);

	if (progress_made) {
		progress->SetValue(progress->GetValue() + new_progress);
		num_sub_goals_done++;
	} else {
		progress->SetValue(progress->GetValue() - new_progress);
		num_sub_goals_done--;
	}
	if (goal->getSubGoals()->size() <= 0) {
		progress->SetValue(0);
	} else {
		if (num_sub_goals_done == goal->getSubGoals()->size()) {
			progress->SetValue(100);
		}
	}
	progress->Refresh();
}

void WGM_Goal_Progress::resetUI()
{
	/*goal_title->Destroy();
	goal_title = nullptr;

	progress->Destroy();
	progress = nullptr;
	num_sub_goals_done = 0;

	for (size_t i = 0; i < sub_goal_checks.size(); i++) {
		sub_goal_checks[i]->Destroy();
	}
	sub_goal_checks.clear();*/
}