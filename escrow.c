/** @file escrow.c
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief user to user communication using IR
 */

/* Fuction to receive opponets character via IR
 * After user makes selection, user is prompted "Press to send"
 * Function returns opponent's character */

#include "system.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "display_character.h"
#include "pacer.h"

char escrow(char selection)
{
    char opChar = 'X'; // place holder for opponent's character
    char* loopMessage = "PRESS TO SEND\0";
    int recieved = 0;
    int sent = 0;
    display_text(loopMessage);

    while (recieved == 0 || sent == 0) {
        // pulse
        // wait recieve idle
        pacer_wait ();
        navswitch_update();
        update_screen();

        if (ir_uart_read_ready_p()) {
            char temp = ir_uart_getc();
            if (temp == 'S' || temp == 'R' || temp == 'P') {
                opChar = temp;
                recieved = 1;

            }
        }

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            ir_uart_putc(selection);
            sent = 1;
        }

    }
    return opChar;
}


