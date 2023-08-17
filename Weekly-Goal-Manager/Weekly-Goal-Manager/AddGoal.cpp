#include "AddGoal.h"

AddGoal::AddGoal(WGM_Driver* driver) : wxFrame(nullptr, wxID_ANY, "Add Goal", wxDefaultPosition, ADD_GOAL_FRAME_SIZE)
{
    wxFont goal_category_title_font(wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Roboto").Bold());

    this->driver = driver;
    this->CenterOnScreen();
    this->SetBackgroundColour(APP_BACKGROUND_COLOUR);

    main_sizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(this, wxID_ANY);

    panel_sizer = new wxBoxSizer(wxVERTICAL);
    panel_sizer->AddStretchSpacer(1);

    goal_category_title = new wxStaticText(panel, wxID_ANY, wxString("Goal Category"));
    goal_category_title->SetForegroundColour(wxColour(51, 51, 51));
    goal_category_title->SetFont(goal_category_title_font);
    panel_sizer->Add(goal_category_title, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    text_box = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, 20), wxBORDER_NONE | wxTE_PROCESS_ENTER);
    text_box->SetBackgroundColour(wxColour(0, 0, 0));
    text_box->SetForegroundColour(wxColour(255, 255, 255));
    text_box->Bind(wxEVT_TEXT_ENTER, &AddGoal::addGoalClicked, this);

    panel_sizer->Add(text_box, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    // Add another flexible space to center-align the text boxes vertically
    panel_sizer->AddStretchSpacer(1);

    wxButton* add_button = new wxButton(panel, wxID_ANY, "Add", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    add_button->SetBackgroundColour(wxColour(0, 0, 0));
    add_button->SetForegroundColour(wxColour(255, 255, 255));
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
            driver->appendGoal(goal_category);
        }
        Close(); // Close the AddGoal frame
    }

}