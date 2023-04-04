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


int main()
{
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
    	
    // stampa array scambiati
	for (int i = 0; i < size_array1; i += 1)
 		printf("[%d] -> A1: %d\n", i, array1[i]);
 	for (int i = 0; i < size_array2; i += 1)
 		printf("[%d] -> A2: %d\n", i, array2[i]);

    return 0;
}
