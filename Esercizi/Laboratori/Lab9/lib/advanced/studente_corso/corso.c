#include "../studente_corso.h"
#include <stdio.h>

float percentuale_superamento_test(Corso s, int n_studenti, int esame){
    int num_studenti_valutati=n_studenti; //Numero effettivo di studenti che hanno effettuato l'esame
    int num_studenti_sufficienti=0; //Numero di studenti sufficienti
    for(int i=0;i<n_studenti;i++){
        int valutazione_studente=(s+i)->voti[esame]; //Valutazione dell'esame dell'i-esimo studente
        if(valutazione_studente==-1)num_studenti_valutati--; //Controllo della presenza dell'esame
        else if(valutazione_studente>=18)num_studenti_sufficienti++; //Controllo la sufficienza nell'esame nel caso in cui venga fatto
    }
    //Se nessuno viene valutato, la percentuale di superamento è 0.0
    if(num_studenti_valutati==0)return 0.0;
    //Calcolo la ratio di superamento
    float ratio=(float)num_studenti_sufficienti / num_studenti_valutati;
    return ratio;
}

Studente miglior_studente(Corso s, int n_studenti){
    int max_media=-1.0;
    Studente studente_migliore;
    for(int i=0;i<n_studenti;i++){
        if(calcola_media(*(s+i))>max_media){
            max_media=calcola_media(*(s+i));
            studente_migliore=*(s+i);
        }
    }
    return studente_migliore;
}

void swap_studenti(Corso s1, Corso s2){
    Studente tmp=*s1;
    *s1=*s2;
    *s2=tmp;
}

void ordina_studenti(Corso s, int n_studenti){
    for(int i=0;i<(n_studenti-1);i++){
        for(int j=i+1;j<n_studenti;j++){
            if(calcola_media(*(s+i))>calcola_media(*(s+j))){
                swap_studenti(s+i, s+j);
            }
        }
    }
}
