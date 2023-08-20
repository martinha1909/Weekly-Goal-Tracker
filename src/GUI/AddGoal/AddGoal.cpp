#include "include/AddGoal.h"
#include "../Components/WGM_Button/include/WGM_Button.h"
#include "../Components/WGM_TextCtrl/include/WGM_TextCtrl.h"
#include "../../Driver/Goal/include/Goal.h"
#include "../../Constants/include/Constants.h"

AddGoal::AddGoal(WGM_Driver* driver) : wxFrame(nullptr, wxID_ANY, "Add Goal", wxDefaultPosition, ADD_GOAL_FRAME_SIZE)
{
    this->driver = driver;
    this->CenterOnScreen();
    this->SetBackgroundColour(APP_BACKGROUND_COLOUR);

    main_sizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(this, wxID_ANY);

    panel_sizer = new wxBoxSizer(wxVERTICAL);
    panel_sizer->AddStretchSpacer(1);

    goal_category_title = new WGM_StaticText(panel, wxID_ANY, wxString("Goal Category"));
    panel_sizer->Add(goal_category_title, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    text_box = new WGM_TextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, 20), wxBORDER_NONE | wxTE_PROCESS_ENTER);
    text_box->Bind(wxEVT_TEXT_ENTER, &AddGoal::addGoalClicked, this);

    panel_sizer->Add(text_box, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    // Add another flexible space to center-align the text boxes vertically
    panel_sizer->AddStretchSpacer(1);

    wxButton* add_button = new WGM_Button(this, panel, wxID_HIGHEST + 1, "Add", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    add_button->Bind(wxEVT_BUTTON, &AddGoal::addGoalClicked, this);

    panel_sizer->Add(add_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    // Set the panel's sizer
    panel->SetSizer(panel_sizer);

    // Add the panel to the main sizer
    main_sizer->Add(panel, 1, wxEXPAND);
    this->SetSizer(main_sizer);
}

AddGoal::~AddGoal()
{

}

void AddGoal::addGoalClicked(wxCommandEvent& event)
{
    wxString goal_category = text_box->GetValue(); // Get the value from the text box

    if (!goal_category.empty()) {
        if (driver) {
            Goal* goal = new Goal(goal_category.c_str());
            driver->appendGoal(goal);
        }
        Close(); // Close the AddGoal frame
    }
}