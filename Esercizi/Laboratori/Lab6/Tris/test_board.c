#include <stdio.h>
#include <assert.h>
#include "board.h"

void test_mossa_ammissibile() {
    char board[9]={'X','X',' ','O','X','0',' ','O','O'};
    effettua_mossa(board, 0, 2, 'X');
}


void test_board_vincente() {
    char board[9]={'X','X','X','O','X','0',' ','O','O'};
    assert(board_vincente(board));
}


void test_partita_terminata() {
    char board[9]={'X','X','X','O','X','0',' ','O','O'};
    assert(partita_terminata(board));
}

