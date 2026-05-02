#include "util.h"
#include <string.h>
#include <stdio.h>

// Utility

void move(Game *g, int pos) {
    g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] = g->current;
    g->current = (g->current == g->player) ? g->opponent : g->player;
}

char place(Game *g, int pos) {
    return g->board[(pos - 1) / SIZE][(pos - 1) % SIZE];
}

// Game logic

void init_game(Game *g, char p, char* diff) {
    memset(g->board, ' ', sizeof(g->board));

    g->player = p;
    g->current = p;

    g->opponent = (g->player == 'X') ? 'O' : 'X';

    g->difficulty = diff;
}

void draw_board(Game *g) {
    for(int i=0;i<SIZE;++i) {
        for(int j=0;j<SIZE;++j) {
            printf(" %c ", g->board[i][j]);
        }
        printf("\n");
    }
}

void player_move(Game *g) {
    int temp;
    
    printf("Enter a position to move for %c (1-9) : ", g->current);
    while(1) {
        scanf("%d",&temp);
        
        if(temp < 1 || temp > 9) {
            printf("Invalid input, enter again : ");
            continue;
        } else {
            if (place(g, temp)  != ' ') {
                printf("Occupied, enter again : ");
                continue;
            }
        }

        move(g, temp);
        break;
    }
}

void opponent_move(Game *g) {
    if(!strcmp(g->difficulty, "-t")) {
        draw_board(g);
        player_move(g);
    }
}
