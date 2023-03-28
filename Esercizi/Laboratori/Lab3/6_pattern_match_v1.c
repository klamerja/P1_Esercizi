#include <stdio.h>

/* La mia versione (senza suggerimenti) di pattern_match.c*/

/* Prototipi */
unsigned int len(char* N);
int find_pattern_index(char *N, char *T, int N_len, int V_len);

/* Main */
int main(){
    char N[256];
    char T[256];
    scanf("%255s", N);
    scanf("%255s", T);


    int N_len =len(N), T_len =len(T);
    //inserite il vostro codice qui
    int index_match=find_pattern_index(N, T, N_len, T_len);
    if(index_match==-1)printf("No match found\n");
    else printf("Match found at position %d\n", index_match);

}

/* Funzioni*/

unsigned int len(char* N){
    unsigned int length=0;
    while(*N++!='\0')length++;
    return length;
}

int find_pattern_index(char *N, char *T, int N_len, int T_len){
    int index_match=-1;
    if(N_len>T_len){
        for(int i=0;i<N_len && index_match==-1;i++){
            int isPattern=1;
            for(int j=0;j<T_len && isPattern!=0;j++){
                if(*(N+i+j)!=T[j])isPattern=0;
            }
            if(isPattern)index_match=i;
        }
        return index_match;
    }else return index_match;
}
