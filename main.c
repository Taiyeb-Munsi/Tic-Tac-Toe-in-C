#include "util.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
    Game g;
    char p = 'X';
    Difficulty d = MEDIUM;

    int opt;
    while((opt = getopt(argc, argv, "temh")) != -1) {
        switch (opt) {
            case 't' :
                d = TWO_PLAYER;
                break;
            case 'e':
                d = EASY;
                break;
            case 'm':
                d = MEDIUM;
                break;
            case 'h':
                d = HARD;
        }
    }

    if (optind < argc) {
        p = argv[optind][0];
    }
    

    init_game(&g, p, d);

    while(1) {
        draw_board(&g);
        player_move(&g);
        if(!check_board(&g)) break;
        opponent_move(&g);
        if(!check_board(&g)) break;
    }

    return 0;
}
