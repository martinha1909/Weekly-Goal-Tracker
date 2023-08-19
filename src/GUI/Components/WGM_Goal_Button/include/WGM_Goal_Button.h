#pragma once

#include "../../WGM_Button/include/WGM_Button.h"
#include "../../../../Driver/Goal/include/Goal.h"

typedef enum WGM_goal_button_option {
	WGM_GOAL_BUTTON_REMOVE = wxID_HIGHEST + 1
	//More options go here
} WGM_goal_button_option_e;

class WGM_Goal_Button : public WGM_Button
{
private:
	Goal* goal;
public:
	WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, const char* name);
	WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, Goal* goal);
	WGM_Goal_Button(wxFrame* frame, 
				    wxPanel* panel,
					const wxWindowID id,
					const char* name,
					const wxPoint& loc,
					const wxSize& size,
					const wxBorder border);
	WGM_Goal_Button(wxFrame* frame, 
					wxPanel* panel,
					const wxWindowID id,
					Goal* goal,
					const wxPoint& loc,
					const wxSize& size,
					const wxBorder border);
	~WGM_Goal_Button();
	void onRightClick(wxContextMenuEvent& event);
	void onMenuItemChosen(wxCommandEvent& event);
	Goal* getGoal();
};

