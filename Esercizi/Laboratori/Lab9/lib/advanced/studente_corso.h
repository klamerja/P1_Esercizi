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

