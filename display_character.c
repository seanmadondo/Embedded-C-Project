#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "../fonts/font5x7_1.h"

void update_screen(void)
{
    tinygl_update();
}

void display_text(char* text)
{
    tinygl_text(text);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    update_screen();
}

void display_result(char* result)
{
    display_text(result);
    navswitch_update();
    while (navswitch_push_event_p(NAVSWITCH_PUSH) == 0) {
        pacer_wait();
        update_screen();
        navswitch_update();
    }
}

void display_character(char character)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
    update_screen();
}

void reset_game(void)
{
    display_text("PUSH TO RESET");
    navswitch_update();
    while (navswitch_push_event_p(NAVSWITCH_PUSH) == 0) {
        pacer_wait();
        update_screen();
        navswitch_update();
    }
}
