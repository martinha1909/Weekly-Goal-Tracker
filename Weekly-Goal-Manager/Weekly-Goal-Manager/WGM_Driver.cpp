#include "WGM_Driver.h"

wxBEGIN_EVENT_TABLE(WGM_Driver, wxFrame)
EVT_BUTTON(10001, onButtonClicked)
wxEND_EVENT_TABLE()

WGM_Driver::WGM_Driver() : wxFrame(nullptr, wxID_ANY, "Weekly Goal Manager", wxDefaultPosition, wxSize(1000, 800))
{
	CenterOnScreen();
	btns = new wxButton*[nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	for (int i = 0; i < nFieldWidth; i++) {
		for (int j = 0; j < nFieldHeight; j++) {
			btns[j * nFieldWidth + i] = new wxButton(this, 10000 + (j * nFieldWidth + i));
			grid->Add(btns[j * nFieldWidth + i], 1, wxEXPAND | wxALL);
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

WGM_Driver::~WGM_Driver()
{

}

void WGM_Driver::onButtonClicked(wxCommandEvent& event)
{
	event.Skip();
}