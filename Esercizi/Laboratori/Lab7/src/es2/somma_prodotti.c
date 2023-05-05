#include <stdio.h>
#include <basic/array.h>

/*
    Scrivere una funzione che, dato un array A di dim interi, calcoli la somma dei prodotti tra il primo e l'ultimo elemento dell'array, tra il secondo ed il penultimo ecc...
    Per esempio, dato l'array [1,2,3,4,5,6] la funzione calcola 1*6+2*5+3*4. Se l'array è dispari, l'elemento centrale va moltiplicato con sè stesso. 
    Il tipo restituito dalla funzione è void, però deve essere possibile stampare nel main la somma calcolata. 
*/

//Prototipi
void calc_somma(int* A, int dim, int* somma);

//Main block
int main (void) {
    //Personal test    
    // int dim = 7;
    // int A[] = {1,2,3,4,5,6,7};
    
    //Moodle Test
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);

    //Esecuzione
    int somma; 
    calc_somma(A, dim, &somma);

    //Output
    printf("%d\n", somma);
}

//Funzioni
void calc_somma(int* A, int dim, int* somma){
    *somma=0;
    int is_dispari=dim%2;
    for(int i=0;i<dim/2+is_dispari;i++){
        *somma+= *(A+i) * *(A+dim-1-i);
    }
}