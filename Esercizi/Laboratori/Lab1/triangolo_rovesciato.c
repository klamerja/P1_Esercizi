#include <stdio.h>
/*
 * Stampare una piramide rovesciata utilizzando il carattere #,  
 * in modo che la punta della piramide sia in basso e la base in alto. 
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * 
 * #####
 *  ###
 *   #
 * 
 * Per la consegna utilizzare ALTEZZA=6. Prestate attenzione al numero di spazi.
 * 
 */

#define ALTEZZA 13

int main () {
    const int larghezza=2*ALTEZZA-1;

    for(int i=0;i<ALTEZZA;i++){
        //Il numero degli spazi è equivalente a i
        for(int j=0;j<larghezza;j++){
            if(j>=i && j<larghezza-i)printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}