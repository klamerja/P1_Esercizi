#include "../matrix.h"
#include <stdio.h>

void stampa_matrice(int *M, int r, int c){ 
    for (int i = 0; i < r; i += 1){ 
        for (int j = 0; j < c; j += 1){ 
            printf("%d ", *(M + j + i*c));  
        } 
        printf("\n"); 
    } 
} 