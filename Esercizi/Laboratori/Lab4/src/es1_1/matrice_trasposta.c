#include <stdio.h>
#include <basic/array.h>
#include <basic/matrix.h>

/*
* Scrivete un programma che calcoli la trasposta di una matrice generica.
*
* L'operazione consiste nello scambiare le righe con le colonne.
*
* Esempio:
* |a b c| ____ |a d|
* |d e f|      |b e|
*              |c f|
*
*/

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 
    // usare la matrice sotto (modificandola secondo le vostre necessità)
    // invece di leggerla da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.
    
    /*int righe = 3, colonne = 3;
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};*/
    
    // creiamo e instanziamo le variabili di supporto per la dimensione della matrice
    int righe, colonne;
    scanf("%d %d", &righe, &colonne);

    // definiamo ed instanziamo la matrice
    int mat1[righe][colonne];
    //funzione libreria
    leggi_array(*mat1, righe*colonne);

    // trasponi matrice

    //stampiamo il risultato
    //funzione libreria
    stampa_matrice(*matRisultato, colonne, righe);

    return 0;
}