#include <stdio.h>

/*
    PRE:
    POST: frequenza di ogni singola cifra (dal 0 al 9)
*/
void contaCifre(int numero, int frequenze[]);

int main(){
    int numero;
    printf("Inserire il numero: ");
    scanf("%d", &numero);
    int frequenze[10]={0,0,0,0,0,0,0,0,0,0};
    contaCifre(numero,frequenze);
    int numElementi=sizeof(frequenze)/sizeof(frequenze[0]);
    printf("Num elementi: %d\n", numElementi);
    for(int i=0;i<numElementi;i++){
        printf("Frequenza[%d]=%d\n", i, frequenze[i]);
    }
}

void contaCifre(int numero, int frequenze[]){
    if(numero<0)numero=(-numero);
    do{
        int resto=numero%10;
        frequenze[resto]++;
        numero/=10;
    }while(numero>0);
}