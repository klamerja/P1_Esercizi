#include "../matrix.h"
#include "../array.h"

int confronta_matrici_double(double *Matrice1, double* Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll){

    if(righe1 != righe2 || colonne1 != colonne2)
        return 0;
    else
        return confronta_array_double(Matrice1, Matrice2, righe1*colonne1, toll);
}