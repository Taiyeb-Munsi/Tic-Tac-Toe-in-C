#include "util.h"

int main() {
    Game g;
    char p = 'X';
    char o = 'O';

    init_game(&g, p, "-t");

    while(1) {
        draw_board(&g);
        player_move(&g);
    }

    return 0;
}
