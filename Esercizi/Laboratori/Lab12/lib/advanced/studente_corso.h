#define N_VOTI 5

typedef struct studente {
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;



//----studente.h---//
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




//----corso.c----//
//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente *Corso;

/*
    PRE: esame compreso tra 0 e N_VOTI
    POST: calcola la ratio di superamento dell'esame (solo guardando gli studenti che hanno conseguito un voto, chi non ha fatto l'esame non è contato). Se nessuno ha fatto l'esame la percentuale è 0.
*/
float percentuale_superamento_test(Corso s, int n_studenti, int esame);

/*
    PRE: s è un corso non vuoto
    POST: restituisce lo studente con la media più alta. Se più di uno studente ha stessa media viene preso quello con indice minore.
*/
Studente miglior_studente(Corso s, int n_studenti);

/*
    PRE: c è un corso, n_studenti è il numero di studenti (c è non vuoto se n_studenti!=0)
    POST: ordina gli studenti a seconda della loro media
*/
void ordina_studenti(Corso s, int n_studenti);