#include <stdio.h>
#include <basic/array.h>

/*
 * Scrivete un programma che dato un array di interi positivi, calcoli quante 
 * sono le occorrenze di ogni valore presente nell'array.
 * Notate che i valori dell'array, purché positivi, 
 * possono essere grandi a piacere. 
 * Il programma deve poi stampare quanto trovato, utilizzando il comando:
 * printf("il valore %d appare %d volte\n", A[i], freq[i]);
 * 
 * Per esempio se l'array è [1,1,2,3,1,2] si ottiene il seguente output:
 * il valore 1 appare 3 volte
 * il valore 2 appare 2 volte
 * il valore 3 appare 1 volte
 * 
 */

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.
    
	/*int dim=6;
	int A[6] = {1,2,3,1,1,3};*/
	
    // leggi array e dimensioni
    int dim;
    scanf("%d", &dim);
    
    int A[dim];
    //funzione libreria
    leggi_array(A, dim);
    
    // prosegui
    int freq[dim];

    for(int i=0;i<dim;i++){
        freq[i]=0;
    }
    
    for(int i=0;i<dim;i++){
        if(freq[i]!=-1){
            freq[i]++;
            for(int j=i+1;j<dim;j++){
                if(A[i]==A[j]){
                    freq[i]++;
                    freq[j]=-1;
                }
            }
            printf("il valore %d appare %d volte\n", A[i], freq[i]);
        }
    }

}