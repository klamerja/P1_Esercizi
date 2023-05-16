#include <stdio.h>
#include "studenti_laureati.h"
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("es4/studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //-----Lettura studenti-----
        //Conteggio degli studenti e reset file
        int n_stud=conta_linee(fp);
        rewind(fp);

        //Allocazione del corso e inizializzazione
        Corso studenti=malloc(sizeof(Studente_extra)*n_stud);
        for(int i=0;i<n_stud;i++){
            leggi_studente(fp, studenti+i);
        }

        fclose(fp); //Chiusura con flush del buffer


        //-----Salvataggio studenti laureati-----
        //Apertura in scrittura del file "studenti_lau.txt"
        fp=fopen("es4/studenti_lau.txt", "w");

        for(int i=0;i<n_stud;i++){
            if(completato_percorso(*(studenti+i))){
                (studenti+i)->status.media=calcola_media(*(studenti+i));
                (studenti+i)->type=Laureato;
            }
            scrivi_studente(fp, *(studenti+i));
            if(i!=n_stud-1)fprintf(fp, "\n");
        }

        fclose(fp);

        //Output finale
        fp = fopen("es4/studenti_lau.txt", "r");
        n_stud=conta_linee(fp);
        rewind(fp);

        for(int i=0; i<n_stud; i++){
            Studente_extra s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
    }
}
