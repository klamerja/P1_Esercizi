#include "../array.h"

int confronta_array(int* A, int* B, int dim){
    for(int i=0; i<dim; i++){
        if(A[i] != B[i]){
            return 0;
        }
    }
    return 1;
}