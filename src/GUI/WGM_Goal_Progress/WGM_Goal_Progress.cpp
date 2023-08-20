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
	wxStaticText* titleLabel = new WGM_StaticText(frame, wxID_ANY, "Title Text", wxPoint(380, 98), wxDefaultSize, wxALIGN_CENTER);

	progress = new wxGauge(frame, wxID_ANY, 100, wxPoint(450, 100), wxSize(300, 15), wxGA_HORIZONTAL);
	progress->SetValue(20); // Set progress to 20%
}