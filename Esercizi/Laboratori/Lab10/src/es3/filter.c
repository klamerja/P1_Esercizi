#include <advanced/list.h>
#include <stdlib.h>
#include <stdio.h>
/* Il seguente esercizio richiede la creazione di una funzione che filtra una lista creandone una nuova 
* con tutti e soli gli elementi, nello stesso ordine,che hanno un campo val maggiore o uguale a un certo 
* valore (la firma della funzione non è fornita).
*/

// filter(...)
/*Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali 
di una certa soglia (nello stesso ordine) */

/*
    PRE: val valore numerico, lista è il puntatore alla lista
    POST: occorrenze di info>=val nella lista
*/

void filter(struct nodo *lista, struct nodo **nuova_lista, int thres){
    int lung_lista=lung(lista);
    for(int i=0;i<lung_lista;i++){
        if(lista->info>=thres){
            suf_insert(nuova_lista, lista->info); //NON È UN ARRAY: NON HA BISOGNO DI ALLOCARE UN INTERO SPAZIO DI MEMORIA; SONO NODI COLLEGATI; BASTA CREARE IL NODO E "APPENDERLO; SE NE OCCUPA SUF_INSERT
            nuova_lista=&((*nuova_lista)->next);
        }
        lista=lista->next;
    }
}

int main(){
	struct nodo* list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        suf_insert(&list, val);
    }
    print_list(list);

    int thres;
    scanf("%d", &thres);

    //Filter
    struct nodo *nuova_lista=NULL; //ATTENZIONE: mettere a null o altrimenti si avrà segmentation fault se si va a leggere senza aver fatto niente (NULL diverso da non inizializzato)
    filter(list, &nuova_lista, thres);

    print_list(nuova_lista);
}