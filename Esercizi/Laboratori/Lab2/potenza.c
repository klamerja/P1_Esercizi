#include <stdio.h>
/* 
 * Definire una funzione che, dati due 
 * interi: base ed esponente, restituisce 
 * base elevata ad esponente. Il prototipo della
 * funzione è il seguente: 
 * 
 * int potenza(int base, int esponente);
 *
 * La funzione deve soddisfare le seguenti PRE e POST:
 * PRE: base è un intero positivo (>=1) ed esponente un intero positivo o nullo.
 * POST: la funzione restituisce base^esponente.
 * 
 * Es. se l'input è: "2 3" stampa 
 * 8
 * 
 */

int potenza(int base, int esponente){
    int result=1;

    for(int i=0;i<esponente;i++){
        result*=base;
    }
    
    return result;
}

int main (void) {

    int base, esp;
    //A tempo di esecuzione, fornire due interi separati da spazio e seguiti da Invio
    scanf("%d %d", &base, &esp);

    printf("%d\n", potenza(base, esp));

}