#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

char makeSelection(void)
{
    char selectionList[3] = {'R', 'P', 'S'}; // Rock Paper Scissors
    int index = 0;
    int selected = 0;
    char selectedChar;
    navswitch_init ();


    // use navswtich to incriment and decrement array index
    while(selected == 0)
    {
        pacer_wait ();
        tinygl_update ();
        navswitch_update();

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
