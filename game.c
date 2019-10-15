/** @file game.c
 * @author Julian Topp (JAT191), Sean Madondo (SMA297)
 * @date 14/10/2019
 * @brief Main loop for game
 */

/* game.c is the games caller function
 * Runs in while loop until terminated.
 * Calls function for self selection and to receive oponent selection
 * Display Result (Draw, Win, Lose)
 * Option to continue playing/reset game via reset() call
 * Authors: Julian Topp, Sean Madondo */

#include "screen.h"
#include "escrow.h"
#include "selection.h"
#include "winner.h"
#include "initialiser.h"


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
