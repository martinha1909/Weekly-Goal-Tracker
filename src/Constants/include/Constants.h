#pragma once

#include <wx/wx.h>


#define APP_BACKGROUND_COLOUR				wxColour(20, 33, 61)
#define APP_TEXT_BOX_FONT					wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Roboto").Bold()
#define APP_BUTTON_FONT						wxFontInfo(10).Family(wxFONTFAMILY_DEFAULT).FaceName("Raleway").Bold()
#define BUTTON_BACKGROUND_COLOUR			wxColour(252, 163, 17)
#define BUTTON_FOREGROUND_COLOUR			wxColour(0, 0, 0)
#define BUTTON_HOVER_BACKGROUND_COLOUR      wxColour(135, 206, 235)
#define BUTTON_SELECTED_BACKGROUND_COLOUR   BUTTON_HOVER_BACKGROUND_COLOUR
#define TEXT_BOX_BACKGROUND_COLOUR			wxColour(20, 33, 61)
#define TEXT_BOX_FOREGROUND_COLOUR			wxColour(252, 163, 17)
#define CHECK_BOX_CHECKED_BACKGROUND_COLOUR wxColour(0, 200, 0)
#define GOAL_PROGRESS_TITLE_START_X		    380
#define GOAL_PROGRESS_TITLE_START_Y			80
#define GOAL_PROGRESS_TITLE_START_POS		wxPoint(GOAL_PROGRESS_TITLE_START_X, GOAL_PROGRESS_TITLE_START_Y)

/* Size */
#define MAIN_APP_FRAME_SIZE					wxSize(1200, 1000)
#define ADD_GOAL_FRAME_SIZE					wxSize(300, 300)

/* IDs */
#define ADD_GOAL_MENU_ID					10001
#define WGM_UNIQUE_ID_START                 10002

/* miscellaneous */
#define SLIDER_VALUE_MULTIPLIER_CAP         5 //Cap for max value of a slider
#define SLIDER_AUTO_SUBMIT_TIMER            2000 // 2 seconds auto submit

static int __cur_id = WGM_UNIQUE_ID_START;

constexpr int WGM_NEXT_ID() {
    int ret = __cur_id;
    __cur_id++;
    return ret;
}