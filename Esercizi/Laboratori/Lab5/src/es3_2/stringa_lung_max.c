#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * Scrivere una funzione che, dato un array di stringhe,
 * restituisca la stringa di lunghezza massima. 
 * Nel main si dovrà stampare tale stringa.
 * Inoltre, si tratti in modo appropriato il caso in cui
 * il numero di stringhe nell'array sia zero. In particolare,
 * nel main si stampi "array vuoto\n". Se il numero di 
 * stringhe è maggiore di zero, utilizzare il seguente comando
 * nel main per la stampa della stringa più lunga:
 * 
 * printf("%s\n", stringa_lung_max(stringhe, num_stringhe));
 * 
 * Il numero di stringhe e le stringhe stesse sono lette da 
 * tastiera. 
 * 
 */

/*
    PRE: s è un puntatore alla stringa o a un carattere della stringa nel caso di esecuzione ricorsiva
    POST: ritorna la lunghezza della stringa tramite chiamate ricorsive
*/
int str_len(char *s){
    if(*s=='\0')return 0;
    return 1+str_len(s+1);
}

/*
    PRE: s puntatore al primo elemento dell'array di stringhe. Numero di stringhe=l
    POST: lunghezza massima
*/
char* stringa_lung_max(char *s, int l){
    int max_len=INT_MIN;
    char *str_len_max=s;
    for(int i=0;i<l;i++){
        int len=str_len(s+i*256);
        if(len>max_len){
            max_len=len;
            str_len_max=s+i*256;
        }
    }
    return str_len_max;
}


void test_stringa_lung_max() {

    char s[5][256]={{"ciao"}, {"ciaociao"}, {""}, {"hello"},{"c"}};
    assert(stringa_lung_max(*s, 5)==s[1]);
    printf("test stringa_lung_max superato\n");

}


int main(void) {

    /* test_stringa_lung_max(); */

    int num_stringhe;
    scanf("%d", &num_stringhe);

    char stringhe[num_stringhe][256];
    for(int i=0; i<num_stringhe;i+=1) {
        scanf("%255s", stringhe[i]);
    }

    char *s_max = stringa_lung_max(*stringhe, num_stringhe);
    printf("%s\n", (s_max==NULL)?"array vuoto": s_max);


}
