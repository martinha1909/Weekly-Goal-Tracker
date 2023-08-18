#pragma once

#include <wx/wx.h>

#define APP_BACKGROUND_COLOUR		   wxColour(20, 33, 61)
#define APP_TEXT_BOX_FONT			   wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Roboto").Bold()
#define APP_BUTTON_FONT				   wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Raleway").Bold()
#define BUTTON_BACKGROUND_COLOUR	   wxColour(252, 163, 17)
#define BUTTON_FOREGROUND_COLOUR	   wxColour(0, 0, 0)
#define TEXT_BOX_BACKGROUND_COLOUR	   wxColour(20, 33, 61)
#define TEXT_BOX_FOREGROUND_COLOUR	   wxColour(252, 163, 17)

/* Size */
#define MAIN_APP_FRAME_SIZE			   wxSize(1000, 800)
#define ADD_GOAL_FRAME_SIZE			   wxSize(300, 300)

/* IDs */
#define ADD_GOAL_MENU_ID			   10001