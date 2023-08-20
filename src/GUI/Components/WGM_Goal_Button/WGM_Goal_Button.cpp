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
	this->Bind(wxEVT_BUTTON, &WGM_Goal_Button::onLeftClick, this);
}

WGM_Goal_Button::~WGM_Goal_Button()
{
	if (goal != nullptr) {
		delete goal;
		goal = nullptr;
	}
}

Goal* WGM_Goal_Button::getGoal()
{
	return goal;
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

void WGM_Goal_Button::onLeftClick(wxCommandEvent& event)
{
	if (combo_box != nullptr) {
		combo_box->Destroy();
	}
	combo_box = new wxCheckListBox(frame, wxID_ANY, wxPoint(500, 80), wxSize(400, 100));

	// Add items to the combo box
	combo_box->Append("Option 1");
	combo_box->Append("Option 2");
	combo_box->Append("Option 3");

	// Bind event handler
	combo_box->Bind(wxEVT_COMBOBOX, &WGM_Goal_Button::onComboBoxSelected, this);
}

void WGM_Goal_Button::onComboBoxSelected(wxCommandEvent& event)
{
	//wxString selectedValue = combo_box->GetValue();
	//wxMessageBox("Selected: " + selectedValue, "ComboBox Selection", wxOK | wxICON_INFORMATION);
}