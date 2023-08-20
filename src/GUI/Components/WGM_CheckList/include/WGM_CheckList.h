#pragma once

#include <wx/wx.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>

class WGM_CheckList : public wxCheckListBox {
private:
    void setDefault();
public:
    WGM_CheckList(wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    WGM_CheckList(wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxColour& colour);
    ~WGM_CheckList();
};

