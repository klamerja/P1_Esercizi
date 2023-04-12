//Librerie
#include <stdio.h>
#include <basic/matrix.h>
#include <basic/array.h>

/*
* CONSEGNA: Scrivere una funzione che verifichi se una matrice sia o meno ORTOGONALE.
* Una matrice quadrata è dette ortogonale se la sua trasposta coincide con la sua inversa (cioé la moltiplicazione tra matrice e trasposta produce una matrice identità)
* La funzione deve restituire 1 se la matrice è ortogonale, 0 altrimenti.
* L'esercizio prevede una tolleranza nei controlli dei double di 0.001
*/

//Prototipi
int is_matrice_ortogonale(double *mat, int dim, double toll);
void moltiplica_matrici_double(int dim, double *mat1, double *mat2, double *matRisultato);
int confronta_matrici_double(double *Matrice1, double *Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll);


//Blocco main
int main(void){
    //Dichiarazione e istanza della dimensione della matrice quadrata
    int dim;
    scanf("%d", &dim);

    //Dichiarazione e istanza della matrice
    double mat[dim][dim];
    leggi_array_double(*mat, dim*dim);

    //Verifichiamo se la matrice è ortogonale
    const double toll=0.001;
    int res;
    res=is_matrice_ortogonale(*mat, dim, toll);
    
    //Output del programma
    if(res)printf("Matrice ortogonale");
    else printf("Matrice non ortogonale");
}


//Funzioni
/*
    PRE: MATRICE è un vettore di dimensione dim*dim; toll è la tolleranza per il confronto dei double
    POST: ritorno di un intero: 1 se la matrice ortogonale, 0 altrimenti
*/
int is_matrice_ortogonale(double *mat, int dim, double toll){
    //Calcolo della trasposta della matrice
    double matTrasposta[dim][dim];
    trasposta_matrice_double(mat, *matTrasposta, dim, dim);

    //Prodotto della matrice e della sua trasposta
    double matProdotto[dim][dim];
    moltiplica_matrici_double(dim, mat, *matTrasposta, *matProdotto);

    //Confronto la matrice con la matrice identità (generata dalla funzione inclusa nella libreria di base)
    double matIdentita[dim][dim];
    matrice_identita_double(*matIdentita, dim);
    return confronta_matrici_double(*matProdotto, *matIdentita, dim, dim, dim, dim, toll);
}

/*
    PRE: mat1, mat2 e matRisultato sono tre vettori di dimensione dim*dim
    POST: prodotto di mat1 e mat2 allocato in matRisultato
*/
void moltiplica_matrici_double(int dim, double *mat1, double *mat2, double *matRisultato){
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			*(matRisultato+i*dim+j)=0;
			for(int k=0;k<dim;k++){
				*(matRisultato+i*dim+j)+=(*(mat1+i*dim+k)) * (*(mat2+k*dim+j));
			}
		}
	}
}

/*
    PRE: Matrice1 e Matrice2 sono due vettori aventi dimensione propria
    POST: ritorno di un intero: 1 se le matrici sono uguali, 0 altrimenti
*/
int confronta_matrici_double(double *Matrice1, double *Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll){
	if(righe1!=righe2 || colonne1 != colonne2)return 0;
	return confronta_array_double(Matrice1, Matrice2, righe1*colonne1, toll);
}

