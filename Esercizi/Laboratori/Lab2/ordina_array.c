#include <stdio.h>

/*
* Scrivete un programma che ordini un array di numeri interi in ordine
* crescente.
*
* Il programma deve stampare l'array ordinato al termine dell'esecuzione.
* Utilizzare: printf("Array[%d] : %d\n", i, array[i]);
*
*/

int main () {
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }
    
    //codice
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(array[i]>array[j]){
                int tmp=array[j];
                array[j]=array[i];
                array[i]=tmp;
            }
        }
    }

    for(int i=0; i<N;i++){
        printf("Array[%d] : %d\n", i, array[i]);
    }
}
