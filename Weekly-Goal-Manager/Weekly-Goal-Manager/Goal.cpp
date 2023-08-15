#include "Goal.h"

Goal::Goal() : wxFrame(nullptr, wxID_ANY, "Add Goal", wxDefaultPosition, wxSize(1000, 800))
{
    // Create the main sizer for the frame
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Create a text box for entering the goal name
    wxTextCtrl* goalTextBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

    // Add the text box to the main sizer
    mainSizer->Add(goalTextBox, 0, wxALL | wxEXPAND, 10);

    // Create a button to confirm and add the goal
    wxButton* addButton = new wxButton(this, wxID_ANY, "Add Goal");
    addButton->Bind(wxEVT_BUTTON, &Goal::onButtonClicked, this); // Bind the event handler

    // Add the button to the main sizer
    mainSizer->Add(addButton, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    // Set the main sizer for the frame
    SetSizerAndFit(mainSizer);
}

Goal::~Goal()
{

}

void Goal::onButtonClicked(wxCommandEvent& event)
{
    event.Skip();
}