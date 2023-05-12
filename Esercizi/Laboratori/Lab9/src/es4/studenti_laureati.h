#define N_VOTI 5
#include <stdio.h>

typedef struct studenti
{
    //definire nuova struct
} Studente_extra;

//funzione identica a quella fatta in es.3
int conta_linee(FILE* fp);

//vedi file d'esempio
void leggi_studente(FILE* fp, Studente_extra* s);
void scrivi_studente(FILE* fp, Studente_extra s);

float calcola_media(Studente_extra s);
//POST: media dei voti salvata per laureati, media dei voti presenti per quelli non laureati 

int sufficienza_studente(Studente_extra s);
//POST: 1 per studenti laureati, per i non laureati come es 1

int completato_percorso(Studente_extra s);
//PRE: 1 per studenti laureati, 1 per studenti non laureato se e solo se hanno tutti i voti e la media è maggiore o uguale a 18

void print_studente(Studente_extra s); //funzione fornita
