#include <stdio.h>

int somman(int n);
int potenza(int b, int exp);

int main(void){
    int x=somman(5);
    int y=potenza(7, 2);
    printf("%d\n", x);
}

int somman(int n){
    if(n==1)return 1;
    return n+somman(n-1);
}

int potenza(int b, int exp){
    if(exp==0) return 1;
    return b*potenza(b, exp-1);
}
