#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

/* read.c */
/*
    PRE: puntatore alla lista (possibilmente vuota)
    POST: return 1 se la lista è vuota, 0 altrimenti
*/
int is_empty(struct nodo *ptr);

/*
    PRE: ptr è il puntatore ad una lista possibilmente vuota
    POST: stampa a video il contenuto della lista, "Vuota" se non ci sono elementi
*/
void print_list(struct nodo *ptr);

int lung(struct nodo* ptr);

/*
    PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: return del campo info del nodo pos-esimo
*/
int get(struct nodo* ptr, int pos);


/* write.c */
/*
    PRE: val è un valore numerico
    POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info = val
*/
struct nodo* new_nodo(int val);

/*
    PRE: pptr è il puntatore al puntatore della lista (ci permette di modificare gli indirizzi dei nodi)
    POST: inserimento in testa di val (inizio lista ed è l'elemento su cui si sviluppano i next);
*/
void pre_insert(struct nodo** pptr, int val);

/*
    PRE: pptr è il puntatore al puntatore della lista
    POST: inserimento in coda (fine lista)
*/
void suf_insert(struct nodo** pptr, int val);

/*
    PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha campo info = val
*/
void modifica(struct nodo** ptr, int pos, int val);

/*
    PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: restituisce il primo nodo della lista, che è quella originale, con un nodo aggiunto in posizione pos avente campo info == val
*/
struct nodo* insert(struct nodo* ptr, int pos, int info);

/*
    PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: restituisce il primo nodo della lista che è quella originale senza il nodo in posizione pos, che è stato eliminato
*/
struct nodo* delete(struct nodo* ptr, int pos);

// PRE: ptr è il primo nodo di una lista (possibilmente vuota) passata per riferimento
void delete_list(struct nodo* ptr);
// POST:la lista è stata interamente eliminata
