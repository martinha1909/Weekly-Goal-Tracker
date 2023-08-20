#include "include/WGM_CheckBox.h"
#include "../../../Constants/include/Constants.h"

WGM_CheckBox::WGM_CheckBox(WGM_Goal_Progress* progress,
                           wxFrame* parent,
                           wxWindowID id,
                           const char* label,
                           const wxPoint& pos, 
                           const wxSize& size) : wxCheckBox(parent, id, wxString(label), pos, size) 
{
    this->progress = progress;
    setDefault();
}

WGM_CheckBox::~WGM_CheckBox()
{

}

void WGM_CheckBox::setDefault()
{
    this->SetBackgroundColour(wxColour(255, 255, 255));
    this->Bind(wxEVT_CHECKBOX, &WGM_CheckBox::onChecked, this);
}

void WGM_CheckBox::onChecked(wxCommandEvent& event)
{
    if (this->IsChecked()) {
        this->SetBackgroundColour(CHECK_BOX_CHECKED_BACKGROUND_COLOUR);
        progress->updateProgress(true);
    } else {
        progress->updateProgress(false);
        this->SetBackgroundColour(wxColour(255, 255, 255));
    }
    this->Refresh();
    event.Skip();
}
