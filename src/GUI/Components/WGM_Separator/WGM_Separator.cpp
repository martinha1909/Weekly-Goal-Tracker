#include "include/WGM_Separator.h"
#include <wx/dc.h>

WGM_Separator::WGM_Separator(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
{
	this->Bind(wxEVT_PAINT, &WGM_Separator::OnPaint, this);
}

WGM_Separator::~WGM_Separator()
{

}

void WGM_Separator::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    // Draw the separator line at a custom location
    wxPoint startPt(50, 100); // Starting point of the line
    wxPoint endPt(350, 100); // Ending point of the line

    dc.SetPen(wxPen(wxColour(0, 0, 0), 2)); // Black pen with thickness 2
    dc.DrawLine(startPt, endPt); // Draw the line
}