/** @file display_character.c
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief Display functions
 */

/* File contains all required display functions
 * Displays characters via use of tinygl module */

#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "../fonts/font5x7_1.h"
#include "timer.h"

// Update display and advance message.
void update_screen(void)
{
    tinygl_update();
}

void clear_screen(void)
{
    int ticks = 20000;
    tinygl_clear();
    update_screen();
    timer_init();
    timer_wait(ticks);
}

//Display Text on LED (scrolls with feature from tinygl)
void display_text(char* text)
{
    clear_screen();
    tinygl_text(text);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    update_screen();
}

//Function used to display final result after winner is identified
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

//Display character on LED
void display_character(char character)
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
    update_screen();
}

// Function to reset game, prompts user to 'push to reset'
void reset_game(void)
{
    display_text("PUSH TO RESET\0");
    navswitch_update();
    while (navswitch_push_event_p(NAVSWITCH_PUSH) == 0) {
        pacer_wait();
        update_screen();
        navswitch_update();
    }
}
