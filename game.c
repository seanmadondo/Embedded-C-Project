#include "display.h"
#include "escrow.h"
#include "selection.h"
#include "winner.h"
#include "system.h"

int main(void)
{
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
        }
    }
}
