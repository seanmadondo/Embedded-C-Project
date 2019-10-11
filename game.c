#include "display_character.h"
#include "escrow.h"
#include "selection.h"
#include "winner.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10
#define LOOP_RATE 500

int main(void)
{
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();
    pacer_init (PACER_RATE);
    
    while (1) {
        int result = 0;
        while (result == 0) {
            char selection = makeSelection();
            char opponentSelection = escrow(selection);
            result = winner(selection, opponentSelection);
            if (result == 0) {
                display_character('D');
            } else if (result == 1) {
                display_character('W');
            } else {
                display_character('L');
            }
        };
    }
}
