#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"






void update_screen(void)
{
    tinygl_update();
}

void display_text(char* text)
{
    tinygl_text(text);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    update_screen();
}


void display_character(char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
    update_screen();
}
