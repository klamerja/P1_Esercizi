//----studente.c---//
#define N_VOTI 5

//----studente.c----//
typedef struct studente {
    char nome[20];
    char cognome[20];
    int voti[N_VOTI];
} Studente;

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


//----corso.c----//
//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente *Corso;

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

