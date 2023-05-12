#include <stdio.h>

/*
 * Programma che converte un numero di giorni in anni/settimane/giorni 
 *
 * Es. se giorni=760 stampa (notate l'accapo finale)
 * 760 giorni corrispondono ad anni 2, settimane 4, giorni 2
 * 
 * Per la consegna utilizzare giorni=366
 */

#define GG 366

int main () {
    //Dichiarazione variabili
    int anni, settimane, giorni;

    //Calcolo anni
    anni=GG/365;

    //Calcolo settimane
    settimane=(GG%365)/7;

    //Calcoli giorni
    giorni=(GG%365)%7;

    //Output
    printf("%d giorni corrispondono ad anni %d, settimane %d, giorni %d\n", GG, anni, settimane, giorni);
}