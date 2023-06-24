#include<stdio.h>
#include<stdlib.h>

/*
    Siamo nel bel mezzo del torneo di Karate "All Valley KarateTournament". Il torneo è ad eliminazione diretta, ovvero, all'inizio di ogni fase, che supponiamo avere un numero pari di squadre N,vengono selezionati casualmente N/2 accoppiamenti. Ogni coppia di squadre si affronta, il vincitore passa alla fase successiva, nella quale si ripete lo stesso procedimento fino alla fine del torneo. 
    Dovete scrivere una funzione che effettui un sorteggio degli accoppiamenti per la fase successiva in modo casuale. 
    La lista delle squadre è rappresentata da un array di stringhe: squadre. 
    Al termine del sorteggio (rimescolamento degli elementi dell'array) gli accoppiamenti saranno i seguenti: 
    squadre[0] sfiderà squadre[1]
    squadre[2] sfiderà squadre[3]
    squadre[4] sfiderà squadre[5], e così via...
    L'esercizio non ha test perché esistono molti modi corretti di effettuare un sorteggio casuale. Caricate lo stesso l'esercizio su Moodle. 
*/

#define NUM_SQUADRE 8

void stampa_array(char **X, int size);
void sorteggio(char **squadre, int size);
void scambia_squadra(char** s1, char** s2);


int main(void) {

    //Array di 8 puntatori a char
    char *squadre[NUM_SQUADRE] = {"Cobra Kai Dojo", "Miyagi-Do Karate", 
                                "Locust Valley Karate Club", "Topanga Karate","Xtreme Martial Arts", "All Star Karate", "Krunch Karate", "Cutting Edge Karate"};
    
    srand(42);

    stampa_array(squadre, NUM_SQUADRE);
    sorteggio(squadre, NUM_SQUADRE); //squadre è il puntatore del primo elemento dell'array di puntatori, quindi un puntatore di puntatore -> tipo= char**
    stampa_array(squadre, NUM_SQUADRE);

}


/*
    PRE: X è un puntatore ad un array di dimensione size 
    POST: stampati a video gli elementi di X a coppie, una coppia per ogni riga
*/
void stampa_array(char **X, int size) {
    for(int i=0; i<size; i+=2)
        printf("%s - %s\n", X[i], X[i+1]);
    printf("\n");
}

/*
    PRE: squadre è un puntatore ad un array (di puntatori a char) di dimensione size
    POST: rimescolamento dell'array in maniera casuale
*/
void sorteggio(char **squadre, int size){ //Doppio asterisco perché passo il puntatore del primo elemento dell'array, che è un puntatore a char, quindi squadre è puntatore a puntatore
    for(int i=0;i<size;i++){
        //Trovo j per poter scambiare la i-esima squadra con una j-esima
        int rand_squad=rand()%size;
        //Scambio le due squadre
        scambia_squadra((squadre+i), (squadre+rand_squad)); //Essendo un puntatore ad un array, scorro gli elementi dell'array di puntatori, dopo dereferenzio per ottenere l'indirizzo del primo carattere della stringa, cioè il puntatore alla stringa
    }
}

/*
    PRE: due stringhe da scambiare
    POST: scambio di s1 e di s2
*/
void scambia_squadra(char** s1, char** s2){
    char *tmp=*s1; //Mi memorizzo il puntatore della stringa s1 (quindi l'indirizzo di memoria)
    *s1=*s2; //s1 adesso punta a s2, quindi se derefenzio s1, sarà il valore dereferenziato di s2
    *s2=tmp;
}

//Prima scambia squadra aveva come parametri due puntatori a char, ma se io passo il puntatore della squadra, lo passo per copia, quindi se vado a cambiarlo, comunque non lo modifico nell'array di squadre
//ma solo internamente, perché se l'array di puntatori a char ha 2 elementi, se io passo a parametro questi due puntatori, posso modificarne il valore interno, ma non il loro indirizzo all'interno dell'array,
//che è quello che voglio fare
