#include <stdio.h>

/*
* Date due stringhe, scrivere una funzione che passi come parametri queste stringhe e le concateni.
* La concatenazione deve avvenire nella prima stringa, senza l'utilizzo di altre variabili di tipo array.
* La funzione dovrà sfruttare quanto visto con i puntatori per l'accesso in memoria (non usare S1[i]).
* Una volta fatto ciò, il programma deve stampare la stringa concatenata.
* 
* 
* Per la stampa usare:
* printf("Stringa concatenata: %s",S1);
*/
void concatena_stringhe(char s1[], char s2[]);
void stampa_array(int *A, int dim);

int main (void) {

    //  Per testare più velocemente il vostro algoritmo
    //  potete usare gli array forniti sotto (modificandoli 
    //  secondo le vostre necessità) invece di leggerli 
    //  da input con scanf. Quando siete pronti a 
    //  consegnare potete ricommentare le seguenti righe.
     
    //  Creazione di stringhe con la dimensione maggiore del contenuto (size < length)
    //  Leggi la dimensione degli array e i valori da tastiera. 
    //   Decommentare le seguenti istruzioni per la consegna. 
    int dim1, dim2;
    scanf("%d", &dim1);
    scanf("%d", &dim2);
    char S1[dim1], S2[dim2];
    scanf("%s", S1);
    scanf("%s", S2);

    //Inserite il vostro codice qua
    concatena_stringhe(S1, S2);

    printf("Stringa concatenata: %s",S1);

    return 0;
}

void concatena_stringhe(char s1[], char s2[]){
    while(*s1!='\0')s1++;
    while(*s2!='\0'){
        *s1++=*s2++; //s1++ è diverso da ++s1... il primo caso prima prende il valore e poi lo incrementa
    }
    *s1='\0';
}

