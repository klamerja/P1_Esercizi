#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>
/* FORMATO FILE STUDENTI: 
 * File testuale, una riga per ogni studente nel formato seguente:
 * nome cognome voto1 voto2 voto3 voto4 voto5
 * Il numero di linee del file corrisponde quindi al numero di studenti
 */



//Prototipi
/*
    PRE: fp punta all'inizio di un file studenti
    POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file
*/
int conta_linee(FILE* fp);

/*
    PRE: fp punta a qualsiasi parte del file, s è un puntatore a studente, dove verrà inserita la copia
    POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s
*/
void leggi_studente(FILE* fp, Studente* s);

/*
    PRE: fp è la posizione all'interno del file, s è lo studente da scrivere
    POST: 
*/
void scrivi_studente(FILE* fp, Studente s);



//Main block
int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //Conteggio studenti presenti nel file studenti.txt e allocazione dinamica del corso mediante malloc
        int n_stud = conta_linee(fp);
        Corso s = malloc(sizeof(Studente)*n_stud);
        rewind(fp);

        //Lettura studenti
        for(int i=0;i<n_stud;i++){
            leggi_studente(fp, s+i);
        }

        //Fine lettura file
        fclose(fp);
        printf("File letto\n\n");

        //ordinamento
        ordina_studenti(s, n_stud); //Funzione contenuta nella librearia che ordina gli studenti in base alla loro media in maniera crescente

        //Scrittura degli studenti ordinati su nuovo file
        fp=fopen("studenti_ord.txt", "w");
        for(int i=n_stud-1;i>=0;i--){
            //Il corso è stato ordinato, basta sfruttare la funzione di scrittura studenti
            scrivi_studente(fp, *(s+i));
            if(i!=(n_stud-1))fputc('\n', fp);
        }
        fclose(fp);

        //output per i test di moodle
        fp = fopen("studenti_ord.txt", "r");
        for(int i=0; i<n_stud; i++){
            Studente s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
    }
}



//Funzioni
int conta_linee(FILE* fp){
    int num_linee=1; //L'ultima riga finisce con EOF, quindi una riga va contata di default
    char c=fgetc(fp);
    while(c!=EOF){
        if(c=='\n')num_linee++;
        c=fgetc(fp);
    }
    return num_linee;
}

void leggi_studente(FILE* fp, Studente* s){
    fscanf(fp, "%s %s", s->nome, s->cognome);
    for(int i=0;i<N_VOTI;i++){
        fscanf(fp, "%d", (s->voti)+i); //anche &s->voti[i] (associatività maggiore di -> rispetto a &)
    }
}

void scrivi_studente(FILE* fp, Studente s){
    fprintf(fp, "%s %s", s.nome, s.cognome);
    for(int i=0;i<N_VOTI;i++){
        fprintf(fp, " %d", s.voti[i]);
    }
}