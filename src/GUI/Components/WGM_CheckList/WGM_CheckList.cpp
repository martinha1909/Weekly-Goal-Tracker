#include "include/WGM_CheckList.h"

WGM_CheckList::WGM_CheckList(wxFrame* parent,
                             wxWindowID id,
                             const wxPoint& pos, 
                             const wxSize& size) : wxCheckListBox(parent, id, pos, size) 
{
    setDefault();
}

WGM_CheckList::WGM_CheckList(wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxColour& colour) : wxCheckListBox(parent, id, pos, size)
{
    this->SetBackgroundColour(colour);
}

WGM_CheckList::~WGM_CheckList()
{

}

void WGM_CheckList::setDefault()
{
    this->SetBackgroundColour(wxColour(255, 255, 255));
}