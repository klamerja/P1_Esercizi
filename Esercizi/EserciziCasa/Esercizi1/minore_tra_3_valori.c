#include <stdio.h>

/*
 Date 3 variabili intere: x,y,z, stampare il valore minore delle tre. 
 */

int main() {
    //Dichiarazione variabili
    int x=5, y=2, z=7;

    //Elaborazione ed output
    if(x<y && x<z){
        printf("Il minore dei tre valori è %d\n", x);
    }else if(y<x){
        printf("Il minore dei tre valori è %d\n", y);
    }else{
        printf("Il minore dei tre valori è %d\n", z);
    }
}
