/** @file initialiser.c
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief Initialise Modules
 */

/* Function for initialisation of all required modules
 * Called with "initiliser()" */

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "ir_uart.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"

#define LOOP_RATE 500
#define PACER_RATE 500
#define MESSAGE_RATE 15

void initialise_all(void)
{
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    navswitch_init();
    pacer_init(PACER_RATE);
    ir_uart_init();
}

