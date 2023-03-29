#include <stdio.h>

/*
* Scrivete un programma che ordini un array di numeri interi in ordine
* crescente.
*
* Il programma deve stampare l'array ordinato al termine dell'esecuzione.
* Utilizzare: printf("Array[%d] : %d\n", i, array[i]);
*
*/

int main (void) {

    /* 
        Per la consegna, utilizzare il codice seguente per leggere l'input.  
    */
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }

    for(int i=0;i<N;i+=1){
        int indice = i;
        int min = array[i];
        for(int j=i; j<N;j+=1){
            if(array[j]<min){
                indice = j, min = array[j];
            }
        }
        //Errore trovato
        /*
            Se la sequenza ha come minimo se stesso, lo sposta alla posizione 0, cambiare l'inizializzazione di indice da 0 ad i
        */
        int temp = array[i];
        array[i] = array[indice];
        array[indice]= temp;
    }

    for(int i=0; i<N; i+=1)printf("Array[%d] : %d\n", i, array[i]);

}
