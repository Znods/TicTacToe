#include <stdio.h>
#include <stdlib.h>

/* TicTacToe */

void playBoard(char *A){
    printf("%c | %c | %c\n", A[0], A[1], A[2]);
    printf("%c | %c | %c\n", A[3], A[4], A[5]);
    printf("%c | %c | %c\n", A[6], A[7], A[8]);
}

void markBoard(char *A, int player, char playerc){
    if(player == 1 && A[0] == NULL){
        A[0] = playerc;
    } else if(player == 2 && A[1] == NULL){
        A[1] = playerc;
    } else if(player == 3 && A[2] == NULL){
        A[2] = playerc;
    } else if(player == 4 && A[3] == NULL){
        A[3] = playerc;
    } else if(player == 5 && A[4] == NULL){
        A[4] = playerc;
    } else if(player == 6 && A[5] == NULL){
        A[5] = playerc;
    } else if(player == 7 && A[6] == NULL){
        A[6] = playerc;
    } else if(player == 8 && A[7] == NULL){
        A[7] = playerc;
    } else if(player == 9 && A[8] == NULL){
        A[8] = playerc;
    } else {
        printf("'X' or 'O' is already here!\n");
    }
}

void checkWin(char *A, char playerc){
    if(A[0] == A[1] && A[1] == A[2] && A[1] != NULL){        // Rows
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[3] == A[4] && A[4] == A[5] && A[3] != NULL){ // Rows
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[6] == A[7] && A[7] == A[8] && A[6] != NULL){ // Rows
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[0] == A[3] && A[3] == A[6] && A[0] != NULL){ // Colums
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[1] == A[4] && A[4] == A[7] && A[1] != NULL){ // Colums
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[2] == A[5] && A[5] == A[8] && A[2] != NULL){ // Colums
        printf("Player %C Wins!\n", playerc);
        exit(1); 
    } else if(A[0] == A[4] && A[4] == A[8] && A[0] != NULL){ // Diagonal
        printf("Player %C Wins!\n", playerc);
        exit(1);
    } else if(A[2] == A[4] && A[4] == A[6] && A[2] != NULL){ // Diagonal
        printf("Player %C Wins!\n", playerc);
        exit(1);
    }
}

int main(){
    char playerc;
    int player, rounds, mark;
    char *A = (char*)malloc(3*3 * sizeof(char));
    do{
        playerc = (playerc = mark) ? 'X' : 'O';
        playBoard(A);
        printf("Player %c: ", playerc);
        scanf("%d", &player);
        if(mark == 1){        // Player X
            markBoard(A, player, playerc);
            mark--;
        } else if(mark == 0){ // Player O
            markBoard(A, player, playerc);
            mark++;
        }
        checkWin(A, playerc);
        rounds++;
    }while(rounds != 9);
    printf("\nGame Over...\n");
    free(A);
    return 0;
}
