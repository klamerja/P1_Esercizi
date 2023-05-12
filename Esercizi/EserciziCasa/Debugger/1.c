#include <stdio.h>

void calc(int *ptr) {

    for(int i = 0; i<36; i = i+3) {
        *ptr += i/3;
    }

    for(int i = 0; i<=36; i = i+3) {
        *ptr -= i/3; 
    }

}



int main() {
    int j=0;
    calc(&j);
    int k;
    calc(&k);
    int l;
    calc(&l);

    int result = j - k + l;

    printf("Il valore dovrebbe essere -12, ma è %d\n",result);

}