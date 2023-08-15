#pragma once

#include "wx/wx.h"

class Goal : public wxFrame
{
private:

public:
	Goal();
	~Goal();

	void onButtonClicked(wxCommandEvent& event);
};

