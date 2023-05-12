#include<basic/array.h>
#include <advanced/studente_corso.h>
#include<stdio.h>
#define N_VOTI 5

//DEFINIZIONE: uno studente è rappresentato da un nome, un cognome e una serie di voti per numero N_VOTI di esami
//I voti vanno da 0 a 30. Se un esame non è stato svolto il valore del voto è -1.
typedef struct studente {
    char nome[20];
    char cognome[20];
    int voti[N_VOTI];
} Studente;

//Prototipi
/*
    PRE: Uno studente qualsiasi
    POST: media dei suoi voti, contenuti nell'array voti (NB: non vengono presi in considerazione i -1)
*/
float calcola_media(Studente s);

//PRE: s è uno studente valido
/*
    PRE: Uno studente qualsiasi
    POST: restituisce 1 se la media dei voti è >= a 18, 0 altrimenti
*/
int sufficienza_studente(Studente s);

/*
    PRE: Uno studente qualsiasi
    POST: Stampa a video di tutte le sue informazioni: nome, cognome e tutti i suoi voti
*/
void print_studente(Studente s);


//Main block
int main(){
    Studente s;
    
    //Lettura dati studente da tastiera
    scanf("%s %s", s.nome, s.cognome);

    //lettura voti da line di comando
    for(int i=0; i<N_VOTI; i++){
        do{
            scanf("%d", s.voti + i);
        }while(*(s.voti+i)>30 || *(s.voti+i)<(-1));
    }

    //Calcolo status studente
    print_studente(s);
    printf("Media: %f\n", calcola_media(s));
    if(sufficienza_studente(s)==1)
        printf("Sufficiente\n");
    else printf("Non sufficiente\n");
}



//Funzioni
float calcola_media(Studente s){
    int sum=0; //Somma dei voti
    int num_esami_svolti=N_VOTI; //Numero di esami svolti dallo studente
    for(int i=0;i<N_VOTI;i++){
        if(s.voti[i]==-1)num_esami_svolti--;
        else sum+=s.voti[i]; 
    }
    if(num_esami_svolti==0)return 0.0;
    float avg=(float)sum / num_esami_svolti;
    return avg;
}

int sufficienza_studente(Studente s){
    //Controllo con ritorno se la media dello studente è sufficiente
    return calcola_media(s)>=18.0;
}

void print_studente(Studente s){
    //Stampa del nome e del cognome
    printf("Nome: %s\n", s.nome);
    printf("Cognome: %s\n", s.cognome);
    //Stampa dei voti
    printf("Voti: ");
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}