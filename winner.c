/** @file winner.c
 * @author Julian Topp, Sean Madondo
 * @date 14/0/2019
 * @brief Decide winner
 */

/* Function to decide winner of game
 * Takes two characters, follows truth table to decide winner
 * Return 0 if it is a draw
 * Return 1 if player1 wins
 * Return 2 if player2 wins */

int winner(char player1, char player2)
{
    int win = 0;

    if (player1 == player2) {
        win = 0; //if it is a draw
    } else if (player1 == 'P' && player2 == 'R') {
        win = 1;
    } else if (player1 == 'R' && player2 == 'S') {
        win = 1;
    } else if (player1 == 'S' && player2 == 'R') {
        win = 2;
    } else if (player1 == 'R' && player2 == 'P') {
        win = 2;
    } else if (player1 == 'P' && player2 == 'S') {
        win = 2;
    } else if (player1 == 'S' && player2 == 'P') {
        win = 1;
    }

    return win;
}


