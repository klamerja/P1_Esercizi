#include <stdio.h>
#include <basic/array.h>

/*
* Scrivete la funzione "scambiaArray" che scambia i
* valori di due array di numeri interi. Notate che i 
* due array possono essere di dimensione diversa. 
* Inserite il vostro codice, ovvero l'implementazione
* della funzione (e di ogni altra funzione accessoria)
* e la sua chiamata nel main, nel file 
* che accompagna la consegna (senza modificare altre
* parti del file). Usare l'aritmetica dei puntatori.  
*
* La funzione riceve come argomenti la loro dimensione 
* e gli elementi dei due array.
*
*/


// funzione scambiaArray per scambiare gli array (da scrivere)
void scambia_array(int *A1, int *A2, int *dim1, int *dim2, int max);
void scambia_interi(int *el1, int *el2);

int main(){
    // Per testare più velocemente il vostro algoritmo potete 
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 3 righe seguenti.
    
	/*int size_array1 = 3, size_array2 = 5;
    int array1[5] = {1,1,1};
	int array2[5] = {2,2,2,2,2};*/
	
	// leggere dimensioni array 
    int size_array1, size_array2;
	scanf("%d %d", &size_array1, &size_array2);

	// leggere array
	int max = (size_array1 > size_array2)?size_array1 : size_array2;
	int array1[max], array2[max];
	
	//funzione libreria
	leggi_array(array1, size_array1);
	leggi_array(array2, size_array2);
    
	// scambia array
	scambia_array(array1, array2, &size_array1, &size_array2, max);
    	
    // stampa array scambiati
	for (int i = 0; i < size_array1; i += 1)
 		printf("[%d] -> A1: %d\n", i, array1[i]);
 	for (int i = 0; i < size_array2; i += 1)
 		printf("[%d] -> A2: %d\n", i, array2[i]);

    return 0;
}

/*
 * PRE: due array da scambiare, riferimenti alle dimensioni di entrambi gli array e copia della dimensione massima
 * POST: scambio degli elementi dell'array
*/
void scambia_array(int *A1, int *A2, int *dim1, int *dim2, int max){
	for(int i=0;i<max;i++){
		scambia_interi((A1+i), (A2+i)); //Scambio gli elementi dell'array
	}
	scambia_interi(dim1, dim2);
}

/*
 * PRE: due riferimenti ad elementi di tipo intero
 * POST: scambio dei due elementi
*/
void scambia_interi(int *el1, int *el2){
	int tmp=*el1;
	*el1=*el2;
	*el2=tmp;
}
