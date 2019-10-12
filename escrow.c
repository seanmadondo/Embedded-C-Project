#include "system.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "display_character.h"
#include "pacer.h"

#define PACER_RATE 500

char escrow(char selection)
{
    char opChar = 'X'; // place holder for opponent's character
    char waitChar = 'W';
    int recieved = 0;
    int sent = 0;
    ir_uart_init();
    pacer_init (PACER_RATE);
    display_character(waitChar);
    
    while (recieved == 0 || sent == 0) {
        // pulse
        // wait recieve idle
        pacer_wait ();
        navswitch_update();
        updateChar();

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


