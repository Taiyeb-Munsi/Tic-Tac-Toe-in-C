#include "game.h"
#include "util.h"
#include "ai.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Ai functions


// Game logic

void init_game(Game *g, char p, Difficulty diff) {
    memset(g->board, ' ', sizeof(g->board));

    g->player = p;

    g->opponent = (g->player == 'X') ? 'O' : 'X';

    g->difficulty = diff;

    srand(time(NULL));
}

void draw_board(Game *g) {
    printf("\n");
    for(int i=0;i<SIZE;++i) {
        printf(" %c | %c | %c \n", g->board[i][0], g->board[i][1], g->board[i][2]);
        if(i < SIZE - 1)
            printf("---|---|---\n");
    }
}

void player_move(Game *g, char p) {
    int temp;
    
    printf("Enter a position to move for %c (1-9) : ", p);
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
            if(!move(g, temp, g->player)) {
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
        player_move(g, g->opponent);
    } else if(g->difficulty == EASY) {
        ai_easy(g);
    } else if(g->difficulty == MEDIUM) {
        ai_medium(g);
    }
}

int check_board(Game *g) {
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

    
    if(check_draw(g)) {
        draw_board(g);
        printf("It's a draw\n");
        return 0;
    }

    return 1;
}
