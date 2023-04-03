#include<stdio.h>

/* Date due stringhe N e T, trovare la posizione del primo match di T in N.
 * Trovare un match significa trovare una sottosequenza di caratteri adiacenti in N uguali a T.
 * (ovvero una *(N+k)==*T, *(N+(k+1))==*(T+1), ..., *(N+(k+n))==*(T+n) dove n è (la lunghezza di T)-$
 * La posizione del match è uguale a quella del primo carattere matchato in N.
 * ES: N="programmazione2022", T="gra" -> "Match found at position 3"
 * ES: N="programmazione2020", T="ez" -> "No match found"
*/

unsigned int len(char* N);
int init_match(char* N, char*T, unsigned int N_len, unsigned int T_len);


int main(){

    // Nota:
    // 256 è la dimensione massima della stringa ma il numero di caratteri può essere inferiore
    // implementare una funzione len per misurare la lunghezza di una stringa
    // (contare quanti caratteri ci sono prima del delimiter "\0")
     
    // Per testare più velocemente il vostro algoritmo
    // potete usare le istruzioni fornite sotto. 
    // Quando siete pronti a consegnare potete ricommentare le seguenti righe.
 
    //  Decommentare le seguenti 4 istruzioni per la consegna. 
    char N[256];
    char T[256];
    scanf("%255s", N);
    scanf("%255s", T);


    int N_len =len(N), T_len =len(T);
    int index_match=-1;
    //inserite il vostro codice qui
    for(int i=0;i<N_len && index_match==-1;i++){
        if(init_match(&N[i], T, N_len, T_len)){
            index_match=i;
        }
    }
    if(index_match==-1)printf("No match found\n");
    else printf("Match found at position %d\n", index_match);

}

unsigned int len(char* N){
    unsigned int length=0;
    while(*N++!='\0')length++;
    return length;
}

int init_match(char *N, char *T, unsigned int N_len, unsigned int T_len){
    if(N_len<T_len)return 0;
    for(int i=0;i<T_len;i++){
        if(*(N+i)!=T[i]) return 0;//Nel caso il puntatore di N si trovasse alla fine, vi sarebbe la verifica tra un carattere e \0, equivalente a false
    }

    return 1;
}
