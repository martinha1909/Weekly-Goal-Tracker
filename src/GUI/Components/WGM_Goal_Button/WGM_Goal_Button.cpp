#include "include/WGM_Goal_Button.h"
#include <wx/wx.h>
#include <wx/button.h>
#include <wx/dcclient.h>

WGM_Goal_Button::WGM_Goal_Button(wxPanel* panel, const wxWindowID id, const char* name) : WGM_Button(panel, id, wxString(name, wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	goal = new Goal(name, goal_id);
}

WGM_Goal_Button::WGM_Goal_Button(wxPanel* panel, const wxWindowID id, Goal* goal) : WGM_Button(panel, id, wxString(goal->getName().c_str(), wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	this->goal = goal;
	this->goal->setID(goal_id);
}

WGM_Goal_Button::WGM_Goal_Button(wxPanel* panel,
								 const wxWindowID id,
								 const char* name,
								 const wxPoint& loc,
								 const wxSize& size,
								 const wxBorder border) : WGM_Button(panel, id, wxString(name, wxConvUTF8), loc, size, border)
{
	int goal_id = wxWindowIDRef(id).GetValue();
	goal = new Goal(name, goal_id);
}

WGM_Goal_Button::WGM_Goal_Button(wxPanel* panel,
								 const wxWindowID id,
								 Goal* goal,
								 const wxPoint& loc,
								 const wxSize& size,
								 const wxBorder border) : WGM_Button(panel, id, wxString(goal->getName().c_str(), wxConvUTF8), loc, size, border)
{
	int goal_id = wxWindowIDRef(id).GetValue();
	this->goal = goal;
	this->goal->setID(goal_id);
}

WGM_Goal_Button::~WGM_Goal_Button()
{
	if (goal != nullptr) {
		delete goal;
		goal = nullptr;
	}
}