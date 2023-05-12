#include "../matrix.h"

void trasposta_matrice(int* A, int* B, int righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            B[righe*j+i] = A[colonne*i+j];
        }
    }
}

void trasposta_matrice_double(double *Matrice, double* Trasposta, int righe, int colonne){
    for(int i=0; i<righe; i+=1){
        for(int j=0; j<colonne; j+=1){
            *(Trasposta + i+ j*righe) = *(Matrice +j +i*colonne);
        }
    }
}

void matrice_identita_double(double *Matrice, int dim){

    for(int i=0; i<dim; i+=1){
        for (int j=0; j<dim; j+=1){
            *(Matrice + j+ i*dim) = (i==j)? 1.0 : 0.0;
        }
    }
}

void moltiplica_matrici_double(int dim, double *mat1, double *mat2, double *matRisultato){
    int i, j, k;
    double scalare;
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            // Esegui prodotto scalare tra le righe di mat1 e le colonne di mat2
            scalare = 0.0;
            for(k=0; k < dim; k++){
                scalare += (*((mat1+i*dim)+k)) * (*((mat2+k*dim)+j));
            }
            //NB dobbiamo arrotondare il numero secondo le prime 3 cifre decimali
            *(matRisultato+i*dim+j) = scalare;
        }
    }
}