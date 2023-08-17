#include "WGM_Driver.h"

wxBEGIN_EVENT_TABLE(WGM_Driver, wxFrame)
EVT_MENU(ADD_GOAL_MENU_ID, WGM_Driver::addGoalMenuSelected)
wxEND_EVENT_TABLE()

WGM_Driver::WGM_Driver() : wxFrame(nullptr, wxID_ANY, "Weekly Goal Manager", wxDefaultPosition, MAIN_APP_FRAME_SIZE)
{
    wxLog::EnableLogging(true);

    // Calculate the height for the top section (20% of the frame height)
    int topSectionHeight = GetSize().GetHeight() * 0.2;

    this->CenterOnScreen();
    this->SetBackgroundColour(APP_BACKGROUND_COLOUR);

    menu_bar = new wxMenuBar();
    menu = new wxMenu();
    menu->Append(ADD_GOAL_MENU_ID, "Add Goal");
    menu_bar->Append(menu, "Trajectory");
    this->SetMenuBar(menu_bar);

    btn_panel = new wxPanel(this);

    setUpDefaultButtons();
    btn_panel->SetSizer(btn_sizer);

    main_sizer = new wxBoxSizer(wxVERTICAL);
    top_sizer = new wxBoxSizer(wxHORIZONTAL);
    main_sizer->Add(top_sizer, 0, wxEXPAND);
    center_sizer = new wxBoxSizer(wxHORIZONTAL);
    center_sizer->AddStretchSpacer();
    center_sizer->Add(btn_panel, 0, wxALIGN_CENTER);
    center_sizer->AddStretchSpacer();

    top_sizer->Add(center_sizer, 1, wxEXPAND);

    this->SetSizer(main_sizer);
}

WGM_Driver::~WGM_Driver()
{
    
}

void WGM_Driver::setUpDefaultButtons()
{
    btns.push_back(new wxButton(btn_panel, 0, "Fitness"));
    btns.push_back(new wxButton(btn_panel, 1, "Finance"));
    btns.push_back(new wxButton(btn_panel, 2, "LeetCode"));

    btn_sizer = new wxBoxSizer(wxHORIZONTAL);
    for (size_t i = 0; i < btns.size(); i++) {
        btn_sizer->Add(btns[i], 1, wxALL, 10);
    }
}

void WGM_Driver::addGoalMenuSelected(wxCommandEvent& event)
{
    AddGoal* goal = new AddGoal(this);

    goal->Show();
    event.Skip();
}

void WGM_Driver::appendGoal(const wxString& new_goal)
{
    if (!new_goal.empty()) {
        btns.push_back(new wxButton(btn_panel, (int)btns.size(), new_goal));
        btn_sizer->Add(btns[(int)btns.size() - 1], 1, wxALL, 10);

        // Update the sizer's layout and the panel's layout
        btn_sizer->Layout();
        btn_panel->Layout();

        // Refresh the frame's layout
        this->Layout();
    }
}