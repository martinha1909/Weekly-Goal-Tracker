#include "include/WGM_App.h"


WGM_App::WGM_App()
{

}

WGM_App::~WGM_App()
{

}

bool WGM_App::OnInit()
{
	m_frame1 = WGM_Driver::getInstance();
	m_frame1->Show();

	return true;
}

wxIMPLEMENT_APP(WGM_App);