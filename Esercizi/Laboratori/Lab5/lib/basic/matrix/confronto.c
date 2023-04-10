//inserire funzioni Lab5 qui
#include "../array.h"
int confronta_matrici_double(double *Matrice1, double *Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll){
	if(righe1!=righe2 || colonne1 != colonne2)return 0;
	return confronta_array_double(Matrice1, Matrice2, righe1*colonne1, toll);
}

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