#pragma once

#include "wx/wx.h"
#include "../../WGM_Driver/include/WGM_Driver.h"

WGM_Driver* WGM_Driver::instance = nullptr;

class WGM_App : public wxApp
{
private:
	WGM_Driver* m_frame1 = nullptr;
public:
	WGM_App();
	~WGM_App();

	virtual bool OnInit();
};

