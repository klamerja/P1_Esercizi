#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente* Corso; //Corso è un puntatore a struct studente (è l'alias di Studente*), meglio dire puntatore al primo elemento di un array di studenti



//Prototipi
/*
    PRE: esame compreso tra 0 e N_VOTI
    POST: calcola la ratio di superamento dell'esame (solo guardando gli studenti che hanno conseguito un voto, chi non ha fatto l'esame non è contato). Se nessuno ha fatto l'esame la percentuale è 0.
*/
float percentuale_superamento_test(Corso c, int n_studenti, int esame);
//La ratio non deve essere in centemìsimi. Se un esame è stato superato da 1 sola persona su 2, la funzione deve restituire 0.5 e non 50.

/*
    PRE: s è un corso non vuoto
    POST: restituisce lo studente con la media più alta. Se più di uno studente ha stessa media viene preso quello con indice minore.
*/
Studente miglior_studente(Corso c, int n_studenti);

/*
    PRE: c è un corso, n_studenti è il numero di studenti (c è non vuoto se n_studenti!=0)
    POST: ordina gli studenti a seconda della loro media
*/
void ordina_studenti(Corso c, int n_studenti);
//NOTA: l'algoritmo di ordinamento da utilizzare è a vostra discrezione. E' consentito riadattare l'esercizio sul quicksort se volete



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
