#include <advanced/tree.h>

/* In questo esercizio vi chiediamo di scrivere una funzione che stampi le foglie di un albero BST in modo ordinato, da sinistra a destra.

Esempio:
          2
         / \
        1   3
       / \   \
      0   2   5
             /
            4

La funzione deve stampare: 0 2 4
La firma della funzione è void print_leaves(BST *ptr).
Potete usare le funzioni sugli alberi che trovate nella libreria advanced.
*/

/*
    PRE: ptr è la radice di un albero BST.
    POST: le foglie dell'albero di cui BST è la radice sono stampate in ordine, da sinistra verso destra.
*/
void print_leaves(BST *ptr);

int main(void) {
    BST *albero;
    init(&albero);

    //Da decommentare per la consegna su Moodle
    // int n_el, val;
    // scanf("%d", &n_el);
    // for(int i=0; i<n_el; i++){
    //     scanf("%d", &val);
    //     ordinsert_rec(&albero, val);
    // }
    
    //Da commentare per la consegna su Moodle
    /*Le seguenti istruzioni sono per i test in locale, per evitare di dover inserire i valori ogni volta.
    Modificate a piacere*/
    int values[] = {2,1,0,2,6,6,9,5};
    for(int i=0; i<8; i++){
        ordinsert_rec(&albero, values[i]);
    }

    // funzione da implementare
    print_scheme(albero);
    print_leaves(albero);  
    return 0;
}

void print_leaves(BST *ptr){
    if(ptr->leftPtr==NULL && ptr->rightPtr==NULL)printf("%d ", ptr->valore);
    else{
        if(ptr->leftPtr!=NULL)print_leaves(ptr->leftPtr);
        if(ptr->rightPtr!=NULL)print_leaves(ptr->rightPtr);
    }
}