#include<stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * 
 * Per questa l'implementazione ci rifaremo letteralmente alla
 * la definizione sopra: creeremo una funzione che 
 * inverte un array ed una che confronta due array. 
 * Realizzate le due funzioni secondo i prototipi forniti
 * ed infine usatele all'interno di una funzione 
 * palindromo che realizzi la consegna. 
 */

int confronta_array(int *X, int *Y, int dim);
void inverti(int *A, int dim);
void leggi_array(int *X, int dim);
int palindromo(int array[], int n);


int main(void){
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    leggi_array(array, N);

    if(palindromo(array, N)){
        printf("Array palindromo\n");
    } else printf("Array non palindromo\n");
    
}

void inverti(int *A, int dim){
    for(int i=0;i<dim/2;i++){
        int tmp=A[i];
        A[i]=A[(dim-i)-1];
        A[(dim-i)-1]=tmp;
    }
}

int confronta_array(int *X, int *Y, int dim){
    for(int i=0;i<dim;i++){
        if(X[i]!=Y[i])return 0;
    }
    return 1;
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

int palindromo(int array[], int n){
    int arrayInvertito[n];
    //Creo la copia dell'array in parametro
    for(int i=0;i<n;i++){
        arrayInvertito[i]=array[i];
    }
    inverti(arrayInvertito, n);
    return confronta_array(array, arrayInvertito, n);
}