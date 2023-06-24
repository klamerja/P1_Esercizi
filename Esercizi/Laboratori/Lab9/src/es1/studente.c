#include <basic/array.h>
#include <stdio.h>

#define N_VOTI 5

//DEFINIZIONE: uno studente è rappresentato da un nome, un cognome e una serie di voti per numero N_VOTI di esami
//I voti vanno da 0 a 30. Se un esame non è stato svolto il valore del voto è -1.
typedef struct studente{
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;



//Prototipi
/*
    PRE: s è uno studente valido (voti compresi tra 0 e 30 oppure uguali a -1)
    POST: calcolare la media dei voti conseguiti (esami svolti). Se non ci sono voti la media è 0.
*/
float calcola_media(Studente s);

/*
    PRE: s è uno studente valido
    POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti
*/
int sufficienza_studente(Studente s);

/*
    PRE: s è uno studente valido
    POST: stampa le info degli studenti
*/
void print_studente(Studente s);
//Funzione di utilità per stampare a schermo tutti i dati dello studente. Seguire l'esempio riportato di seguito.
/* Esempio di stampa
 * Nome: Michele 
 * Cognome: Poggi
 * Voti: [1,2,3,4,5]
 */



//Main bloc
int main(){
    Studente s;
    
    //lettura dati studente da tastiera
    scanf("%s %s", s.nome, s.cognome);

    //lettura voti da line di comando
    for(int i=0; i<N_VOTI; i++){
        scanf("%d", s.voti + i);
    }

    //calcolo status studente
    print_studente(s);
    printf("Media: %f\n", calcola_media(s));
    if(sufficienza_studente(s)==1)
        printf("Sufficiente\n");
    else printf("Non sufficiente\n");
}



//Funzioni
float calcola_media(Studente s){
    int esami_svolti=N_VOTI;
    float sum_voti=0;
    for(int i=0;i<N_VOTI;i++){
        if(s.voti[i]==-1)esami_svolti--;
        else sum_voti+=s.voti[i];
    }
    if(esami_svolti==0)return 0.0;
    return sum_voti/esami_svolti;
}

int sufficienza_studente(Studente s){
    return calcola_media(s)>=18;
}

void print_studente(Studente s){
    printf("Nome: %s\nCognome: %s\n", s.nome, s.cognome);
    printf("Voti: ");
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}