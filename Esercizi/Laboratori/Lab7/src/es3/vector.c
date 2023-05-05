#include<stdio.h>
#include<stdlib.h>
#include<basic/array.h>

//Prototipi
/*
    PRE: v è un vettore passato per riferimento
    POST: inizializza il vettore con capacity 1 e senza nessun elemento.
*/
void init_vector(int** v);

/*
    PRE: il vettore è inizializzato e pos è un numero tra 0 e size -1 compreso
    POST: aggiunge un elemento data in posizione pos. Se necessario, la capacity del vettore viene raddoppiata
*/
void insert_element(int** v, int data, unsigned int pos, unsigned int *size, unsigned int *capacity);

/*
    PRE: v1 è un riferimento a un vettore inizializzato, con size = s e capacity = c, v2 è un vettore o un array di size n_elem
    POST: v1 contiene il risultato della concatenazione tra v1 e v2
*/
void concat_vectors(int** v1, int* v2, unsigned int n_elem, unsigned int *s, unsigned int *c);

//Main
int main(){
    int *vector;
    int n_elem;

    //inizializzazione del vettore
    init_vector(&vector);
    // variabili che tengono traccia di size e capacity
    unsigned int size = 0, capacity = 1;

    scanf("%d", &n_elem);

    //inserimento di n_elem da standard input
    int elem;
    for(int i=0; i<n_elem; i+=1){
        scanf("%d", &elem);
        insert_element(&vector, elem, i, &size, &capacity);
    }

    //lettura di un secondo array, non dinamico
    scanf("%d", &n_elem);
    int second_vec[n_elem];
    leggi_array(second_vec, n_elem);

    //concatenazione tra vector e array
    concat_vectors(&vector, second_vec, n_elem, &size, &capacity);

    stampa_array(vector, size);
    printf("\n");
    printf("%d\n", capacity);
}

//Funzioni
void init_vector(int **v){
    *v=(int*)malloc(sizeof(int));
}

void insert_element(int** v, int data, unsigned int pos, unsigned int *size, unsigned int *capacity){
    (*size)++;
    if((*capacity)<(*size)){
        (*capacity)*=2;
        *v=(int*)realloc(*v, *capacity * sizeof(int));
    }
    for(int i=(*size)-1;i>pos;i--){
        *(v+i)=*(v+i-1);
    }
    *(*v+pos)=data;
}

void concat_vectors(int** v1, int* v2, unsigned int n_elem, unsigned int *s, unsigned int *c){
    for(int i=0;i<n_elem;i++){
        insert_element(v1, *(v2+i), *s, s, c);
    }
}

