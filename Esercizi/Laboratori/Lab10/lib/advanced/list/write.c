#include "../list.h"

struct nodo *new_nodo(int val){
    struct nodo *nuovo_nodo=malloc(sizeof(struct nodo));
    nuovo_nodo->info=val;
    nuovo_nodo->next=NULL;
    return nuovo_nodo;
}

void pre_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    nuovo->next = *pptr;
    *pptr = nuovo;
}

void suf_insert(struct nodo** pptr, int val){
    while(!is_empty(*pptr)){
        pptr=&((*pptr)->next); //Evito di modificare il puntatore del primo elemento per sovvrascriverlo, vado quindi a modificare la copia, cioè pptr
    }
    pre_insert(pptr, val); //Scorro tutta la lista (inserimento in coda). Con pre insert il ptr è a null, viene spostato a destra per inserire il nodo di val in testa a null, e successivamente vi è null
}

// void suf_insert_easy(struct nodo** pptr, int val){
//     while(!is_empty(*pptr)){
//         pptr=&((*pptr)->next); //Evito di modificare il puntatore del primo elemento per sovvrascriverlo, vado quindi a modificare la copia, cioè pptr
//     }
//     *pptr=new_nodo(val);
// }

void modifica(struct nodo** ptr, int pos, int val){
    while(pos!=0){
        pos--;
        ptr=&((*ptr)->next);
    }
    (*ptr)->info=val;
}

void delete_list(struct nodo* ptr){
    if (ptr == NULL) return;
    delete_list(ptr->next);
    free(ptr);
}