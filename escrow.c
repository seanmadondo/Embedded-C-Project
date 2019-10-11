#include "system.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "display_character.h"

char escrow(char selection)
{
    char opChar = 'X'; // place holder for opponent's character
    char waitChar = 'W';
    ir_uart_init();

    while (opChar != 'S' && opChar != 'R' && opChar != 'P') {
        // pulse
        // wait recieve idle


        if (ir_uart_read_ready_p()) {
            char temp = ir_uart_getc();
            if (temp == 'S' || temp == 'R' || temp == 'P') {
                opChar = temp;

            }
        }

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            ir_uart_putc(selection);
        }
        display_character(waitChar);
    }
    return opChar;
}


