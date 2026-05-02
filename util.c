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

int check_win(Game *g, char a) {
    for(int i=0;i<SIZE;++i) {
        if((g->board[i][0] == a && g->board[i][1] == a && g->board[i][2] == a) ||
            (g->board[0][i] == a && g->board[1][i] == a && g->board[2][i] == a)) {
            draw_board(g);
            printf("%c WON\n", a);
            return 1;
        }
    }

    if((g->board[0][0] == a && g->board[1][1] == a && g->board[2][2] == a) ||
        (g->board[0][2] == a && g->board[1][1] == a && g->board[2][0] == a)) {
        draw_board(g);
        printf("%c WON\n", a);
        return 1;
    }

    return 0;
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
        printf(" %c | %c | %c \n", g->board[i][0], g->board[i][1], g->board[i][2]);
        if(i < SIZE - 1)
            printf("---|---|---\n");
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

int check_board(Game *g) {
    int flag = 1;

    if(check_win(g, g->player)) {
        return 0;
    }

    if(check_win(g, g->opponent)) {
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
