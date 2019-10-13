/* game.c is the games caller function
 * Runs in while loop until terminated. */

#include "display_character.h"
#include "escrow.h"
#include "selection.h"
#include "winner.h"
#include "initialiser.h"
#include "../fonts/font5x7_1.h"

int main(void)
{
    initialise_all();

    while (1) {
        int result = 0;
        while (result == 0) {
            char selection = makeSelection();
            char opponentSelection = escrow(selection);
            result = winner(selection, opponentSelection);
            if (result == 0) {
                display_result("DRAW");
            } else if (result == 1) {
                display_result("WIN");
            } else {
                display_result("LOSE");
            }
        }
        reset_game();
    }
}
