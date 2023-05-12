#include "studenti_laureati.h"
#include <string.h>
#include <basic/array.h>

int conta_linee(FILE* fp){
    //
}

void leggi_studente(FILE* fp, Studente_extra* s){
    //
}

void scrivi_studente(FILE* fp, Studente_extra s){
    //
}

float calcola_media(Studente_extra s){
    //
}

int sufficienza_studente(Studente_extra s){
    //
}

int completato_percorso(Studente_extra s){
    //
}

void print_studente(Studente_extra s){
    printf("Nome: %s\nCognome: %s\n", s.nome, s.cognome);
    if(s.type == Laureato){
        printf("Laureato con media del %.1f", s.status.media);
    }
    else{
        printf("Voti: ");
        stampa_array(s.status.voti, N_VOTI);
    }
    printf("\n");
}