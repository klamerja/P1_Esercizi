#include <stdio.h>

/*
* Scrivete un programma che trovi tutti i numeri perfetti tra due estremi. Sia estremi che i numeri trovati dovranno essere interi.
* Un numero perfetto si definisce tale quando la somma di tutti i suoi divisori eccetto se stesso è uguale al numero stesso.
*
* Il programma deve stampare i valori trovati, utilizzare
* printf("Numero %d perfetto\n", limite_inferiore);
*
* I limiti sono forniti tramite input.
*/

int main (void) {
    
    // inizializzazione e lettura limiti
    int limite_inferiore, limite_superiore;
    scanf("%d %d", &limite_inferiore, &limite_superiore);

    //codice
    for(int i=limite_inferiore;i<=limite_superiore;i++){
        int somma=0;
        for(int j=1;j<i;j++)if(i%j==0)somma+=j;
        if(somma==i)printf("Numero %d perfetto\n", i);
    }
}