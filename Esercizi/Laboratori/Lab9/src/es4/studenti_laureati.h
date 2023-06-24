#define N_VOTI 5
#include <stdio.h>


//Enum e structs
enum type{Non_Laureato, Laureato};

typedef struct{
    float media;
    int voti[N_VOTI];
} Status;

typedef struct studenti
{
    char *nome;
    char *cognome;
    int type;
    Status status;
} Studente_extra;

//Prototipi

/*
    PRE: puntatore a file
    POST: numero di linee presenti nel file (equivalenti al num di studenti)
*/
int conta_linee(FILE* fp);

/*
    PRE: puntatore a file e puntatore a Studente_extra
    POST: lettura e copia in s dello studente presente nella i-esima riga del file
*/
void leggi_studente(FILE* fp, Studente_extra* s);

/*
    PRE: puntatore a file e struttura di tipo Studente_extra
    POST: scrittura all'interno del file
*/
void scrivi_studente(FILE* fp, Studente_extra s);

/*
    PRE: struttura di tipo Studente_extra
    POST: media dei voti (float)
*/
float calcola_media(Studente_extra s);

/*
    PRE: struttura di tipo Studente_extra
    POST: 1 se studente sufficiente o laureato, 0 altrimenti
*/
int sufficienza_studente(Studente_extra s);

/*
    PRE: struttura di tipo Studente_extra
    POST: 1 se il percorso è completato o laureati, 0 altrimenti
*/
int completato_percorso(Studente_extra s);

void print_studente(Studente_extra s);
