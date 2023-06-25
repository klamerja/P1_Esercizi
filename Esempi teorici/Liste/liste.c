#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

int is_empty(struct node *ptr);
void pre_insert(struct node **ptr, int value);
void print_list(struct node *ptr);
void suf_insert(struct node **ptr, int value);
void ord_insert(struct node **ptr, int val);
void push(struct node **ptr, int val);
void pop(struct node **ptr);


int main(){
    printf("Prima lista\n\n");

    struct node *list=NULL;
    printf("Lista vuota? %d\n", is_empty(list));

    pre_insert(&list,93);
    pre_insert(&list,7);
    pre_insert(&list,15);
    push(&list, 10);

    printf("Lista vuota? %d\n", is_empty(list));
    print_list(list);

    return 0;
}

int is_empty(struct node *ptr){
    return ptr == NULL;
}

void print_list(struct node *ptr){
    // struct node *tmp= ptr;
    // while(tmp->nexr != NULL) //Se io lo lancio adesso, va in segv, perché non esiste
    while(!is_empty(ptr)){
        printf("%d ", ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

//Possiamo avere due inserimenti: in testa, e in coda
//Inserimento in testa, quindi è una pila->crea un nuovo nodo, tenere il puntatore della testa, e spostare il puntatore della testa sul nuovo nodo
void pre_insert(struct node **ptr, int value){ //Ha side effect sulla memoria (modifica la memoria) [mi basta il puntatore o mi serve il puntatore a puntatore]
    struct node *tmp;

    tmp=*ptr; //ptr è puntatore a puntatore perché se voglio modificare l'indirizzo che punta alla testa, passerei solo per copia l'indirizzo alla funzione passando il puntatore a nodo

    *ptr=malloc(sizeof(struct node)); //Creo un nuovo ptr
    (*ptr)->val=value;
    (*ptr)->next=tmp;

    //Quindi, se passo *ptr e non **ptr, passo solo la copia del puntatore e se vado a modificare l'indirizzo del puntatore al nodo in testa
    //per aggiornarlo, i dati vengono persi perché per copia
}

//Inserimento in coda sfruttando quello in testa
void suf_insert(struct node **ptr, int value){
    while(!is_empty(*ptr)){
        //*ptr=(*ptr)->next; //Vado a sovvrascrivere l'indirizzo della testa della lista, quindi rimarrò solo con 81, nodo che lo sovvrascrive
        ptr=&((*ptr)->next); //Andiamo a modificare ptr in modo da mantenere i valori e non sovvrascriverlo

    }
    pre_insert(ptr, value); //è una FIFO, quindi ogni next rappresenta l'output successivo. Col ciclo arrivo fino a dopo l'ultimo elemento
    //cioè un NULL visto che non esiste, con pre_insert mi salvo in tmp l'indirizzo a NULL, metto value su next, e il next del ptr mandato conterrà il NULL
}

//Inserimento ordinato
void ord_insert(struct node **ptr, int val){
    while(*ptr!=NULL && (*ptr)->val<val){
        ptr=&((*ptr)->next);
    }
    pre_insert(ptr, val); //I next li salvo successivamente e in quella posizione la cambio col nodo di val
}

void push(struct node **ptr, int val){
    while(*ptr!=NULL)ptr=&((*ptr)->next);
    pre_insert(ptr, val);
}

// void pop(struct node **ptr){
//     if(ptr==NULL)printf("Pila vuota");
//     else if((*ptr)->next==NULL){
//         // *ptr = NULL; Fatto male
//         free(*ptr); //Fatto bene, cioè libero la memoria, cioè diventa null, quindi memoria liberata
//     }else{
//         struct node *tmp=*ptr
//         *ptr=(*ptr)->next;
//     }
// }