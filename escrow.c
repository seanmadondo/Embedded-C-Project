#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

char escrow(char selection)
{
    char opChar; // place holder for opponent's character
    char waitChar;
    ir_uart_init();
    tinygl_init(500);
    while (opChar != 'S' && opChar != 'R' && opChar != 'P') {
        // pulse
        // wait recieve idle
        tinygl_update();

        if (ir_uart_read_ready_p()) {
            char temp = ir_uart_getc();
            if (temp == 'S' || temp == 'R' || temp == 'P') {
                opChar = temp;

            }
        }

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            ir_uart_putc(selection);
        }
        display_character('W');
    }
}


