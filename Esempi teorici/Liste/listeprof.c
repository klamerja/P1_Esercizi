#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *nextPtr;
};

typedef struct node List;

int isempty(struct node *ptr); //return: 1 se vuota, 0 altrimenti
void print_list(struct node *ptr);
void wrong_pre_insert(struct node *ptr, int val);
void pre_insert(struct node **ptr, int val);
void suf_insert(struct node **ptr, int val);
void ord_insert(struct node **ptr, int val);

// versioni alternative
struct node* pre_insert_bis(struct node *ptr, int val);
// versioni ricorsive
void print_list_rec(struct node *ptr);
void suf_insert_rec(struct node **ptr, int val);
// stack
void push(List **ptr, int val);
void pop(List **ptr);

int main(void) {

	struct node *list = NULL;

	printf("*** Primo esempio con liste ***\n\n");
	printf("Lista vuota? %d\n", isempty(list));
	print_list(list);

	//wrong_pre_insert(list, 93);
	pre_insert(&list, 93);
	pre_insert(&list, 5);
	//pre_insert(&list, 29);
	list = pre_insert_bis(list, 29);	
	//pre_insert(&list, 17);
	suf_insert(&list, 17);

	printf("Lista vuota? %d\n", isempty(list));
	print_list(list);
	printf("\n");

	printf("*** Implementazione di una pila ***\n\n");
	List *stack = NULL;

	push(&stack, 93);
	push(&stack, 5);
	push(&stack, 29);
	
	print_list_rec(stack);
	printf("\n");

	pop(&stack);
	pop(&stack);
	//pop(&stack);

	print_list_rec(stack);
	printf("\n");

	return 0;
}

int isempty(struct node *ptr) {

	if(ptr == NULL)
		return 1;
	else
		return 0;
}

void print_list(struct node *ptr) {

	while(ptr != NULL) {
		printf("%d ", ptr->value);
		ptr = ptr->nextPtr;
	}
	printf("\n");
}

void wrong_pre_insert(struct node *ptr, int val) {
	struct node *tmp;

	tmp = ptr;
	ptr = malloc(sizeof(struct node));
	ptr->value = val;
	ptr->nextPtr = tmp;
}

void pre_insert(struct node **ptr, int val) {
	struct node *tmp;

	tmp = *ptr;
	*ptr = malloc(sizeof(struct node));
	(*ptr)->value = val;
	(*ptr)->nextPtr = tmp;
}

void suf_insert(struct node **ptr, int val) {
	
	while(*ptr != NULL) {
		ptr = &((*ptr)->nextPtr);
	}
	pre_insert(ptr, val);
}

void ord_insert(struct node **ptr, int val){
	while(*ptr != NULL && val > (*ptr)->value) {
		ptr = &((*ptr)->nextPtr);
	}
	pre_insert(ptr, val);	
}

// versioni alternative
struct node* pre_insert_bis(struct node *ptr, int val){
	struct node *tmp;

	tmp = ptr;
	ptr = malloc(sizeof(struct node));
	ptr->value = val;
	ptr->nextPtr = tmp;
	return ptr;
}

// versioni ricorsive
void print_list_rec(struct node *ptr){

	if(ptr == NULL) {
		return;
	}
	else {		
		printf("%d ", ptr->value);
		print_list_rec(ptr->nextPtr);
	}

}

void suf_insert_rec(struct node **ptr, int val){
	
	if (*ptr == NULL) {
		pre_insert(ptr, val);
	}
	else {
		suf_insert_rec(&((*ptr)->nextPtr), val);
	}
}

// stack 
void push(List **ptr, int val){

	while(*ptr != NULL) {
		ptr = &((*ptr)->nextPtr);
	}
	pre_insert(ptr, val);
}

void pop(List **ptr){

    // verifica se lista vuota
    if(isempty(*ptr)) {
    //if(*ptr == NULL) {
        printf("La lista è vuota!\n");
    }
    else if((*ptr)->nextPtr == NULL) {
        //*ptr = NULL;    
        free(*ptr);
    }
    else {    
        List *tmpPtr, *current = *ptr;
        
        while(current->nextPtr != NULL) {
            tmpPtr = current;
            current = current->nextPtr;
        }
        // cancella elemento in coda
        //tmpPtr->nextPtr = NULL;
        free(current);
    }
}