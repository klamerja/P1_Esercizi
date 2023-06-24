#include <stdio.h>
#include <stdlib.h>
#include "studenti_laureati.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
        return EXIT_FAILURE;
    }
    else {
        //Trovo il num di studenti presenti all'interno del file
        int n_stud=conta_linee(fp);
        rewind(fp);

        //Leggo tutti gli studenti del file e li salvo all'interno ad un array di Studente_Extra
        Studente_extra* c=malloc(sizeof(Studente_extra)*n_stud);
        for(int i=0;i<n_stud;i++){
            leggi_studente(fp, c+i);
        }
        fclose(fp); //Chiusura del file

        //Verifico la situazione scolastica e aggiorno le lauree
        for(int i=0;i<n_stud;i++){
            Studente_extra s=*(c+i);
            if(completato_percorso(s) && s.type==Non_Laureato){
                s.status.media=calcola_media(s);
                s.type=Laureato;
            }
        }

        //Apro e scrivo all'interno di studenti_lau.txt
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
        fclose(fp);
    }
}
