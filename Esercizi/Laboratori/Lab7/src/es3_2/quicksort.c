/*
* Implementare l'algoritmo di quick sort per ordinare un array di interi.
* Quick Sort è un algoritmo divide-et-impera che divide iterativamente
* l'array di input in due sottoarray rispetto ad un elemento detto pivot.
* Tale procedura ricorsiva viene chiamata partition: scelto il pivot si pongono a sinistra
* tutti gli elementi minori e a destra tutti i maggiori formando così i due sottoarray.
* L'operazione viene reiterata ricorsivamente sui sottoarray fino all'ordinamento completo. 
*
* Potete trovare una spiegazione più dettagliata al seguente link: https://ifif.altervista.org/quicksort-come-funziona-esempio/
*
* Stampare l'array ordinato usando la funzione stampa_array in libreria.
*/

#include <stdio.h>
#include <basic/array.h>

int main (void) {

    /* Per velocizzare i vostri test potete usare le seguenti istruzioni*/
    /*int size = 8;
    int A[8] = {5, 8, 7, 2, 4, 0, 9, 6};*/

    /* Da commentare se si usano le istruzioni precedenti, necessarie per
       la consegna su Moodle*/
    int size;
    scanf("%d", &size);
    int A[size];
    leggi_array(A, size);

    // ordina array
    // stampa array

}