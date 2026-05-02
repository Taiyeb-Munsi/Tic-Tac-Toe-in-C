#include "util.h"

int main() {
    Game g;
    char p = 'X';

    init_game(&g, p, "-t");

    while(1) {
        draw_board(&g);
        player_move(&g);
        if(!check_board(&g)) break;
        opponent_move(&g);
        if(!check_board(&g)) break;
    }

    return 0;
}
