#include <stdio.h>

/*
    PRE: s è un puntatore alla stringa o a un carattere della stringa nel caso di esecuzione ricorsiva
    POST: ritorna la lunghezza della stringa tramite chiamate ricorsive
*/
int str_len(char *s){
    if(*s=='\0')return 0;
    return 1+str_len(s+1);
}

int main(void){
    char s[100];
    scanf("%s", s);
    int lunghezza_s=str_len(s);
    printf("%d\n", lunghezza_s);
}