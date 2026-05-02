#ifndef UTIL_H
#define UTIL_H
#define SIZE 3

// Game objects

typedef struct {
    char board[SIZE][SIZE];
    char player, opponent, current;
    char* difficulty;
} Game;

// Function declarations

void init_game(Game*, char, char*);
void draw_board(Game*);
void player_move(Game*);
void opponent_move(Game*);
int check_board(Game*);

#endif
