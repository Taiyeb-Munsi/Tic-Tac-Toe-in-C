#ifndef GAME_H
#define GAME_H
#define SIZE 3

// Game objects

typedef enum { TWO_PLAYER, EASY, MEDIUM, HARD } Difficulty;

typedef struct {
    char board[SIZE][SIZE];
    char player, opponent;
    Difficulty difficulty;
} Game;

// Function declarations

void init_game(Game*, char, Difficulty);
void draw_board(Game*);
void player_move(Game*, char);
void opponent_move(Game*);
int check_board(Game*);

#endif
