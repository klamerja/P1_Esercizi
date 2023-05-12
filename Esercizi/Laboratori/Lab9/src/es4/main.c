#include <stdio.h>
#include "studenti_laureati.h"

int main(){
    FILE *fp;
    fp = fopen("es4/studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //codice qui

        //output per i test di moodle
        fp = fopen("es4/studenti_lau.txt", "r");
        for(int i=0; i<n_stud; i++){
            Studente_extra s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
    }
}