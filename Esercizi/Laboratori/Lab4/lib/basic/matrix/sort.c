#include "../matrix.h"

void trasponi_matrice(int *mat1, int *matRisultato, int righe, int colonne){
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            *(matRisultato+righe*j+i)=*(mat1+i*colonne+j);
        }
    }
}