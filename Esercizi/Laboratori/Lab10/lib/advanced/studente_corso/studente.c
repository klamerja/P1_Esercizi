#include "../studente_corso.h"
#include "../../basic/array.h"
#include <stdio.h>

float calcola_media(Studente s){
    int esami_svolti=N_VOTI;
    float sum_voti=0;
    for(int i=0;i<N_VOTI;i++){
        if(s.voti[i]==-1)esami_svolti--;
        else sum_voti+=s.voti[i];
    }
    if(esami_svolti==0)return 0.0;
    return sum_voti/esami_svolti;
}

int sufficienza_studente(Studente s){
    return calcola_media(s)>=18;
}

void print_studente(Studente s){
    printf("Nome: %s\nCognome: %s\n", s.nome, s.cognome);
    printf("Voti: ");
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}