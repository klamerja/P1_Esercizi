#include <stdio.h>
#include <stdlib.h>
#include "studenti_laureati.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //Trovo il numero di studenti
        int n_stud=conta_linee(fp);
        rewind(fp);

        //Memorizzo gli studenti all'interno di un array
        Studente_extra *c=malloc(sizeof(Studente_extra)*n_stud);
        for(int i=0;i<n_stud;i++){
            leggi_studente(fp, c+i);
        }
        fclose(fp); //Chiusura file

        //Controllo la situazione degli studenti e effettuo aggiornamenti
        for(int i=0;i<n_stud;i++){
            if((c+i)->type==NonLaureato && completato_percorso(*(c+i))){
                (c+i)->status.media=calcola_media(*(c+i));
                (c+i)->type=Laureato;
            }
        }

        //Scrivo in studenti_lau.txt la mia lista aggiornata
        fp=fopen("studenti_lau.txt", "w");
        for(int i=0;i<n_stud;i++){
            scrivi_studente(fp, *(c+i));
            if(i!=n_stud-1)fputc('\n', fp);
        }
        fclose(fp);

        //output per i test di moodle
        fp = fopen("studenti_lau.txt", "r");
        for(int i=0; i<n_stud; i++){
            Studente_extra s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
    }
}
