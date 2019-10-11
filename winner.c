/* Winner Function to decide who won */

int winner(char player1, char player2)
{

    /* Return 0 if it is a draw
     * Return 1 if player1 wins
     * Return 2 if player2 wins */

    int win = 0;

    if (player1 == player2) {
        win = 0;
    } else if (player1 == 'P' && player2 == 'R') {
        won = 1;
    } else if (player1 == 'R' && player2 == 'S') {
        won = 1;
    } else if (player1 == 'S' && player2 == 'R') {
        won = 2;
    } else if (player1 == 'R' && player2 == 'P') {
        won = 2;
    } else if (player1 == 'P' && player2 == 'S') {
        won = 2;
    } else if (player1 == 'S' && player2 == 'P') {
        won = 1;
    }

    return win;
}
