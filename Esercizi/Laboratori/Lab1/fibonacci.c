#include <stdio.h>

/*
 * Data la costante LIMIT, stampare la serie di 
 * fibonacci, fib(k), a partire da fib(0) fino al
 * valore fib(k) più grande t.c. fib(k) < LIMIT.
 * 
 * La funzione di Fibonacci è definita per casi:
 * 
 * fib(0) = 0
 * fib(1) = 1
 * fib(i) = fib(i-1) + fib(i-2)
 * 
 * Es. se LIMIT = 25 stampa
 * 0
 * 1
 * 1
 * 2
 * 3
 * 5
 * 8
 * 13
 * 21
 * 
 * Per la consegna assegnare LIMIT=56
 * 
 */

#define LIMIT 56

int main() {
    //Dichiarazione variabili
    int precedente=0;
    int corrente=1; //Presupposto-> siamo a fib(1)
    int successivo=1; //Sequenza

    //Elaborazione e output
    printf("%d\n%d\n", precedente, corrente);
    while(successivo<LIMIT){
        printf("%d\n", successivo);
        precedente=corrente;
        corrente=successivo;
        successivo=corrente+precedente;
    }
}