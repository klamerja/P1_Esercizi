#include <stdio.h>
#include "board.h"

int board_vincente(char board[]) {
for(int i=0;i<BOARD_LATO;i++){
}
}


void effettua_mossa(char board[], int x, int y, char simbolo_giocatore) {
    //TODO
}


int partita_terminata(char board[]){
    //TODO
}


void print_board(char board[]) {
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}


void reset_board(char board[]) {
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
     */
    for(int i=0; i<BOARD_SIZE; i+=1)
        board[i] = CASELLA_VUOTA;
}

