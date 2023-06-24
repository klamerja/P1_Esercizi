#include <stdio.h>
#include <stdlib.h>

//Structs, Typedef e Prototipi
struct nodo{
    int val;
    struct nodo* next;
};

typedef struct nodo node;

int is_empty(node* ptr); //1 se vuota, 0 altrimenti
void print_list(node* ptr);
void pre_insert(node** ptr, int value);
void suf_insert(node** ptr, int value);

//Main block
int main(){
    printf("Prima lista\n\n");
    node* list=NULL;

    printf("Lista vuota?%d\n", is_empty(list));

    return 0;
}

//Funzioni
int is_empty(node* ptr){
    return ptr==NULL;
}

void print_list(node* ptr){
    while(is_empty(ptr)){
        printf("%d ", ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

void pre_insert(node** ptr, int value){ 
    node* old_ptr=*ptr;
    *ptr=malloc(sizeof(node));
    (*ptr)->val=value;
}

void suf_insert(node **ptr, int value){ //Analizzare bene
    node* tmp=*ptr;
    while(is_empty(*ptr)){
        ptr=&((*ptr)->next);
    }
    stack_insert(ptr, value);
}
