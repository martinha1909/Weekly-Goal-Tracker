#pragma once

#include <wx/wx.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>
#include "../../../WGM_Goal_Progress/include/WGM_Goal_Progress.h"

class WGM_Goal_Progress;

class WGM_CheckBox : public wxCheckBox {
private:
    WGM_Goal_Progress* progress;

    void setDefault(bool checked);
public:
    WGM_CheckBox(WGM_Goal_Progress* progress, 
                 wxFrame* parent, 
                 wxWindowID id, 
                 const char* label, 
                 const wxPoint& pos, 
                 const wxSize& size,
                 bool checked);
    ~WGM_CheckBox();
    void onChecked(wxCommandEvent& event);
};

