#pragma once

#include "../../WGM_Button/include/WGM_Button.h"
#include "../../../../Driver/Goal/include/Goal.h"

class WGM_Goal_Button : public WGM_Button
{
private:
	Goal* goal;

public:
	WGM_Goal_Button(wxPanel* panel, const wxWindowID id, const char* name);
	WGM_Goal_Button(wxPanel* panel, const wxWindowID id, Goal* goal);
	WGM_Goal_Button(wxPanel* panel,
					const wxWindowID id,
					const char* name,
					const wxPoint& loc,
					const wxSize& size,
					const wxBorder border);
	WGM_Goal_Button(wxPanel* panel,
					const wxWindowID id,
					Goal* goal,
					const wxPoint& loc,
					const wxSize& size,
					const wxBorder border);
	~WGM_Goal_Button();
};

