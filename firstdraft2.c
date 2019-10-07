#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10
#define LOOP_RATE 500


void display_selection(char selection)
{
    char buff[2];
    buff[1] = '\0'; // Null terminate
    buff[0] = selection;
    tinygl_text(buff);
}

char makeSelection(void)
{
    char selectionList[3] = {'R', 'P', 'S'}; // Rock Paper Scissors
    int index = 0;
    int selected = 0;
    char selectedChar;

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
        display_selection (selectionList[index]);
    }

    return selectedChar;
}

int main(void)
{
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();
    pacer_init (PACER_RATE);
    makeSelection ();
}



