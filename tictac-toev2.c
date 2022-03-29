#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

/* TicTacToe */

void board(char *map);
void set(int turn, char xo, char *map);
void checkwin(char *map, char xo);

struct boardinfo{
    char map[9];
    char xo;
    int turn;
    bool check:1;
    unsigned int i:4;
};

bool running = true;

int main(){
    struct boardinfo *info = (struct boardinfo *)malloc(1 * sizeof(struct boardinfo));
    for(info->i = 0; info->i < 9; info->i++){ 
        info->map[info->i] = 'a'+info->i; 
    } 
    do{
        board(info->map);
        info->xo = info->check == true ? 'X' : 'O';  
        printf("\n\x1b[1;33m%c\x1b[0m Turn: ", info->xo);
        scanf("%d", &info->turn);
        while(info->turn > 9){
            printf("Please Enter Valid Number! 1-9\n");
            printf("\n\x1b[1;33m%c\x1b[0m Turn: ", info->xo);
            scanf("%d", &info->turn);
        }
        system("clear");
        set(info->turn, info->xo, info->map);
        checkwin(info->map, info->xo);
        info->check--; // Switch Turn
    } while(running == true);
    free(info);
    return 0;
}

void board(char *map){
    for(int i = 0; i < 9; i+=3){
        printf("\x1b[1;34m%c\x1b[0m |\x1b[1;34m %c\x1b[0m |\x1b[1;34m %c\x1b[0m\n", map[i], map[i+1], map[i+2]);
    }
}

void set(int turn, char xo, char *map){
    if(map[turn-1] == 'X'){
        printf("'\x1b[1;33mX\x1b[0m'\x1b[1;31m Already Here!\x1b[0m\n\n");
    } else if(map[turn-1] == 'O'){
        printf("'\x1b[1;33mO\x1b[0m'\x1b[1;31m Already Here!\x1b[0m\n\n");
    } else {
        map[turn-1] = xo;
    }
}

void checkwin(char *map, char xo){
    if(map[0] == map[1] && map[1] == map[2]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[3] == map[4] && map[4] == map[5]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[6] == map[7] && map[7] == map[8]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[0] == map[3] && map[3] == map[6]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[1] == map[4] && map[4] == map[7]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[2] == map[5] && map[5] == map[8]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[0] == map[4] && map[4] == map[8]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    } else if(map[2] == map[4] && map[4] == map[6]){
        printf("\x1b[1;32m%c Wins!\x1b[0m\n", xo);
        running = false;
    }
}