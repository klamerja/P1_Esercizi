#include "../array.h"

int confronta_array(int *X, int *Y, int dim){
    for(int i=0;i<dim;i++){
        if(X[i]!=Y[i])return 0;
    }
    return 1;
}