#include <stdio.h>

/*
 * Scrivete un programma che definisca una costante ALTEZZA=x e disegni un triangolo rettangolo di base ed 
 * altezza x, utilizzando il carattere #, senza spazi né prima né dopo.  
 * In particolare il programma stamperà # una volta per la prima riga, # due volte per la seconda riga, 
 * fino a stampare # x volte per la x-esima riga. 
 *
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * #
 * ##
 * ###
 * 
 * Per la consegna utilizzare ALTEZZA=13
 */
 
 #define ALTEZZA 13

int main () {
    for(int i=0;i<ALTEZZA;i++){
        for(int j=0;j<i+1;j++)printf("#");
        printf("\n");
    }
}