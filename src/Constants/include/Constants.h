#pragma once

#include <wx/wx.h>

#define APP_BACKGROUND_COLOUR		   wxColour(0, 128, 128)
#define APP_TEXT_BOX_FONT			   wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Roboto").Bold()
#define APP_BUTTON_FONT				   wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Raleway")
#define DEFAULT_ITEM_BACKGROUND_COLOUR wxColour(0, 0, 0)
#define DEFAULT_ITEM_FOREGROUND_COLOUR wxColour(255, 255, 255)

/* Size */
#define MAIN_APP_FRAME_SIZE			   wxSize(1000, 800)
#define ADD_GOAL_FRAME_SIZE			   wxSize(300, 300)

/* IDs */
#define ADD_GOAL_MENU_ID			   10001