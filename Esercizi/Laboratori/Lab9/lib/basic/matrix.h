//io 
void stampa_matrice(int*, int, int);
void stampa_matrice_double(double *, int, int);


//write

/*
    PRE:  A e B vettori di dimensione righe*colonne
    POST: B è la trasposta di A: 0<=i<righe, 0<=j<colonne A(i,j)=B(j,i)
*/
void trasposta_matrice(int* A, int* B, int righe, int colonne);

/* trasposta_matrice() per vettori di double */
void trasposta_matrice_double(double *, double *, int , int );


/* 
    PRE: Matrice è un vettore di dimensione dim*dim
    POST: modificata Matrice in modo che sia una matrice identità
          Matrice identità: 1 sulla diagonale principale, 0 gli altri elementi
*/
void matrice_identita_double(double *Matrice, int dim);

/* per PRE e POST vedi lab 5*/
void moltiplica_matrici_double(int , double *, double *, double *);
int confronta_matrici_double(double *, double* , int , int , int , int, double);
