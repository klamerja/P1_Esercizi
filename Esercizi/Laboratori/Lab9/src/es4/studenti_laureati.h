#define N_VOTI 5
#include <stdio.h>

//Enum: 0=Laureato, 1=Non_Laureato
enum stato_laurea{Laureato, Non_Laureato};

typedef struct{
        float media;
        int voti[N_VOTI];
}Status;

typedef struct studenti{
    char nome[20];
    char cognome[20];
    int type;
    Status status;
} Studente_extra;

typedef Studente_extra* Corso;

/*
    PRE: puntatore a struct FILE
    POST: numero di linee del file
*/
int conta_linee(FILE* fp);

/*
    PRE: puntatore a struct FILE, puntatore a Studente_extra
    POST: allocazione dello studente all'interno del corso
*/
void leggi_studente(FILE* fp, Studente_extra* s);

/*
    PRE: puntatore a struct FILE, puntatore a Studente_extra
    POST: scrittura dello studente all'interno del file
*/
void scrivi_studente(FILE* fp, Studente_extra s);

/*
    PRE: Studente_extra
    POST: media dello studente: ritorna il valore contenuto in status.media se laureato, altrimenti calcola da array status.voti
*/
float calcola_media(Studente_extra s);

/*
    PRE: Studente_extra
    POST: 1 se media>=18 o studente laureato, 0 altrimenti
*/
int sufficienza_studente(Studente_extra s);

/*
    PRE: Studente_extra
    POST: 1 se studente_laureato oppure 5 voti presenti e media>=18, 0 altrimenti
*/
int completato_percorso(Studente_extra s);

/*
    PRE: Studente_extra
    POST: Stampa a video lo studente
*/
void print_studente(Studente_extra s); //funzione fornita
