#pragma once

#include <wx/wx.h>
#include <wx/gauge.h>
#include "../../../Driver/Goal/include/Goal.h"

class Goal;

class WGM_Goal_Progress
{
private:
	Goal* goal = nullptr;
	wxFrame* frame = nullptr;
	wxGauge* progress = nullptr;
public:
	WGM_Goal_Progress(Goal* goal, wxFrame* frame);
	~WGM_Goal_Progress();
	void show();
};

