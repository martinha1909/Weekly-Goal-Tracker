#include "include/WGM_CheckBox.h"
#include "../../../Constants/include/Constants.h"

WGM_CheckBox::WGM_CheckBox(WGM_Goal_Progress* progress,
                           wxFrame* parent,
                           wxWindowID id,
                           const char* label,
                           const wxPoint& pos, 
                           const wxSize& size,
                           bool checked) : wxCheckBox(parent, id, wxString(label), pos, size) 
{
    this->progress = progress;
    setDefault(checked);
}

WGM_CheckBox::~WGM_CheckBox()
{

}

void WGM_CheckBox::setDefault(bool checked)
{
    if (!checked) {
        this->SetBackgroundColour(wxColour(255, 255, 255));
    } else {
        this->SetBackgroundColour(wxColour(CHECK_BOX_CHECKED_BACKGROUND_COLOUR));
        this->SetValue(checked);
    }
    this->Bind(wxEVT_CHECKBOX, &WGM_CheckBox::onChecked, this);
}

void WGM_CheckBox::onChecked(wxCommandEvent& event)
{
    int goal_id = event.GetId();

    if (this->IsChecked()) {
        this->SetBackgroundColour(CHECK_BOX_CHECKED_BACKGROUND_COLOUR);
        progress->updateProgress(true, goal_id);
    } else {
        progress->updateProgress(false, goal_id);
        this->SetBackgroundColour(wxColour(255, 255, 255));
    }
    this->Refresh();
    event.Skip();
}
