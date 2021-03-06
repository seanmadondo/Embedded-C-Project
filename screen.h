/** @file display_character.h
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief Display functions
 */

#ifndef SCREEN_H_
#define SCREEN_H_

/* Prompt user to reset game using navswtich*/
void reset_game (void);

// Update display and advance message.
void update_screen(void);

void clear_screen(void);

// Initialise Screen
void screen_init(void);

// Update text to display
void display_text(char* text);

// Display result of game
void display_result(char* result);

// Update character to display
void display_character(char character);

#endif
