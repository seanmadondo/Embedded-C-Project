/** @file selection.c
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief Make user selection
 */

/* Function to make user selection using call to navswitch push event
 * Returns the selected char */

#include "navswitch.h"
#include "screen.h"
#include "pacer.h"

char makeSelection(void)
{
    char selectionList[3] = {'R', 'P', 'S'}; // Rock Paper Scissors
    int index = 0;
    int selected = 0;
    char selectedChar;

    // use navswtich to incriment and decrement array index
    while(selected == 0) {
        pacer_wait();

        navswitch_update();
        //updateChar();

        // Navswitch up
        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            if (index < 2) {
                index += 1;
            }
        }
        // Navswitch down
        if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            if (index > 0) {
                index -= 1;
            }
        }
        // Navswitch press
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            selected = 1;
            selectedChar = selectionList[index];
        }
        display_character (selectionList[index]);
    }

    return selectedChar;
}
