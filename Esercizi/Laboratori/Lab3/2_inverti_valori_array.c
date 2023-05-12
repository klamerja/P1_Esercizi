#include <stdio.h>

/*
 * Scrivete una funzione che, dato un array di interi, inverta (riordini) i valori dell'array
 * scambiando ogni valore con il suo corrispondente partendo dal fondo. 
 * Ad esempio l'inverso dell'array [1,2,4] è [4,2,1]. 
 * Il programma deve stampare l'array aggiornato utilizzando
 * la funzione stampa_array() che vi forniamo noi.
 * La funzione leggi_array è quella vista nell'esercizio 1.1 del laboratorio 3.
 *
 * Per esempio se l'array è [1,2,3,4] si ottiene il seguente output: 
 * [ 4 3 2 1 ]
 *
 *
*/

void inverti(int *A, int dim);
void stampa_array(int *A, int dim);
void leggi_array(int *X, int dim);


int main(void)
{
    
    // Per testare più velocemente il vostro algoritmo
    // potete usare l'array fornito sotto (modificandolo 
    //  secondo le vostre necessità) invece di leggerlo 
    //  da input con scanf. Quando siete pronti a 
    //  consegnare potete ricommentare le seguenti righe.
     
    /* 
    const int dim = 10;    
    int A[] = {1,2,3,4,5,6,7,8,9,10}; 
    */
     
    //  Leggi la dimensione dell' array e i valori da tastiera. 
    //  Decommentare le seguenti istruzioni per la consegna. 
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);
    
    inverti(A, dim);
    stampa_array(A, dim);

    return 0;
}

void inverti(int *A, int dim){
    for(int i=0;i<dim/2;i++){
        int tmp=A[i];
        A[i]=A[(dim-i)-1];
        A[(dim-i)-1]=tmp;
    }
}

void stampa_array(int *A, int dim) {

    printf("[");
    for (int i = 0; i < dim; i+=1)
        printf(" %d",A[i]);
    printf(" ]\n");

}

void leggi_array(int *X, int dim) {
    /* 
        Legge da tastiera dim interi e li carica 
        sull'array X. Si assume che X sia stato 
        dichiarato come int X[dim] nella funzione
        chiamante. 
    */
    for(int i=0; i<dim; i+=1) {
        scanf("%d", &X[i]);
    }
}