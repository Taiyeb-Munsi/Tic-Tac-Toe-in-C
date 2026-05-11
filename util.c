#include "util.h"
#include "game.h"

int move(Game *g, int pos, char p) {
    if(g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] != ' ')
        return 0;
    else {
        g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] = p;
        return 1;
    }
}

int check_win(Game *g, char a) {
    for(int i=0;i<SIZE;++i) {
        if((g->board[i][0] == a && g->board[i][1] == a && g->board[i][2] == a) ||
            (g->board[0][i] == a && g->board[1][i] == a && g->board[2][i] == a)) {
            return 1;
        }
    }

    if((g->board[0][0] == a && g->board[1][1] == a && g->board[2][2] == a) ||
        (g->board[0][2] == a && g->board[1][1] == a && g->board[2][0] == a)) {
        return 1;
    }

    return 0;
}

int check_draw(Game *g) {
    for(int i=0;i<SIZE;++i) {
        for(int j=0;j<SIZE;++j) {
            if(g->board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}
