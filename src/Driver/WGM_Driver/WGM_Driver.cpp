#include "include/WGM_Driver.h"
#include <wx/statline.h>
#include "../../GUI/Components/WGM_Goal_Button/include/WGM_Goal_Button.h"
#include "../../GUI/Components/WGM_Separator/include/WGM_Separator.h"
#include "../../GUI/Components/WGM_TextCtrl/include/WGM_TextCtrl.h"
#include "../../Constants/include/Constants.h"
#include "../Goal/include/DefaultGoal.h"
#include "../Goal/include/CustomGoal.h"

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

    goal_panel = new wxPanel(this);
    wxStaticLine* separatorLine = new wxStaticLine(goal_panel, wxID_ANY, wxDefaultPosition, wxSize(1200, 1), wxLI_HORIZONTAL);

    wxBoxSizer* line_sizer = new wxBoxSizer(wxVERTICAL);
    line_sizer->AddStretchSpacer(); // Stretch spacer to push the line to the bottom
    line_sizer->Add(separatorLine, 0, wxEXPAND); // Add the static line
    goal_panel->SetSizer(line_sizer);

    main_sizer = new wxBoxSizer(wxVERTICAL);
    top_sizer = new wxBoxSizer(wxHORIZONTAL);
    main_sizer->Add(top_sizer, 0, wxEXPAND);
    center_sizer = new wxBoxSizer(wxHORIZONTAL);
    center_sizer->AddStretchSpacer();
    center_sizer->Add(btn_panel, 0, wxALIGN_CENTER);
    center_sizer->AddStretchSpacer();

    top_sizer->Add(center_sizer, 1, wxEXPAND);

    // Add the line_panel to the main_sizer
    main_sizer->Add(goal_panel, 0, wxEXPAND);

    this->SetSizer(main_sizer);
    
    //Bind to event queue so that when a button is removed, wxWdiget will use its asynchronous event queue to remove a button,
    //which will not cause unexpected behaviour with the GUI
    this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WGM_Driver::onRemoveGoal, this, WGM_GOAL_BUTTON_REMOVE);
    title = new WGM_StaticText(this, wxID_ANY, "", wxPoint(320, 80), wxDefaultSize, wxALIGN_CENTER);
}

WGM_Driver::~WGM_Driver()
{
    
}

WGM_Driver* WGM_Driver::getInstance()
{
    if (instance == nullptr) {
        instance = new WGM_Driver();
    }
    return instance;
}

void WGM_Driver::setUpDefaultButtons()
{
    Goal* fitness = new DefaultGoal("Fitness", WGM_NEXT_ID());
    Goal* lc = new DefaultGoal("LeetCode", WGM_NEXT_ID());
    Goal* finance = new CustomGoal("Finance", WGM_NEXT_ID());
    Goal* monthly_sub_goal = new CustomGoal("Monthly Spending", WGM_NEXT_ID(), 2200, "Enter expense");
    Goal* income_goal = new CustomGoal("Monthly Income", WGM_NEXT_ID(), 5000, "Enter income");

    finance->addSubGoal(monthly_sub_goal);
    finance->addSubGoal(income_goal);

    fitness->addSubGoal(new DefaultGoal("gym", WGM_NEXT_ID()));

    lc->addSubGoal(new DefaultGoal("Easy", WGM_NEXT_ID()));
    lc->addSubGoal(new DefaultGoal("Medium", WGM_NEXT_ID()));
    lc->addSubGoal(new DefaultGoal("Hard", WGM_NEXT_ID()));

    goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), fitness, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
    goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), lc, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
    goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), finance, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));

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
        goals.push_back(new WGM_Goal_Button(this, btn_panel, WGM_NEXT_ID(), new_goal, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE));
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

void WGM_Driver::resetUI()
{
    while (!sub_goal_checks.empty()) {
        sub_goal_checks.back()->Destroy();
        sub_goal_checks.pop_back();
    }

    while (!custom_goal_sliders.empty()) {
        custom_goal_sliders.back()->Destroy();
        custom_goal_sliders.pop_back();
    }

    while (!custom_goal_slider_values.empty()) {
        custom_goal_slider_values.back()->Destroy();
        custom_goal_slider_values.pop_back();
    }

    while (!custom_sub_goal_titles.empty()) {
        custom_sub_goal_titles.back()->Destroy();
        custom_sub_goal_titles.pop_back();
    }

    while (!custom_sub_goal_progress.empty()) {
        custom_sub_goal_progress.back()->Destroy();
        custom_sub_goal_progress.pop_back();
    }
}

void WGM_Driver::updateGoalGUI(WGM_Goal_Progress* progress)
{
    int sub_goal_x_coor = 450;
    WGM_StaticText* sub_goal_header = nullptr;

    resetUI();
    current_goal = progress->getGoal();

    progress->setYCoor(150);
    sub_goal_header = new WGM_StaticText(this, wxID_ANY, "Sub Goals", wxPoint(320, progress->getYCoor()), wxDefaultSize, wxALIGN_CENTER);
    sub_goal_header->SetForegroundColour(wxColour(255, 255, 255));

    if (dynamic_cast<DefaultGoal*>(current_goal) != nullptr) {
        DefaultGoal* curr_goal = dynamic_cast<DefaultGoal*>(current_goal);
        std::vector<Goal*>* sub_goals = curr_goal->getSubGoals();
        std::string progress_title = progress->getGoal()->getName() + 
                                     " (" +
                                     std::to_string(curr_goal->getNumSubGoalsDone()) +
                                     " / " + 
                                     std::to_string(sub_goals->size()) +
                                     ")";
 
        if (goal_progress != nullptr) {
            goal_progress->Destroy();
        }

        goal_progress = new wxGauge(this, wxID_ANY, 100, wxPoint(450, 80), wxSize(300, 20), wxGA_HORIZONTAL);
        goal_progress->SetValue(progress->getCompletePercentage());

        title->SetLabel(progress_title);

        progress->setYCoor(180);
        for (size_t i = 0; i < sub_goals->size(); i++) {
            if (dynamic_cast<DefaultGoal*>(sub_goals->at(i)) != nullptr) {
                sub_goal_checks.push_back(new WGM_CheckBox(progress, 
                                                           this, 
                                                           sub_goals->at(i)->getID(), 
                                                           sub_goals->at(i)->getName().c_str(),
                                                           wxPoint(sub_goal_x_coor, 
                                                           progress->getYCoor()), 
                                                           wxSize(230, 25),
                                                           sub_goals->at(i)->isCompleted()));
                progress->setYCoor(progress->getYCoor() + 50);
            }
        }
    } else if (dynamic_cast<CustomGoal*>(current_goal) != nullptr) {
        int sub_goal_progress_x_coor = 450;
        int sub_goal_progress_title_x_coor = 320;
        CustomGoal* curr_goal = dynamic_cast<CustomGoal*>(current_goal);
        std::vector<Goal*>* sub_goals = curr_goal->getSubGoals();
        std::string progress_title = progress->getGoal()->getName() +
            " (" +
            std::to_string(curr_goal->getNumSubGoalsDone()) +
            " / " +
            std::to_string(curr_goal->getSubGoals()->size()) +
            ")";

        if (goal_progress != nullptr) {
            goal_progress->Destroy();
        }

        goal_progress = new wxGauge(this, wxID_ANY, 100, wxPoint(450, 80), wxSize(300, 20), wxGA_HORIZONTAL);
        goal_progress->SetValue(curr_goal->getSubGoalCompletionProgress());

        title->SetLabel(progress_title);

        progress->setYCoor(180);
        for (size_t i = 0; i < sub_goals->size(); i++) {
            if (dynamic_cast<CustomGoal*>(sub_goals->at(i)) != nullptr) {
                CustomGoal* curr_sub_goal = dynamic_cast<CustomGoal*>(sub_goals->at(i));
                wxString tooltip = "Automatically updates " + std::to_string(SLIDER_AUTO_SUBMIT_TIMER / 1000) + " seconds";
                const int auto_submit_timer_id = wxNewId();
                wxTimer* auto_submit_timer = new wxTimer(this, auto_submit_timer_id);

                /* sub goal titles */
                custom_sub_goal_titles.push_back(new WGM_StaticText(this, 
                                                                    wxID_ANY, 
                                                                    curr_sub_goal->getName().c_str(), 
                                                                    wxPoint(sub_goal_progress_title_x_coor, progress->getYCoor()), 
                                                                    wxDefaultSize, 
                                                                    wxALIGN_CENTER));
                custom_sub_goal_progress.push_back(new wxGauge(this, 
                                                               wxID_ANY, 
                                                               100, 
                                                               wxPoint(sub_goal_progress_x_coor, progress->getYCoor()), 
                                                               wxSize(230, 20), 
                                                               wxGA_HORIZONTAL));
                custom_sub_goal_progress.back()->SetValue(curr_sub_goal->getCompletionProgress());
                progress->setYCoor(progress->getYCoor() + 35);
                /*sub goal subtitles */
                custom_sub_goal_titles.push_back(new WGM_StaticText(this,
                                                                    WGM_NEXT_ID(),
                                                                    curr_sub_goal->getSubTitle().c_str(),
                                                                    wxPoint(sub_goal_progress_title_x_coor, progress->getYCoor()),
                                                                    wxDefaultSize,
                                                                    wxALIGN_CENTER));
                custom_goal_slider_values.push_back(new WGM_TextCtrl(this, 
                                                                     WGM_NEXT_ID(), 
                                                                     wxString(std::to_string(curr_sub_goal->getProgress()).c_str()),
                                                                     wxPoint(sub_goal_x_coor + 100, progress->getYCoor() + 3), 
                                                                     wxSize(50, 20), 
                                                                     wxTE_CENTRE | wxNO_BORDER | wxTE_PROCESS_ENTER));
                custom_goal_slider_values.back()->Bind(wxEVT_TEXT_ENTER, &WGM_Driver::onSliderTextBoxEnter, this);

                custom_goal_sliders.push_back(new wxSlider(this, 
                                                           WGM_NEXT_ID(), 
                                                           curr_sub_goal->getProgress(), //current value
                                                           0, //min value
                                                           curr_sub_goal->getTotalGoal() * SLIDER_VALUE_MULTIPLIER_CAP, //max value
                                                           wxPoint(sub_goal_progress_x_coor, progress->getYCoor()), 
                                                           wxSize(100, 20), 
                                                           wxSL_HORIZONTAL));
                custom_goal_sliders.back()->SetToolTip(tooltip);
                custom_goal_sliders.back()->Bind(wxEVT_SCROLL_THUMBTRACK, &WGM_Driver::onSliderUpdate, this);
                custom_goal_sliders.back()->Bind(wxEVT_SCROLL_CHANGED, &WGM_Driver::onSliderUpdate, this);

                auto_submit_timer_ids.push_back(auto_submit_timer_id);
                auto_submit_timers.push_back(auto_submit_timer);

                this->Bind(wxEVT_TIMER, &WGM_Driver::onSliderAutoSubmit, this, auto_submit_timer_id);

                progress->setYCoor(progress->getYCoor() + 50);
            }
        }
    }
}

void WGM_Driver::updateCustomGoalProgressUI(int custom_sub_goal_id, int new_progress)
{
    if (current_goal != nullptr && dynamic_cast<CustomGoal*>(current_goal) != nullptr) {
        CustomGoal* curr_goal = dynamic_cast<CustomGoal*>(current_goal);
        CustomGoal* curr_sub_goal = dynamic_cast<CustomGoal*>(curr_goal->getSubGoals()->at(custom_sub_goal_id));

        if (curr_sub_goal != nullptr) {
            curr_sub_goal->setProgress(new_progress);
            custom_sub_goal_progress[custom_sub_goal_id]->SetValue(curr_sub_goal->getCompletionProgress());
            custom_sub_goal_progress[custom_sub_goal_id]->Refresh();
            if (curr_sub_goal->getCompletionProgress() == 100) {
                curr_sub_goal->setComplete(true);
                curr_goal->setNumSubGoalsDone(curr_goal->getNumSubGoalsDone() + 1);
                goal_progress->SetValue(curr_goal->getSubGoalCompletionProgress());
                goal_progress->Refresh();

                if (curr_goal->getSubGoalCompletionProgress() >= 100) {
                    curr_goal->setComplete(true);
                }

                title->SetLabel(curr_goal->getName() +
                                " (" +
                                std::to_string(curr_goal->getNumSubGoalsDone()) +
                                " / " +
                                std::to_string(curr_goal->getSubGoals()->size()) +
                                ")");
            }
        }
    }
}

inline int WGM_Driver::getSliderIndexFromTimer(int timer_id)
{
    for (size_t i = 0; i < auto_submit_timer_ids.size(); ++i) {
        if (timer_id == auto_submit_timer_ids[i]) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void WGM_Driver::onSliderAutoSubmit(wxTimerEvent& event)
{
    int slider_id = getSliderIndexFromTimer(event.GetId());
    if (slider_id != -1) {
        if (current_goal != nullptr && dynamic_cast<CustomGoal*>(current_goal) != nullptr) {
            CustomGoal* curr_goal = dynamic_cast<CustomGoal*>(current_goal);
            CustomGoal* curr_sub_goal = dynamic_cast<CustomGoal*>(curr_goal->getSubGoals()->at(slider_id));
            updateCustomGoalProgressUI(slider_id, curr_sub_goal->getProgress() + custom_goal_sliders[slider_id]->GetValue());
        }
        auto_submit_timers[slider_id]->Stop();
    }
}

void WGM_Driver::onSliderTextBoxEnter(wxCommandEvent& event)
{
    for (size_t i = 0; i < custom_goal_slider_values.size(); i++) {
        if (event.GetEventObject() == custom_goal_slider_values[i]) {
            CustomGoal* curr_goal = dynamic_cast<CustomGoal*>(current_goal);
            CustomGoal* curr_sub_goal = dynamic_cast<CustomGoal*>(curr_goal->getSubGoals()->at(i));
            wxString text = custom_goal_slider_values[i]->GetValue();
            int value;

            if (text.ToInt(&value)) {
                updateCustomGoalProgressUI(i, curr_sub_goal->getProgress() + value);
            }
            break;
        }
    }
}

void WGM_Driver::onSliderUpdate(wxScrollEvent& event)
{
    for (size_t i = 0; i < custom_goal_sliders.size(); i++) {
        if (event.GetEventObject() == custom_goal_sliders[i]) {
            int value = custom_goal_sliders[i]->GetValue();

            custom_goal_slider_values[i]->SetValue(wxString::Format("%d", value));
            custom_goal_slider_values[i]->Refresh();
            auto_submit_timers[i]->Start(SLIDER_AUTO_SUBMIT_TIMER);

            break;
        }
    }
}

void WGM_Driver::updateProgressBarGUI(WGM_Goal_Progress* updated_progress)
{
    if (dynamic_cast<DefaultGoal*>(updated_progress->getGoal()) != nullptr) {
        DefaultGoal* curr_goal = dynamic_cast<DefaultGoal*>(updated_progress->getGoal());
        std::string progress_title = curr_goal->getName() +
                                     " (" +
                                     std::to_string(curr_goal->getNumSubGoalsDone()) +
                                     " / " +
                                     std::to_string(curr_goal->getSubGoals()->size()) +
                                     ")";

        title->SetLabel(progress_title);
        title->Refresh();

        goal_progress->SetValue(updated_progress->getCompletePercentage());
        goal_progress->Refresh();
    }
}
