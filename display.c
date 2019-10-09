#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500

void display_character(char character)
{
    tinygl_init();
