#include <stdio.h>

/*
* Scrivete un programma che trovi il minimo ed il massimo
* di una lista di interi non vuota.
*
* Il programma deve stampare i valori trovati. Utilizzare:
* printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
* printf("valore massimo: array[%d] -> %d", max_indice, array[max_indice]);
*
*/

int main (void) {

    /* Per comodità potete usare il codice sottostante 
    invece che leggere gli input da tastiera, è da commentare prima 
    di consegnare */ 
    /*const int N = 10;
    int array[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};*/

    /* da commentare se si usano le istruzioni sopra */

    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }

    //codice per trovare massimo e minimo
    int min_indice=0, max_indice=0;
    
    for(int i=1;i<N;i++){
        if(array[i]>array[max_indice])max_indice=i;
        if(array[i]<array[min_indice])min_indice=i;
    }

    printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
    printf("valore massimo: array[%d] -> %d", max_indice, array[max_indice]);
}