#include "WGM_Driver.h"

wxBEGIN_EVENT_TABLE(WGM_Driver, wxFrame)
wxEND_EVENT_TABLE()

WGM_Driver::WGM_Driver() : wxFrame(nullptr, wxID_ANY, "Weekly Goal Manager", wxDefaultPosition, wxSize(1000, 800))
{
	CenterOnScreen();
	btns = new wxButton*[nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	nField = new int[nFieldWidth * nFieldHeight];

	for (int i = 0; i < nFieldWidth; i++) {
		for (int j = 0; j < nFieldHeight; j++) {
			btns[j * nFieldWidth + i] = new wxButton(this, 10000 + (j * nFieldWidth + i));
			grid->Add(btns[j * nFieldWidth + i], 1, wxEXPAND | wxALL);
			btns[j * nFieldWidth + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WGM_Driver::onButtonClicked, this);
			nField[j * nFieldWidth + i] = 0;
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
	int x = (event.GetId() - 10000) % nFieldWidth;
	int y = (event.GetId() - 10000) / nFieldWidth;

	if (bFirstClick) {
		int mines = 30;

		while (mines) {
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;

			if (nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y) {
				nField[ry * nFieldWidth + rx] = -1;
				mines--;
			}
		}
		bFirstClick = false;
	}

	btns[y * nFieldWidth + x]->Enable(false);

	// if a player hits mine
	if (nField[y * nFieldWidth + x] == -1) {
		wxMessageBox("BOOOOOM !! - Game Over retard");

		//Reset the game
		for (int i = 0; i < nFieldWidth; i++) {
			for (int j = 0; j < nFieldHeight; j++) {
				nField[j * nFieldWidth + i] = 0;
				btns[j * nFieldWidth + i]->SetLabel("");
				btns[j * nFieldWidth + i]->Enable(true);
			}
		}
	} else {
		//Count neighbor mines
		int mine_count = 0;

		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < nFieldWidth && y + j >= 0 && y + j < nFieldHeight) {
					if (nField[(y + j) * nFieldWidth + (x + i)] == -1) {
						mine_count++;
					}
				}
			}
		}

		//Update button label to show mine count if > 0
		if (mine_count > 0) {
			btns[y * nFieldWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}
	event.Skip();
}