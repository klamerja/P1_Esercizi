#include "studenti_laureati.h"
#include <string.h>
#include <basic/array.h>

int conta_linee(FILE* fp){
    int numb_lines=1;
    char c=fgetc(fp);
    while(c!=EOF){
        if(c=='\n')numb_lines++;
        c=fgetc(fp);
    }
    return numb_lines;
}

void leggi_studente(FILE* fp, Studente_extra* s){
    char isLaureato[20];
    fscanf(fp, "%s %s %s", s->nome, s->cognome, isLaureato);
    //Controllo della laurea e lettura
    if(strcmp(isLaureato, "Laureato")==0){
        s->type=Laureato;
        fscanf(fp, "%f", &s->status.media);
    }
    else{
        s->type=Non_Laureato;
        for(int i=0;i<N_VOTI;i++){
            fscanf(fp, "%d", &s->status.voti[i]);
        }
    }
}

void scrivi_studente(FILE* fp, Studente_extra s){
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    if(s.type==Laureato){
        fprintf(fp, "%s %.1f", "Laureato", s.status.media);
    }else{
        fprintf(fp, "%s", "Non_laureato");
        for(int i=0;i<N_VOTI;i++){
            fprintf(fp, " %d", s.status.voti[i]);
        }
    }
}

float calcola_media(Studente_extra s){
    if(s.type==Laureato){
        return s.status.media;
    }else{
        float numb_voti=N_VOTI;
        int sum=0;
        for(int i=0;i<N_VOTI;i++){
            if(s.status.voti[i]==-1)numb_voti--;
            else{
                sum+=s.status.voti[i];
            }
        }
        return sum / numb_voti;
    }
}

int sufficienza_studente(Studente_extra s){
    if(s.type==Laureato)return 1;
    if(calcola_media(s)>=18.0)return 1;
    return 0;
}

int completato_percorso(Studente_extra s){
    if(s.type==Laureato)return 1;
    for(int i=0;i<N_VOTI;i++){
        if(s.status.voti[i]==-1)return 0;
    }
    if(sufficienza_studente(s)){
        return 1;
    }
    return 0;
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
