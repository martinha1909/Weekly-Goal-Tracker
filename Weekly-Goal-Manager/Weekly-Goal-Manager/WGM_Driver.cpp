#include "WGM_Driver.h"

WGM_Driver::WGM_Driver() : wxFrame(nullptr, wxID_ANY, "Weekly Goal Manager", wxDefaultPosition, wxSize(1000, 800))
{
    // Calculate the height for the top section (20% of the frame height)
    int topSectionHeight = GetSize().GetHeight() * 0.2;

    CenterOnScreen();

    main_sizer = new wxBoxSizer(wxVERTICAL);
    top_sizer = new wxBoxSizer(wxHORIZONTAL);

    setUpDefaultButtons();

    main_sizer->Add(top_sizer, 0, wxEXPAND);

    center_sizer = new wxBoxSizer(wxHORIZONTAL);
    center_sizer->AddStretchSpacer();
    center_sizer->Add(btn_panel, 0, wxALIGN_CENTER);
    center_sizer->AddStretchSpacer();

    top_sizer->Add(center_sizer, 1, wxEXPAND);

    SetSizer(main_sizer);
}

WGM_Driver::~WGM_Driver()
{
    
}

void WGM_Driver::setUpDefaultButtons()
{
    btn_panel = new wxPanel(this);

    btns.push_back(new wxButton(btn_panel, 0, "Fitness"));
    btns.push_back(new wxButton(btn_panel, 1, "Finance"));
    btns.push_back(new wxButton(btn_panel, 2, "LeetCode"));

    add_goal_btn = new wxButton(this, ADD_GOAL_BTN_ID, "Add Goal", wxPoint(915, 0));
    add_goal_btn->SetSize(wxSize(70, 20));
    add_goal_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WGM_Driver::addGoalBtnClicked, this);

    btn_sizer = new wxBoxSizer(wxHORIZONTAL);
    for (size_t i = 0; i < btns.size(); i++) {
        btn_sizer->Add(btns[i], 1, wxALL, 10);
    }
    btn_panel->SetSizer(btn_sizer);
}

void WGM_Driver::addGoalBtnClicked(wxCommandEvent& event)
{
    event.Skip();
}

void WGM_Driver::onButtonClicked(wxCommandEvent& event)
{
	event.Skip();
}