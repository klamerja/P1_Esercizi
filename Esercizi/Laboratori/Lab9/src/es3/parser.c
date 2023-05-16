#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

/* FORMATO FILE STUDENTI: 
 * File testuale, una riga per ogni studente nel formato seguente:
 * nome cognome voto1 voto2 voto3 voto4 voto5
 * Il numero di linee del file corrisponde quindi al numero di studenti
 */


/*
    PRE: fp punta all'inizio di un file studenti
    POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file
*/
int conta_linee(FILE* fp);

/*
    PRE: fp punta all'inizio di un file studenti, s è un puntatore a struct studente
    POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s
*/
void leggi_studente(FILE* fp, Studente* s);

/*
    PRE: fp punta all'inizio di un file studenti, s è uno studente
    POST: scrive su file i dati di un unico studente
*/
void scrivi_studente(FILE* fp, Studente s);



//Main block
int main(){
    FILE *fp;
    //ATTENZIONE: in locale il percorso è es3/studenti.txt, su moodle è studenti.txt
    //Vale anche per l'es 4
    fp = fopen("es3/studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //Lettura file originale e storage all'interno del corso
        int n_stud = conta_linee(fp);
        Corso s = malloc(sizeof(Studente)*n_stud);
        for(int i=0;i<n_stud;i++)leggi_studente(fp, (s+i));
        fclose(fp); //Chiudo lo stream di studenti.txt
        printf("File letto\n\n");

        //Ordinamento
        ordina_studenti(s, n_stud);

        //Scrittura su nuovo file (ordine decrescente)
        fp=fopen("es3/studenti_ord.txt", "w");
        for(int i=n_stud-1;i>=0;i--){
            scrivi_studente(fp, *(s+i));
        }
        fclose(fp); //Effettuo il flush del buffer

        //Output per i test di moodle
        fp = fopen("es3/studenti_ord.txt", "r");
        for(int i=0; i<n_stud; i++){
            Studente s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
        fclose(fp);
    }
}



//Funzioni
int conta_linee(FILE* fp){
    int numb_lines=1; //L'ultima riga finisce con un EOF
    char c=fgetc(fp);
    while(c!=EOF){
        c=fgetc(fp);
        if(c=='\n')numb_lines++;
    }
    rewind(fp);
    return numb_lines;
}

void leggi_studente(FILE* fp, Studente* s){
    fscanf(fp, "%s %s", s->nome, s->cognome);
    for(int i=0;i<N_VOTI;i++){
        fscanf(fp, "%d", &s->voti[i]);
    }
}

void scrivi_studente(FILE* fp, Studente s){
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    for(int i=0;i<N_VOTI;i++){
        fprintf(fp, " %d", s.voti[i]);
    }
    fprintf(fp, "\n");
}
