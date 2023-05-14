#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente *Corso;



//Prototipi
/*
    PRE: gli studenti del corso, il numero di studenti, esame preso in considerazione (compreso tra 0 ed N_VOTI-1)
    POST: percentuale di superamento dell'esame
*/
float percentuale_superamento_test(Corso s, int n_studenti, int esame);
//La ratio non deve essere in centesimi. Se un esame è stato superato da 1 sola persona su 2, la funzione deve restituire 0.5 e non 50.

/*
    PRE: gli studenti del corso, il numero di studenti
    POST: restituisce lo studente con la media più alta. Se più di uno studente ha stessa media viene preso quello con indice minore
*/
Studente miglior_studente(Corso s, int n_studenti);

/*
    PRE: puntatori a due studenti del corso
    POST: swap in memoria dei due studenti
*/
void swap_studenti(Corso s1, Corso s2);

/*
    PRE: studenti del corso, il numero di studenti
    POST: ordinamento degli studenti a secondo della loro media (senza quicksort)
*/
void ordina_studenti(Corso s, int n_studenti);

//Main block
int main(){
    int n_stud;
    scanf("%d", &n_stud);

    Corso s = malloc(sizeof(Studente)*n_stud);
    for(int i=0; i<n_stud; i++){
        scanf("%s %s", (s+i)->nome, (s+i)->cognome);
        for(int j=0; j<N_VOTI; j++)
            scanf("%d", ((s+i)->voti) + j);
    }

    printf("Miglior Studente:\n");
    print_studente(miglior_studente(s, n_stud));
    for(int i=0; i<N_VOTI; i++){
        printf("Percentuale superamento corso %d: %.2f\n", i, percentuale_superamento_test(s, n_stud, i)*100);
    }

    ordina_studenti(s, n_stud);
    printf("Peggiori 2 Studenti:\n");
    for(int i=0; i<2; i++){
        print_studente(*(s+i));
    }

}



//Funzioni
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