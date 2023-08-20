#include <wx/checkbox.h>
#include <wx/checklst.h>
#include "include/WGM_Goal_Progress.h"
#include "../Components/WGM_StaticText/include/WGM_StaticText.h"

WGM_Goal_Progress::WGM_Goal_Progress(Goal* goal, wxFrame* frame)
{
	this->goal = goal;
	this->frame = frame;
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
		progress->SetValue(20); // Set progress to 20%

		for (int i = 0; i < 3; i++) {
			sub_goals.push_back(new WGM_CheckList(frame, wxID_ANY, wxPoint(450, row), wxSize(300, 25)));
			sub_goals[sub_goals.size() - 1]->Append(std::to_string(sub_goals[sub_goals.size() - 1]->GetId()));
			sub_goals[sub_goals.size() - 1]->Bind(wxEVT_CHECKLISTBOX, &WGM_Goal_Progress::onSubGoalComplete, this);
			row += 35;
		}
	}
}

void WGM_Goal_Progress::onSubGoalComplete(wxCommandEvent& event)
{
	int id = event.GetId();
	int item_id = event.GetInt();

	for (auto sub_goal : sub_goals) {
		if (sub_goal->GetId() == id) {
			sub_goal = new WGM_CheckList(frame, wxID_ANY, wxPoint(450, 120), wxSize(300, 25), wxColour(0, 255, 0));
			/*sub_goal->SetBackgroundColour(wxColour(0, 255, 0));
			sub_goal->Layout();*/
			break;
		}
	}
	event.Skip();
}