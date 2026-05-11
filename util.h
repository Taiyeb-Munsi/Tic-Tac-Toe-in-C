#ifndef UTIL_H
#define UTIL_H

#include "game.h"

int move(Game*, int, char);
int check_win(Game*, char);
int check_draw(Game*);

#endif
