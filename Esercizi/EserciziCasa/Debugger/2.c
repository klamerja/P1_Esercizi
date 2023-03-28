#include <stdio.h>



/* 

    PRE: dimensione di A >= dim 

    POST: restituisce 1 se x è presente nei primi dim elementi di A

                      0 altrimenti

*/

int cerca_in_array(int A[], int dim, int x) {
    int i=0;
    while(A[i]!=x && i<dim) 
        i+=1;
    return A[i]==x;
}

int main() {
    int A[3]={5,8,6};
    int n = 6;
    if (cerca_in_array(A,2,n)) printf("%d presente in array\n", n);
    else printf("%d non presente in array\n", n);
}



