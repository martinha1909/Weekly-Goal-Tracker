#include "include/WGM_App.h"

wxIMPLEMENT_APP(WGM_App);

WGM_App::WGM_App()
{

}

WGM_App::~WGM_App()
{

}

bool WGM_App::OnInit()
{
	m_frame1 = new WGM_Driver();
	m_frame1->Show();

	return true;
}

//#include <wx/wx.h>
//
//class MyFrame : public wxFrame {
//public:
//    MyFrame(const wxString& title)
//        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
//        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
//
//        // Create a wxStaticText object
//        staticText = new wxStaticText(this, wxID_ANY, "Click a button to change the label",
//            wxDefaultPosition, wxDefaultSize,
//            wxALIGN_CENTER);
//
//        // Add the wxStaticText object to the sizer
//        sizer->Add(staticText, 1, wxEXPAND | wxALL, 20);
//
//        // Create buttons to change the label
//        wxButton* button1 = new wxButton(this, wxID_ANY, "Change Label 1");
//        wxButton* button2 = new wxButton(this, wxID_ANY, "Change Label 2");
//
//        // Bind the button click events
//        button1->Bind(wxEVT_BUTTON, &MyFrame::OnChangeLabel1, this);
//        button2->Bind(wxEVT_BUTTON, &MyFrame::OnChangeLabel2, this);
//
//        // Add the buttons to the sizer
//        sizer->Add(button1, 0, wxALIGN_CENTER | wxBOTTOM, 10);
//        sizer->Add(button2, 0, wxALIGN_CENTER);
//
//        SetSizer(sizer);
//    }
//
//    void OnChangeLabel1(wxCommandEvent& event) {
//        staticText->SetLabel("Fitness");
//    }
//
//    void OnChangeLabel2(wxCommandEvent& event) {
//        staticText->SetLabel("Leetcode");
//    }
//
//private:
//    wxStaticText* staticText;
//};
//
//class MyApp : public wxApp {
//public:
//    virtual bool OnInit() {
//        MyFrame* frame = new MyFrame("Dynamic Label Example");
//        frame->Show(true);
//        return true;
//    }
//};
//
//wxIMPLEMENT_APP(MyApp);