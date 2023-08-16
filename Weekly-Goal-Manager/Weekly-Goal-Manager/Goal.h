#pragma once

#include "Constants.h"

class Goal : public wxFrame
{
private:

public:
	Goal();
	~Goal();

	void onButtonClicked(wxCommandEvent& event);
};

