#include <stdio.h>
#include <basic/array.h>
#include <basic/matrix.h>

/*
* Scrivete una funzione che verifichi se una matrice sia ortogonale.
* Una matrice quadrata si dice ortogonale se la sua trasposta coincide con la sua inversa. 
* In altre parole, se la moltiplicazione tra la matrice e la sua trasposta produce una matrice identità, 
* allora la matrice è ortogonale.
* 
* Esempio:
* |a b|   x  |a c|  =  |1 0|
* |c d|      |b d|     |0 1|
*            
*
* La funzione deve restituire 1 se la variabile è ortogonale o se 0 non è ortogonale.
* Dato che stiamo lavorando con double, utilizzeremo una tolleranza di 0.001 sui valori della matrice identità.
*
* Esempio:
* 0.999 = 1
* 1.001 = 1
*
* Potete utilizzare le funzioni già presenti nella libreria per risolvere l'esercizio 
* (ne abbiamo aggiunte alcune, andate a vedervi i file .h)
*/

int main(){
    //Definiamo la dimensione della matrice (quadrata) 
    int dim;
    scanf("%d", &dim);

    //Definiamo e istanziamo la matrice
    double mat1[dim][dim];
    leggi_array_double(*mat1, dim*dim);

    //Verichiamo se la matrice è ORTOGONALE
    double matTrasposta[dim][dim];
    trasposta_matrice_double(*mat1, *matTrasposta, dim, dim);

    double matProdotto[dim][dim];
    moltiplica_matrici_double(dim, *mat1, *matTrasposta, *matProdotto);

    double matIdentita[dim][dim];
    matrice_identita_double(*matIdentita, dim);
    const int toll=0.001;
    int res=confronta_matrici_double(*matProdotto, *matIdentita, dim, dim, dim, dim, toll);


    // Stampa dell'output
    if (res == 1)
        printf("Matrice ortogonale");
    else
        printf("Matrice non ortogonale");
}