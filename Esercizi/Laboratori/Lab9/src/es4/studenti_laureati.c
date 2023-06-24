#include "studenti_laureati.h"
#include <string.h>
#include <basic/array.h>

int conta_linee(FILE* fp){
    int num_linee=1; //L'ultima riga finisce con EOF, quindi una riga va contata di default
    char c=fgetc(fp);
    while(c!=EOF){
        if(c=='\n')num_linee++;
        c=fgetc(fp);
    }
    return num_linee;
}

void leggi_studente(FILE* fp, Studente_extra* s){
    char *is_laureato;
    fscanf(fp, "%s %s %s", s->nome, s->cognome, is_laureato);
    printf
    if(strcmp(is_laureato, "Laureato")==0)s->type=Laureato;
    if(s->type==Laureato){
        fscanf(fp, "%f", &s->status.media);
    }else{
        for(int i=0;i<N_VOTI;i++){
            fscanf(fp, "%d", s->status.voti+i);
        }
    }
}

void scrivi_studente(FILE* fp, Studente_extra s){
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    if(s.type==Laureato){
        fprintf(fp, "Laureato %.1f", s.status.media);
    }else{
        fprintf(fp, "Non_laureato");
        for(int i=0;i<N_VOTI;i++){
            fprintf(fp, " %d", s.status.voti[i]);
        }
    }
}

float calcola_media(Studente_extra s){
    if(s.type==Laureato)return s.status.media;
    int n_esami=N_VOTI;
    float sum_voti=0;
    for(int i=0;i<N_VOTI;i++){
        if(s.status.voti[i]==-1)n_esami--;
        else sum_voti+=s.status.voti[i];
    }
    if(n_esami==0)return 0.0;
    return sum_voti/n_esami;
}

int sufficienza_studente(Studente_extra s){
    return calcola_media(s)>=18;
}

int completato_percorso(Studente_extra s){
    for(int i=0;i<N_VOTI;i++){
        if(s.status.voti[i]==-1)return 0;
    }
    return sufficienza_studente(s);
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
