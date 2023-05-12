#include "../studente_corso.h"
#include "../../basic/array.h"
#include <stdio.h>

float calcola_media(Studente s){
    int sum=0; //Somma dei voti
    int num_esami_svolti=N_VOTI; //Numero di esami svolti dallo studente
    for(int i=0;i<N_VOTI;i++){
        if(s.voti[i]==-1)num_esami_svolti--;
        else sum+=s.voti[i]; 
    }
    if(num_esami_svolti==0)return 0.0;
    float avg=(float)sum / num_esami_svolti;
    return avg;
}

int sufficienza_studente(Studente s){
    //Controllo con ritorno se la media dello studente è sufficiente
    return calcola_media(s)>=18.0;
}

void print_studente(Studente s){
    //Stampa del nome e del cognome
    printf("Nome: %s\n", s.nome);
    printf("Cognome: %s\n", s.cognome);
    //Stampa dei voti
    printf("Voti: ");
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}