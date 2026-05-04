#include "util.h"

int main(int argc, char* argv[]) {
    Game g;
    Difficulty d = MEDIUM;

    if (argc > 1) {
        switch (argv[1][0]) {
            case 't': d = TWO_PLAYER; break;
            case 'e': d = EASY; break;
            case 'm': d = MEDIUM; break;
            case 'h': d = HARD; break;
        }
    }

    init_game(&g, 'X', d);

    while(1) {
        draw_board(&g);
        player_move(&g);
        if(!check_board(&g)) break;
        opponent_move(&g);
        if(!check_board(&g)) break;
    }

    return 0;
}
