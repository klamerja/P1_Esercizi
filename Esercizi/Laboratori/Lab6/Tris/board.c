#include <stdio.h>
#include "board.h"

int board_vincente(char board[]) {
    //Verifica righe
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')return 1;
    if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ')return 1;
    if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ')return 1;

    //Verifica colonne
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')return 1;
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')return 1;
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')return 1;

    //Verifica diagonali
    if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ')return 1;
    if(board[2]==board[4] && board[4]==board[6] && board[0]!=' ')return 1;

    //Se tabella non vincente
    return 0;
}


void effettua_mossa(char board[], int x, int y, char simbolo_giocatore) {
    int position=x*BOARD_SIZE+y;
    int mossa_valida=(position>=0 && position<BOARD_SIZE && board[position]==' ')?1:0;
    if(mossa_valida)board[position]=simbolo_giocatore;
    else printf("Mossa non valida\n");
}


int partita_terminata(char board[]){
    if(board_vincente(board))return 1;
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i]==' ')return 0;
    }
    return 1;
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

