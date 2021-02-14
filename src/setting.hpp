#ifndef SETTING_HPP
#define SETTING_HPP

/* ---------------------------- COLORS --------------------------- */
#define FONT_COLOR {0, 0, 0, 255}

/* --------------------------- FORMATS --------------------------- */
#define IMAGE_FORMAT        ".png"
#define TEXT_FORMAT         ".txt"

/* -------------------------- CONSTANTS -------------------------- */
#define MAX_ROOMS_NUMBER    10


/* ---------------------------- SIZES ---------------------------- */
#define SCREEN_WIDTH        900
#define SCREEN_HEIGHT       600

#define BUTTON_WIDTH        SCREEN_WIDTH/MAX_ROOMS_NUMBER
#define BUTTON_HEIGHT       BUTTON_WIDTH
#define BUTTON_X            0
#define BUTTON_Y            SCREEN_HEIGHT - BUTTON_HEIGHT

#define TASK_WIDTH          300
#define TASK_HEIGHT         350
#define TASK_X              SCREEN_WIDTH  - (TASK_WIDTH + 20)
#define TASK_Y              10

#define TEXT_DISTANCE       10
#define TEXT_INDENT         20
#define TEXT_X              TASK_X + TEXT_INDENT
#define TEXT_Y              TASK_Y + TEXT_INDENT

#define BUTTON_INDENT       6
#define PREV_BUTTON_WIDTH   TASK_WIDTH/2 - BUTTON_INDENT/2
#define PREV_BUTTON_HEIGHT  35
#define PREV_BUTTON_X       TASK_X
#define PREV_BUTTON_Y       TASK_Y + TASK_HEIGHT + BUTTON_INDENT

#define NEXT_BUTTON_WIDTH   PREV_BUTTON_WIDTH
#define NEXT_BUTTON_HEIGHT  PREV_BUTTON_HEIGHT
#define NEXT_BUTTON_X       PREV_BUTTON_X + PREV_BUTTON_WIDTH + BUTTON_INDENT
#define NEXT_BUTTON_Y       PREV_BUTTON_Y

#define KID_WIDTH           200
#define KID_HEIGHT          350
#define KID_X               30
#define KID_Y               BUTTON_WIDTH + 10

#define KID_NAME_INDENT     10
#define KID_NAME_X          KID_X
#define KID_NAME_Y          KID_Y - KID_NAME_INDENT

#define GIFT_WIDTH          BUTTON_WIDTH
#define GIFT_HEIGHT         BUTTON_HEIGHT
#define GIFT_X              BUTTON_X
#define GIFT_Y              BUTTON_Y



#endif // SETTING_HPP
