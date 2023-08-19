#include "include/WGM_Driver.h"
#include "../../GUI/Components/WGM_Goal_Button/include/WGM_Goal_Button.h"
#include "../../Constants/include/Constants.h"

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
    
    //Bind to event queue so that when a button is removed, wxWdiget will use its asynchronous event queue to remove a button,
    //which will not cause unexpected behaviour with the GUI
    this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WGM_Driver::onRemoveGoal, this, WGM_GOAL_BUTTON_REMOVE);
}

WGM_Driver::~WGM_Driver()
{
    
}

void WGM_Driver::setUpDefaultButtons()
{
    goals.push_back(new WGM_Goal_Button(this, btn_panel, 0, new Goal("Fitness"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
    goals.push_back(new WGM_Goal_Button(this, btn_panel, 1, new Goal("Finance"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
    goals.push_back(new WGM_Goal_Button(this, btn_panel, 2, new Goal("LeetCode"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));

    btn_sizer = new wxBoxSizer(wxHORIZONTAL);
    for (size_t i = 0; i < goals.size(); i++) {
        btn_sizer->Add(goals[i], 1, wxALL, 10);
    }
}

void WGM_Driver::addGoalMenuSelected(wxCommandEvent& event)
{
    AddGoal* goal = new AddGoal(this);

    goal->Show();
    event.Skip();
}

void WGM_Driver::appendGoal(Goal* new_goal)
{
    if (new_goal != NULL) {
        goals.push_back(new WGM_Goal_Button(this, btn_panel, (int)goals.size(), new_goal));
        btn_sizer->Add(goals[(int)goals.size() - 1], 1, wxALL, 10);

        // Update the sizer's layout and the panel's layout
        btn_sizer->Layout();
        btn_panel->Layout();

        // Refresh the frame's layout
        this->Layout();
    }
}

void WGM_Driver::onRemoveGoal(wxCommandEvent& event)
{
    int goal_id = event.GetInt(); // Get the goal ID from the event
    int i = 0;

    for (auto goal : goals) {
        if (dynamic_cast<WGM_Goal_Button*>(goal)->getGoal()->getID() == goal_id) {
            btn_sizer->Detach(goal);
            goal->Destroy();
            goals.erase(goals.begin() + i);
            btn_sizer->Layout();
            btn_panel->Layout();
            break;
        }
        i++;
    }
}
