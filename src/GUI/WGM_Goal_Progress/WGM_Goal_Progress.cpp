#include <wx/checklst.h>
#include "include/WGM_Goal_Progress.h"
#include "../Components/WGM_StaticText/include/WGM_StaticText.h"

WGM_Goal_Progress::WGM_Goal_Progress(Goal* goal, wxFrame* frame)
{
	this->goal = goal;
	this->frame = frame;
	num_sub_goals_done = 0;
}

WGM_Goal_Progress::~WGM_Goal_Progress()
{

}

void WGM_Goal_Progress::show()
{
	if (frame) {
		int row = 120;
		wxStaticText* titleLabel = new WGM_StaticText(frame, wxID_ANY, "Title Text", wxPoint(380, 80), wxDefaultSize, wxALIGN_CENTER);
		
		progress = new wxGauge(frame, wxID_ANY, 100, wxPoint(450, 80), wxSize(300, 20), wxGA_HORIZONTAL);
		progress->SetValue(0); // Set progress to 20%

		num_sub_goals = 3;
		for (int i = 0; i < 3; i++) {
			sub_goals.push_back(new WGM_CheckBox(this, frame, wxID_ANY, "sjfi", wxPoint(450, row), wxSize(300, 25)));
			row += 35;
		}
	}
}

void WGM_Goal_Progress::updateProgress(bool progress_made)
{
	float ratio = (float)1 / (float)num_sub_goals;
	int new_progress = static_cast<int>(ratio * 100);

	if (progress_made) {
		progress->SetValue(progress->GetValue() + new_progress);
		num_sub_goals_done++;
	} else {
		progress->SetValue(progress->GetValue() - new_progress);
		num_sub_goals_done--;
	}
	if (num_sub_goals <= 0) {
		progress->SetValue(0);
	} else {
		if (num_sub_goals_done == num_sub_goals) {
			progress->SetValue(100);
		}
	}
	progress->Refresh();
}