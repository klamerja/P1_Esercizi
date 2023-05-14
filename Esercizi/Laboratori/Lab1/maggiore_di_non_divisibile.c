#include <stdio.h>
#include <stdbool.h>

/*
 * Data una costante intera SOGLIA, stampare il più piccolo numero
 * maggiore di SOGLIA che non sia divisibile per i seguenti numeri: 2, 3, 5. 
 * Es. se SOGLIA = 4, il programma stampa 
 * 7
 * 
 * Per la consegna, utilizzare SOGLIA = 63
 * 
 */

#define SOGLIA 63

int main () {
    //Dichiarazione variabili 
    int i=SOGLIA+1;
    bool isFound=false;
    int value;

    //Elaborazione
    while(!isFound){
        if((i%2)!=0 && (i%3)!=0 && (i%5)!=0){
            printf("%d\n", i);
            isFound=true;
        }
        i++;
    }
}