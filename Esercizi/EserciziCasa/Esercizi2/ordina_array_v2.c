#include <stdio.h>
/*
* Scrivete un programma che ordini un array di numeri interi in ordine
* crescente.
*
* Il programma deve stampare l'array ordinato al termine dell'esecuzione.
* Utilizzare: printf("Array[%d] : %d\n", i, array[i]);
*
*/

//Prototipi
void leggi_array(int *A, int dim);
void scambia(int *A, unsigned int i, unsigned int j);
unsigned int indice_minimo_array(int *A, int len);
void riordina_array();

//Main
int main(void){
    //Dimensione array
    unsigned int dim;
    scanf("%u", &dim);

    //Creazione array
    int A[dim];
    leggi_array(A, dim);

    //Elaborazione
    riordina_array(A, dim);

    //Output
    for(int i=0; i<dim; i+=1)printf("Array[%d] : %d\n", i, A[i]);
}

//Funzioni
/*
    PRE: Array vuoto e dimensione dell'array
    POST: array inizializzato
*/
void leggi_array(int *A, int dim){
    for(int i=0;i<dim;i++){
        scanf("%d", &A[i]);
    }
}

/*
    PRE: array e dimensione dell'array
    POST: array ordinato (ascendente)
*/
void riordina_array(int *A, int dim){
    for(int i=0;i<dim;i++){
        scambia(A, i, i+indice_minimo_array(&A[i], dim-i));
    }
}

/*
    PRE: array, indice del primo elemento e del secondo elemento
    POST: array dove alla posizione del primo elemento è contenuto il secondo elemento e viceversa
*/
void scambia(int *A, unsigned int i, unsigned int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

/*
    PRE: array e dimensione dell'array
    POST: indice del valore minimo nell'array
*/
unsigned int indice_minimo_array(int *A, int len){
    int min=*A;
    int min_index=0;
    for(int i=0;i<len;i++){
        if(A[i]<min){
            min=A[i];
            min_index=i;
        }
    }
    return min_index;
}

