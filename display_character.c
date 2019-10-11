#include "system.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define LOOP_RATE 500

void display_character(char character)
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}
