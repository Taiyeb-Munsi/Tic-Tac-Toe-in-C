#include "util.h"
#include <string.h>

int main() {
    Game g;
    char p = 'X';
    char* temp_test = "-e";
    Difficulty d;

    if(!strcmp(temp_test, "-t")) {
        d = TWO_PLAYER;
    } else if(!strcmp(temp_test, "-e")) {
        d = EASY;
    } else if(!strcmp(temp_test, "-m")) {
        d = MEDIUM;
    } else if(!strcmp(temp_test, "-h")) {
        d = HARD;
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
