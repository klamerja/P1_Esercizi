#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>
/* FORMATO FILE STUDENTI: 
 * File testuale, una riga per ogni studente nel formato seguente:
 * nome cognome voto1 voto2 voto3 voto4 voto5
 * Il numero di linee del file corrisponde quindi al numero di studenti
 */


//PRE: fp punta all'inizio di un file studenti
int conta_linee(FILE* fp);
//POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file

void leggi_studente(FILE* fp, Studente* s);
//POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s

void scrivi_studente(FILE* fp, Studente s);
//POST: scrive su file i dati di un unico studente

int main(){
    FILE *fp;
    //ATTENZIONE: in locale il percorso è es3/studenti.txt, su moodle è studenti.txt
    //Vale anche per l'es 4
    fp = fopen("es3/studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //lettura file originale
        int n_stud = conta_linee(fp);
        Corso s = malloc(sizeof(Studente)*n_stud);    
        //vostro codice qui
        
        printf("File letto\n\n");

        //ordinamento
        ordina_studenti(s, n_stud);

        //scrittura su nuovo file (ordine decrescente)

        //output per i test di moodle
        fp = fopen("es3/studenti_ord.txt", "r");
        for(int i=0; i<n_stud; i++){
            Studente s;
            leggi_studente(fp, &s);
            print_studente(s);
        }
    }
}
