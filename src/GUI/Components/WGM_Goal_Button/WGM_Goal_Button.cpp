#include "include/WGM_Goal_Button.h"
#include <wx/wx.h>
#include <wx/button.h>
#include <wx/dcclient.h>

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, const char* name) : WGM_Button(frame, panel, id, wxString(name, wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	goal = new Goal(name, goal_id);
	setDefault();
}

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, Goal* goal) : WGM_Button(frame, panel, id, wxString(goal->getName().c_str(), wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	this->goal = goal;
	this->goal->setID(goal_id);
	setDefault();
}

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, 
								 wxPanel* panel,
								 const wxWindowID id,
								 const char* name,
								 const wxPoint& loc,
								 const wxSize& size,
								 const wxBorder border) : WGM_Button(frame, panel, id, wxString(name, wxConvUTF8), loc, size, border)
{
	int goal_id = wxWindowIDRef(id).GetValue();
	goal = new Goal(name, goal_id);
	setDefault();
}

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, 
								 wxPanel* panel,
								 const wxWindowID id,
								 Goal* goal,
								 const wxPoint& loc,
								 const wxSize& size,
								 const wxBorder border) : WGM_Button(frame, panel, id, wxString(goal->getName().c_str(), wxConvUTF8), loc, size, border)
{
	int goal_id = wxWindowIDRef(id).GetValue();
	this->goal = goal;
	this->goal->setID(goal_id);
	setDefault();
}

WGM_Goal_Button::~WGM_Goal_Button()
{
	if (goal != nullptr) {
		delete goal;
		goal = nullptr;
	}

	if (progress != nullptr) {
		delete progress;
		progress = nullptr;
	}
}

void WGM_Goal_Button::setDefault()
{
	progress = new WGM_Goal_Progress(this->goal, this->frame);
	this->Bind(wxEVT_CONTEXT_MENU, &WGM_Goal_Button::onRightClick, this);
	this->Bind(wxEVT_BUTTON, &WGM_Goal_Button::onLeftClick, this);
}

Goal* WGM_Goal_Button::getGoal()
{
	return goal;
}

void WGM_Goal_Button::onLeftClick(wxCommandEvent& event)
{
	dynamic_cast<WGM_Driver*>(frame)->updateGoalGUI(progress);
	//progress->show();
	event.Skip();
}

void WGM_Goal_Button::onRightClick(wxContextMenuEvent& event)
{
	// Create a context menu with menu items
	wxMenu contextMenu;
	contextMenu.Append(WGM_GOAL_BUTTON_REMOVE, "Remove");
	Bind(wxEVT_MENU, &WGM_Goal_Button::onMenuItemChosen, this);

	// Show the context menu at the mouse position
	PopupMenu(&contextMenu, this->ScreenToClient(event.GetPosition()));

	event.Skip();
}

void WGM_Goal_Button::onMenuItemChosen(wxCommandEvent& event)
{
	switch (event.GetId()) {
		case WGM_GOAL_BUTTON_REMOVE:
			wxCommandEvent removeEvent(wxEVT_COMMAND_BUTTON_CLICKED, WGM_GOAL_BUTTON_REMOVE);
			removeEvent.SetInt(this->goal->getID()); // Pass the ID of the goal
			wxPostEvent(frame, removeEvent); // Queue the event for the main thread
			break;
	}

	event.Skip();
}