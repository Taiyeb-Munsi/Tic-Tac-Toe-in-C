#include "util.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Utility

int move(Game *g, int pos, char p) {
    if(g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] != ' ')
        return 0;
    else {
        g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] = p;
        g->current = (g->current == g->player) ? g->opponent : g->player;
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

// Ai functions

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
            move(g, i, g->current);
            return;
        }
    }

    for(int i=1;i<=SIZE*SIZE;++i) {
        Game copy = *g;
        if(move(&copy, i, g->player) && check_win(&copy, g->player)) {
            move(g, i, g->current);
            return;
        }
    }

    ai_easy(g);
}

// Game logic

void init_game(Game *g, char p, Difficulty diff) {
    memset(g->board, ' ', sizeof(g->board));

    g->player = p;
    g->current = p;

    g->opponent = (g->player == 'X') ? 'O' : 'X';

    g->difficulty = diff;

    srand(time(NULL));
}

void draw_board(Game *g) {
    for(int i=0;i<SIZE;++i) {
        printf(" %c | %c | %c \n", g->board[i][0], g->board[i][1], g->board[i][2]);
        if(i < SIZE - 1)
            printf("---|---|---\n");
    }
}

void player_move(Game *g) {
    int temp;
    
    printf("Enter a position to move for %c (1-9) : ", g->current);
    while(1) {
        if(scanf("%d", &temp) != 1) {
            printf("Invalid input, enter again : ");
            while(getchar() != '\n');
            continue;
        }
        
        if(temp < 1 || temp > 9) {
            printf("Invalid input, enter again : ");
            continue;
        } else {
            if(!move(g, temp, g->current)) {
                printf("Occupied, try again : ");
                continue;
            } else {
                break;
            }
        }
    }
}

void opponent_move(Game *g) {
    if(g->difficulty == TWO_PLAYER) {
        draw_board(g);
        player_move(g);
    } else if(g->difficulty == EASY) {
        ai_easy(g);
    } else if(g->difficulty == MEDIUM) {
        ai_medium(g);
    }
}

int check_board(Game *g) {
    int flag = 1;

    if(check_win(g, g->player)) {
        draw_board(g);
        printf("%c WON\n", g->player);
        return 0;
    }

    if(check_win(g, g->opponent)) {
        draw_board(g);
        printf("%c WON\n", g->opponent);
        return 0;
    }

    for(int i=0;i<SIZE;++i) {
        for(int j=0;j<SIZE;++j) {
            if(g->board[i][j] == ' ') {
                flag = 0;
                break;
            }
        }
    }

    if(flag) {
        draw_board(g);
        printf("It's a draw\n");
        return 0;
    }

    return 1;
}
