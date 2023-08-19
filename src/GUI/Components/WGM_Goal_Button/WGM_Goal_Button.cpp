#include "include/WGM_Goal_Button.h"
#include <wx/wx.h>
#include <wx/button.h>
#include <wx/dcclient.h>

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, const char* name) : WGM_Button(frame, panel, id, wxString(name, wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	goal = new Goal(name, goal_id);
}

WGM_Goal_Button::WGM_Goal_Button(wxFrame* frame, wxPanel* panel, const wxWindowID id, Goal* goal) : WGM_Button(frame, panel, id, wxString(goal->getName().c_str(), wxConvUTF8))
{
	int goal_id = wxWindowIDRef(id).GetValue();
	this->goal = goal;
	this->goal->setID(goal_id);
	this->Bind(wxEVT_CONTEXT_MENU, &WGM_Goal_Button::onRightClick, this);
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
	this->Bind(wxEVT_CONTEXT_MENU, &WGM_Goal_Button::onRightClick, this);
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
	this->Bind(wxEVT_CONTEXT_MENU, &WGM_Goal_Button::onRightClick, this);
}

WGM_Goal_Button::~WGM_Goal_Button()
{
	if (goal != nullptr) {
		delete goal;
		goal = nullptr;
	}
}

void WGM_Goal_Button::onRightClick(wxContextMenuEvent& event)
{
	// Create a context menu with menu items
	wxMenu contextMenu;
	contextMenu.Append(WGM_GOAL_BUTTON_REMOVE, "Remove");
	Bind(wxEVT_MENU, &WGM_Goal_Button::onMenuItemChosen, this); // Bind to function for Menu Item 1

	// Show the context menu at the mouse position
	PopupMenu(&contextMenu, this->ScreenToClient(event.GetPosition()));

	event.Skip();
}

void WGM_Goal_Button::onMenuItemChosen(wxCommandEvent& event)
{
	switch (event.GetId()) {
		case WGM_GOAL_BUTTON_REMOVE:
			dynamic_cast<WGM_Driver*>(frame)->removeGoal(this->goal);
			break;
		default:
			break;
	}

	event.Skip();
}