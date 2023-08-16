#include "Goal.h"

Goal::Goal() : wxFrame(nullptr, wxID_ANY, "Add Goal", wxDefaultPosition, wxSize(500, 500))
{
    this->CenterOnScreen();
    this->SetBackgroundColour(APP_BACKGROUND_COLOUR);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Create a panel to hold the text boxes
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create vertical sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);

    // Add a flexible space to center-align the text boxes vertically
    panelSizer->AddStretchSpacer(1);

    // Add three text boxes
    for (int i = 0; i < 3; i++)
    {
        wxFont titleFont(wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Roboto").Bold());
        wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, wxString::Format("TextBox %d", i + 1));
        titleText->SetForegroundColour(wxColour(51, 51, 51));
        titleText->SetFont(titleFont);
        panelSizer->Add(titleText, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

        wxTextCtrl* textBox = new wxTextCtrl(panel, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize);
        panelSizer->Add(textBox, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    }

    // Add another flexible space to center-align the text boxes vertically
    panelSizer->AddStretchSpacer(1);

    // Set the panel's sizer
    panel->SetSizer(panelSizer);

    // Add the panel to the main sizer
    mainSizer->Add(panel, 1, wxEXPAND);
    
    this->SetSizer(mainSizer);
}

Goal::~Goal()
{

}

void Goal::onButtonClicked(wxCommandEvent& event)
{
    event.Skip();
}