#include "../studente_corso.h"
#include <stdio.h>

float percentuale_superamento_test(Corso c, int n_studenti, int esame){
    int n_studenti_test=0;
    int n_test_superati=0;
    for(int i=0;i<n_studenti;i++){
        Studente s=*(c+i);
        if(s.voti[esame]!=-1){
            n_studenti_test++;
            if(s.voti[esame]>=18)n_test_superati++;
        }
    }
    if(!n_studenti_test)return 0.0;
    return ((float)n_test_superati)/n_studenti_test;
}

Studente miglior_studente(Corso c, int n_studenti){
    Studente miglior_studente=*c; //Potevamo anche solamente salvarci l'indice e poi lavorare con l'array
    float max_media=calcola_media(miglior_studente);
    for(int i=1;i<n_studenti;i++){
        Studente s=*(c+i);
        if(calcola_media(s)>max_media){
            max_media=calcola_media(s);
            miglior_studente=s;
        }
    }
    return miglior_studente;
}

void swap_studenti(Studente* s1, Studente* s2){
    Studente tmp=*s1;
    *s1=*s2;
    *s2=tmp;
}

void ordina_studenti(Corso c, int n_studenti){
    for(int i=0;i<n_studenti-1;i++){
        for(int j=i+1;j<n_studenti;j++){ //ATTENZIONE: con j=1 sicuramente quando i sarà minore di j, vuol dire che quelli precedenti sono ordinati e restano così, se li vado a rivedere è ovvio che sarà più grande, ma mettendo j=1, vado a riscambiarli
            if(calcola_media(*(c+i))>calcola_media(*(c+j)))swap_studenti(c+i,c+j);//Non potevo modificare semplicemente i c perché i puntatori agli elemenenti dell'array sono passati per copia
        }
    }
}