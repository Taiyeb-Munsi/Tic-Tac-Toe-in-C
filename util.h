#ifndef UTIL_H
#define UTIL_H
#define SIZE 3

typedef struct {
    char board[SIZE][SIZE];
    char player, opponent;
} Game;

void init_game(Game*, char, char);
void draw_board(Game*);
void player_move(Game*);

#endif
