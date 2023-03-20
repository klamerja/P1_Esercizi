#include <stdio.h>

/*
 * Trasformare il valore in gradi farenheit della variabile fahr (X) nel 
 * corrispondente valore celsius (Y) arrotondato all'intero inferiore e stampare 
 * "X gradi farenheit corrispondono a Y gradi celsius"
 * 
 * Ad esempio se fahr=78 stampa
 * 78 gradi farenheit corrispondono a 25 gradi celsius
 * 
 * Si ricorda che C = (5/9)(F-32)
 *
 * Per la consegna utilizzare F=36
 */

#define F 36

int main () {
    //Dichiarazione variabili
    int c;

    //Calcolo
    c=(5.0/9)*(F-32);

    //Output
    printf("%d gradi farenheit corrispondono a %d gradi celsius\n", F, c);
}