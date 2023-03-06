#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

typedef struct node{
    char dati;
    struct node *next;
}Node;

int is_empty(struct node *head){
    if(head == NULL) return 1;
    else return 0;

}

void push(struct node **head, struct node *element){
    if(is_empty(*head)){
        *head = element;
        element -> next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Node *pop(Node **head){
    Node *ret = *head;
    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;

    return ret;
    
}

int main(){
    char stringa[MAX]= "{[( bjdhbcjhd )]}";
    Node *pila;
    Node *elemento;
    Node *temp;
    bool continua = true;
    int k = 0;
    while(stringa[k] != '\0' && continua == true){
        if(stringa[k] == '{' || stringa[k] == '[' || stringa[k] == '('){
            elemento = (Node*)malloc(sizeof(Node));
            elemento->dati = stringa[k];
            push(&pila, elemento);
        }else if (stringa[k] == '}' || stringa[k] == ']' || stringa[k] == ')'){
            elemento = (Node*)malloc(sizeof(Node));
            temp = pop(&pila);
            if ((stringa[k] == '}' && temp->dati == '{') || (stringa[k] == ']' && temp->dati == '[') || (stringa[k] == ')' && temp->dati == '('))
            continua = true;
            else
            continua = false;
        }

        k++;
        
    };

    if(is_empty(pila))
        printf("non ci sono errori");
    else
        printf("si sono verificati degli errori");

    return 0;

}
