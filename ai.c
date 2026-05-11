#include "ai.h"
#include "util.h"

#include <stdlib.h>

void ai_easy(Game* g) {
    int temp = rand() % 9 + 1;
    while(!move(g, temp, g->opponent)) {
        temp = rand() % 9 + 1;
    }
}

void ai_medium(Game* g) {
    for(int i=1;i<=SIZE*SIZE;++i) {
        Game copy = *g;
        if(move(&copy, i, g->opponent) && check_win(&copy, g->opponent)) {
            move(g, i, g->opponent);
            return;
        }
    }

    for(int i=1;i<=SIZE*SIZE;++i) {
        Game copy = *g;
        if(move(&copy, i, g->player) && check_win(&copy, g->player)) {
            move(g, i, g->opponent);
            return;
        }
    }

    ai_easy(g);
}

