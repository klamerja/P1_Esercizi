#include <advanced/tree.h>
#include <stdio.h>
#include <stdlib.h>

int size(BST *ptr){
    if(ptr==NULL)return 0;
    return size(ptr->leftPtr)+size(ptr->rightPtr)+1; //Cioè ogni volta che scorro un nodo, lo sommo (+1) e vado a sommare ricorsivamente i nodi figli, se non sono NULL
}

//PRE: albero non vuoto passato per riferimento, pos posizione valida al suo interno
void delete_pos(BST **ptrPtr, unsigned pos){
    int size_l=size((*ptrPtr)->leftPtr); //Vado a trovare quanti nodi ho sul ramo sinistro
    if(pos==size_l){
        //Ho trovato il nodo->devo capire come cancellarlo
        //Caso foglia
        if((*ptrPtr)->leftPtr==NULL && (*ptrPtr)->leftPtr==NULL){
            free(*ptrPtr);
            *ptrPtr=NULL;
        }
        else if((*ptrPtr)->leftPtr!=NULL && (*ptrPtr)->leftPtr!=NULL){ //Caso successori doppi
            BST *gps=(*ptrPtr)->rightPtr; //Creo un puntatore che punta inizialmente al ramo destro di ptrptr
            while(gps->leftPtr!=NULL){ //Scorro fino all'ultimo elemento di ptrptr
                gps=gps->leftPtr;
            }
            gps->leftPtr=(*ptrPtr)->leftPtr; //Nodo sinistro di gps viene impostato col nodo sinistro di ptrptr (trasferimento) -> gps= non va bene
            //var di tipo puntatore = var di tipo puntatore, rimane la copia del puntatore, ma non è una deref
            //Io devo modificare l'indirizzo contenuto nel leftptr dell'elemento più a sinistra del ramo destro
            //Quindi in gps ho quel nodo, dereferenziandolo posso accedere ai suoi dati
            //Se con gps mi posiziono in null, io semplicemente scrivo null nel puntatore, e poi lo riscrivo con l'indirizzo del ramo sinistro che devo spostare, ma perdo i dati
            BST *tmp=(*ptrPtr)->rightPtr;
            free(*ptrPtr);
            *ptrPtr=tmp;
        }
        else if((*ptrPtr)->leftPtr!=NULL){ //Caso: successore sinistro
            BST *tmp=(*ptrPtr)->leftPtr;
            free(*ptrPtr);
            *ptrPtr=tmp;
        }
        else{ //Caso successore destro
            BST *tmp=(*ptrPtr)->rightPtr;
            free(*ptrPtr);
            *ptrPtr=tmp;
        }
    }
    else if(pos<size_l){
        delete_pos(&((*ptrPtr)->leftPtr), pos); //Vado a fare la ricorsione e mi sposto verso sinistra finché non trovo il nodo
    }
    else{
        delete_pos(&((*ptrPtr)->rightPtr), pos-size_l-1);
    }
}
//POST: elimina nodo in posizione data, il risultato deve essere sempre un BST

int main(){
    BST *albero;
    init(&albero);

    //Da decommentare per la consegna su Moodle
    /*int n_el, val;
    scanf("%d", &n_el);
    for(int i=0; i<n_el; i++){
        scanf("%d", &val);
        ordinsert_rec(&albero, val);
    }*/
    
    //Da commentare per la consegna su Moodle
    /*Le seguenti istruzioni sono per i test in locale, per evitare di dover inserire i valori ogni volta.
    Modificate a piacere*/
    int values[] = {2,1,0,2,6,6,9,5};
    for(int i=0; i<8; i++){
        ordinsert_rec(&albero, values[i]);
    }
    print_scheme(albero);
    printf("\n");

    //Da decommentare per la consegna su Moodle
    /*int pos;
    scanf("%d", &n_el);
    for(int i=0; i<n_el; i++){
        scanf("%d", &pos);
        delete_pos(&albero, pos);
    }*/
    
    //Da commentare per la consegna su Moodle
    /*Le seguenti istruzioni sono per i test in locale, per evitare di dover inserire i valori ogni volta.
    Modificate a piacere*/
    delete_pos(&albero,1);
    //delete_pos(&albero,5);

    if(albero != NULL) print_scheme(albero);
    return 0;
}
