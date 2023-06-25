#define N_VOTI 5
#include <stdio.h>

enum laurea{Laureato, NonLaureato};

typedef struct{
    float media;
    int voti[N_VOTI];
} Status;

typedef struct studenti
{
    char nome[256]; //Attenzione: se si mette un puntatore, va in segv
    char cognome[256];
    int type;
    Status status;
} Studente_extra;



int conta_linee(FILE* fp);

void leggi_studente(FILE* fp, Studente_extra* s);

void scrivi_studente(FILE* fp, Studente_extra s);

float calcola_media(Studente_extra s);

int sufficienza_studente(Studente_extra s);

int completato_percorso(Studente_extra s);

void print_studente(Studente_extra s); //funzione fornita
