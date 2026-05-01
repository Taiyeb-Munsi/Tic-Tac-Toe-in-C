#include "util.h"
#include <string.h>
#include <stdio.h>

void move(Game*, int, char);
char place(Game*, int);

void init_game(Game *g, char p, char o) {
    memset(g->board, ' ', sizeof(g->board));

    g->opponent = o;
    g->player = p;
}

void draw_board(Game *g) {
    for(int i=0;i<SIZE;++i) {
        for(int j=0;j<SIZE;++j) {
            printf(" %c ", g->board[i][j]);
        }
        printf("\n");
    }
}

void move(Game *g, int pos, char ch) {
    g->board[(pos - 1) / SIZE][(pos - 1) % SIZE] = ch;
}

char place(Game *g, int pos) {
    return g->board[(pos - 1) / SIZE][(pos - 1) % SIZE];
}

void player_move(Game *g) {
    int temp;
    
    printf("Enter a position (1-9) : ");
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

        move(g, temp, g->player);
        break;
    }
}
