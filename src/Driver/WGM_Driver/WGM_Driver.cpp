#include "include/WGM_Driver.h"
#include "../../GUI/Components/WGM_Goal_Button/include/WGM_Goal_Button.h"
#include "../../Constants/include/Constants.h"

wxBEGIN_EVENT_TABLE(WGM_Driver, wxFrame)
EVT_MENU(ADD_GOAL_MENU_ID, WGM_Driver::addGoalMenuSelected)
wxEND_EVENT_TABLE()

WGM_Driver::WGM_Driver() : wxFrame(nullptr, 
                                   wxID_ANY, 
                                   "Weekly Goal Manager", 
                                   wxDefaultPosition, 
                                   MAIN_APP_FRAME_SIZE, 
                                   wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX)
{
    wxLog::EnableLogging(true);

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
    title = new WGM_StaticText(this, wxID_ANY, "", wxPoint(350, 80), wxDefaultSize, wxALIGN_CENTER);
}

WGM_Driver::~WGM_Driver()
{
    
}

void WGM_Driver::setUpDefaultButtons()
{
    Goal* fitness = new Goal("Fitness", WGM_NEXT_ID());
    Goal* lc = new Goal("LeetCode", WGM_NEXT_ID());

    fitness->addSubGoal(new Goal("gym", WGM_NEXT_ID()));

    lc->addSubGoal(new Goal("Easy", WGM_NEXT_ID()));
    lc->addSubGoal(new Goal("Medium", WGM_NEXT_ID()));
    lc->addSubGoal(new Goal("Hard", WGM_NEXT_ID()));

    goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), fitness, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
    goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), lc, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));

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

void WGM_Driver::updateGoalGUI(WGM_Goal_Progress* progress)
{
    int sub_goal_x_coor = 450;
    std::vector<Goal*>* sub_goals = progress->getGoal()->getSubGoals();
    std::string progress_title = "Progress (" + 
                                 std::to_string(progress->getGoal()->getNumSubGoalsDone()) + 
                                 " / " + 
                                 std::to_string(progress->getGoal()->getSubGoals()->size()) +
                                 ")";

    if (goal_progress != nullptr) {
        goal_progress->Destroy();
    }

    goal_progress = new wxGauge(this, wxID_ANY, 100, wxPoint(450, 80), wxSize(300, 20), wxGA_HORIZONTAL);
    goal_progress->SetValue(progress->getCompletePercentage()); // Set progress to 20%

    progress->setYCoor(GOAL_PROGRESS_TITLE_START_Y);
    title->SetLabel(progress_title);

    progress->setYCoor(120);
    while (!sub_goal_checks.empty()) {
        sub_goal_checks.back()->Destroy();
        sub_goal_checks.pop_back();
    }
    for (size_t i = 0; i < sub_goals->size(); i++) {
        sub_goal_checks.push_back(new WGM_CheckBox(progress, 
                                                   this, 
                                                   sub_goals->at(i)->getID(), 
                                                   sub_goals->at(i)->getName().c_str(),
                                                   wxPoint(sub_goal_x_coor, 
                                                   progress->getYCoor()), 
                                                   wxSize(300, 25),
                                                   sub_goals->at(i)->isCompleted()));
        progress->setYCoor(progress->getYCoor() + 35);
    }
}

void WGM_Driver::updateProgressBarGUI(WGM_Goal_Progress* updated_progress)
{
    std::string progress_title = "Progress (" +
                                 std::to_string(updated_progress->getGoal()->getNumSubGoalsDone()) +
                                 " / " +
                                 std::to_string(updated_progress->getGoal()->getSubGoals()->size()) +
                                 ")";
    title->SetLabel(progress_title);
    title->Refresh();

    goal_progress->SetValue(updated_progress->getCompletePercentage());
    goal_progress->Refresh();
}
