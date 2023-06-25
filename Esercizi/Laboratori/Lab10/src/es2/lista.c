#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

//Prototipi
/*
    PRE: val è un valore numerico
    POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info = val
*/
struct nodo* new_nodo(int val);

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
    PRE: ptr è un puntatore ad una lista possibilmente vuota
    POST: lunghezza della lista
*/
int lung(struct nodo* ptr);

/*
    PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: return del campo info del nodo pos-esimo
*/
int get(struct nodo* ptr, int pos);

/*
    PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
    POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha campo info = val
*/
void modifica(struct nodo** ptr, int pos, int val);


//Main block
int main(){
    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        if(i%2==0){
            pre_insert(&list, val);
        }
        else suf_insert(&list, val);
    }
    print_list(list);

    //raddoppio ogni elemento della lista (codice qui)
    int lung_lista=lung(list);
    for(int i=0;i<lung_lista;i++){
        modifica(&list, i, get(list, i)*2);
    }
    print_list(list);
}



//Funzioni
struct nodo *new_nodo(int val){
    struct nodo *nuovo_nodo=malloc(sizeof(struct nodo));
    nuovo_nodo->info=val;
    nuovo_nodo->next=NULL;
    return nuovo_nodo;
}

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

void pre_insert(struct nodo **pptr, int val){
    struct nodo *tmp=*pptr; //Salvo il puntatore alla lista in una lista temporanea
    *pptr=malloc(sizeof(struct nodo)); //Ricreo la testa sul puntatore pptr
    (*pptr)->info=val;
    (*pptr)->next=tmp; //Quello che ho fatto è salvarmi TUTTA la lista in tmp, sul puntatore della testa ho ricreato un nuovo nodo con valore val e come next la lista antecedente alle modifiche
}

void suf_insert(struct nodo** pptr, int val){
    while(!is_empty(*pptr)){
        pptr=&((*pptr)->next); //Evito di modificare il puntatore del primo elemento per sovvrascriverlo, vado quindi a modificare la copia, cioè pptr
    }
    pre_insert(pptr, val); //Scorro tutta la lista (inserimento in coda). Con pre insert il ptr è a null, viene spostato a destra per inserire il nodo di val in testa a null, e successivamente vi è null
}

void suf_insert_easy(struct nodo** pptr, int val){
    while(!is_empty(*pptr)){
        pptr=&((*pptr)->next); //Evito di modificare il puntatore del primo elemento per sovvrascriverlo, vado quindi a modificare la copia, cioè pptr
    }
    *pptr=new_nodo(val);
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

int rec_lung(struct nodo* ptr){
    if(is_empty(ptr))return 0;
    return 1+lung(ptr->next);
}

int get(struct nodo* ptr, int pos){
    //Sappiamo che ptr è per forza valido, quindi niente check di null se posizione ancora in range
    while(pos!=0){
        pos--;
        ptr=ptr->next;
    }
    return ptr->info;
}

int rec_get(struct nodo* ptr, int pos){
    if(pos==0)return ptr->info;
    return rec_get(ptr->next, --pos);
}

void modifica(struct nodo** ptr, int pos, int val){
    while(pos!=0){
        pos--;
        ptr=&((*ptr)->next);
    }
    (*ptr)->info=val;
}

