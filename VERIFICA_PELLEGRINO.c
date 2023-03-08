/*
 * Author:Nicola
 * Date: 08/02/2023
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>

#define MAX 10
#define MIN 1
#define MAXELEMENTI 5

typedef struct node {
    int NUMERO_ARRIVO;
    int VALORE;
    struct node *next;
} Node;

bool isEmpty(Node *list) {
    return list == NULL;
}

void push(Node **head, Node *el) {
    if (!isEmpty(*head))
        el->next = *head;
    else
        el->next = NULL;
    *head = el;
}

Node *pop(Node **head) {
    if (isEmpty(*head))
        return NULL;
    Node *ret = *head;
    *head = ret->next;
    return ret;
}

//funzione che stampa
void stampaCoda(Node *queue) {
    if (isEmpty(queue))
        return;
    printf("\nnumero coda: %d, %d", queue->NUMERO_ARRIVO, queue->VALORE);
    if (queue->next != NULL)
        stampaCoda(queue->next);
}

//stampa pila
void stampaPila(Node *l) {
    //printf("STAMPA CON PROC: \n");
    while (l != NULL)                                  //puntatore alla lista diversa da NULL
    {
        printf("\nstampa pila: %d %d", l->NUMERO_ARRIVO, l->VALORE);
        l = l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}

//funzione enqueu inserisce elementi
void enqueu(Node **head, Node **tail, Node *element) {
    if (isEmpty(*head)) {
        *head = element;
    } else {
        (*tail)->next = element;
    }
    *tail = element;
    element->next = NULL;
}

//funzione dequeu per l'estrazione del dato
Node *dequeu(Node **head, Node **tail) {
    Node *ret = *head;
    if (isEmpty(*head))
        return NULL;
    *head = ret->next;

    if (isEmpty(*head)) {
        *tail = NULL;
    }
    return ret;
}

void freeQueue(Node *queue) {
    if (queue->next != NULL)
        freeQueue(queue->next);
    free(queue);
}

void freePila(Node *l) {
    if (l->next != NULL)
        freePila(l->next);
    free(l);
}

int main() {
    //head e tail del nuovo processo
    Node *h = NULL;
    Node *t = NULL;
    int x, x1;
    bool g=true, pilaControllo=false, codaControllo=false;

    srand(time(NULL));
    int quanti= MAX-MIN+1;
    Node *coda = NULL;

    Node *pila = NULL;
    Node *pila1=NULL;


    for(int k=0; k<MAXELEMENTI; k++){
        printf("entrato\n");
        x= rand() % quanti+MIN;
        pila1 = (Node *) malloc(sizeof(Node));
        pila1->NUMERO_ARRIVO=k+1;
        pila1->VALORE=x;
        push(&pila, pila1);

        //-----------------------
        x1= rand() % quanti+MIN;
        coda = (Node *) malloc(sizeof(Node));
        coda->NUMERO_ARRIVO = k+1;
        coda->VALORE = x1;
        coda->next=NULL;
        enqueu(&h, &t, coda);
    }
    //printf("uscito\n");
    stampaCoda(h);
    printf("\n");
    stampaPila(pila);
    printf("\n\n");

    while (g == true) {
        //printf("ecco\n");
        if (isEmpty(h) || isEmpty(pila)) {
            if (isEmpty(h)) {
                printf("\nvince la pila\n");
                pilaControllo = true;
                g=false;
            } else if (isEmpty(pila)) {
                printf("\nvince la coda\n");
                codaControllo=true;
                g=false;
            } else g = false;
        }else {
            Node*exitPila=pop(&pila);
            Node*exitCoda= dequeu(&h, &t);
            //stampaPila(pila);
            //stampaCoda(h);
            if(exitPila->VALORE!=exitCoda->VALORE){
                if(exitPila->VALORE>exitCoda->VALORE){
                    printf("valore della pila %d vince contro il valore della coda %d\n", exitPila->VALORE, exitCoda->VALORE);
                    exitPila->VALORE-=exitCoda->VALORE;
                    printf("valore rimanente: %d\n\n", exitPila->VALORE);
                    push(&pila, exitPila);

                }else{
                    printf("valore della coda %d vince contro il valore della pila %d\n", exitCoda->VALORE, exitPila->VALORE);
                    exitCoda->VALORE-=exitPila->VALORE;
                    printf("valore rimanente: %d\n\n", exitCoda->VALORE);
                    enqueu(&h, &t, exitCoda);
                }
            }else{
                printf("pareggio tra il valore della pila %d e il valore della coda %d\n", exitPila->VALORE, exitCoda->VALORE);
            }
        }
    }
    //printf("uscito\n");
    if(pilaControllo) stampaPila(pila);
    else if(codaControllo) stampaCoda(h);
    freeQueue(t);
    freePila(pila);
    return 0;
}

