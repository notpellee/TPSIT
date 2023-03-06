#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct pila{

    float num;
    struct pila *next;

}Pila;

typedef struct coda{
    float num;
    struct processo *next;
}Coda;

int is_empty_Coda(Coda* head){
    if(head == NULL) return 1;
    else return 0;
}

int is_empty_Pila(Pila* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Coda** head, Coda** tail, Coda* element){
    if(is_empty_Coda(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;

    if(is_empty_Coda(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

void push(struct pila **head, struct pila *element){
    if(is_empty_Pila(*head)){
        *head = element;
        element -> next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Pila *pop(Pila **head){
    Pila *ret = *head;
    if(is_empty_Pila(*head))
        return NULL;
    else
        *head = ret->next;

    return ret;
    
}

void stampaCoda(Coda *p){
    while(p != NULL){
        printf("%f\n", p->num);
        p = p->next;
    }
}

void stampaPila(Pila *p){
    while(p != NULL){
        printf("%f\n", p->num);
        p = p->next;
    }
}



int main(){

    Pila* pila;
    Coda* coda;

    Pila *testa_pila= NULL;  
    Pila *coda_pila = NULL;

    Coda *coda_testa = NULL;
    Coda *coda_coda = NULL;

    coda= (Coda*)malloc(sizeof(Coda));
    pila= (Pila*)malloc(sizeof(Pila));

    Pila* elemento_coda;
    Pila* elemento_pila;

    for(int k = 0; k < MAX; k++){
        printf("inserisci valore da inserire nella coda\n");
        scanf("%f", &coda->num);
        printf("inserisci valore da inserire nella pila\n");
        scanf("%f", &pila->num);

    }

    stampaCoda(coda_testa);
    stampaPila(testa_pila);

    while(is_empty_Coda(coda_testa) || is_empty_Pila(testa_pila)){
        elemento_coda = dequeue(&coda_testa, &coda_coda);
        elemento_pila= pop(&testa_pila);

        printf("numero estratto coda = %f\n", elemento_coda);
        printf("numero estratto pila %f\n", elemento_pila);

        if(elemento_coda > elemento_pila){
            
            enqueue(&coda_testa, &coda_coda, (elemento_coda-elemento_pila));
            printf("vincitore : %f\n", elemento_coda);

        } else if (elemento_pila > elemento_coda){

            push(&testa_pila, (elemento_pila-elemento_coda));
            printf("vincitore : %f\n", elemento_pila);
        }
    }

    if(is_empty_Coda(coda_testa)){
        printf("struttura vincente = pila\n");
        stampaCoda(coda_testa);
    }else if(is_empty_Pila(testa_pila)){
        printf("struttira vincente = coda\n");
        stampaPila(testa_pila);
    }

    


}
