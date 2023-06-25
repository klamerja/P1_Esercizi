#include "../list.h"

int is_empty(struct nodo *ptr){
    return ptr==NULL;
}

void print_list(struct nodo *ptr){
    if(is_empty(ptr))printf("Vuota\n");
    else{
        while(!is_empty(ptr)){
            printf("%d ", ptr->info);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int lung(struct nodo* ptr){
    if(is_empty(ptr))return 0;
    if(is_empty(ptr->next))return 1;
    int counter=0;
    while(!is_empty(ptr)){
        counter++;
        ptr=ptr->next;
    }
    return counter; //Potrei anche omettere le prime due righe, ma è indifferente
}

// int rec_lung(struct nodo* ptr){
//     if(is_empty(ptr))return 0;
//     return 1+lung(ptr->next);
// }

int get(struct nodo* ptr, int pos){
    //Sappiamo che ptr è per forza valido, quindi niente check di null se posizione ancora in range
    while(pos!=0){
        pos--;
        ptr=ptr->next;
    }
    return ptr->info;
}

// int rec_get(struct nodo* ptr, int pos){
//     if(pos==0)return ptr->info;
//     return rec_get(ptr->next, --pos);
// }



