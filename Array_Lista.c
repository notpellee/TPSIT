#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#define NUM 5
typedef struct  node     //struttura autoreferenziale perchè presenta un campo next,
{                        //un puntatore dalla struttura stessa
    int vett[NUM];
    struct  node* next;
}Node;

/*int contaRic(Node* l){
    if(l != NULL){
        contaRic(l->next) + 1;
    }else{
        return 0;
    }
}*/

void stampa(Node* l){
    int k = 0;
    while (l!=NULL && k < 5){ //l!=NULL equivale a farlo finchè non arrivo all'ultima cella
        printf("%d - %s \n",l->valore,l->nome);
        l = l->next;
    k++;
    }
}

void dealloca(Node *lista){
    Node *temp;

    if(lista!=NULL){
        temp = lista;
        lista = lista->next;
        free(list);
        dealloca(temp);
    }
}

void inserisciPosizioneCasuale(Node** head, Node *element){
    Node *curr = *head, *prev = NULL;
    

    while(curr != NULL){
        if(element->valore >= curr->valore)
            break;
    prev = curr;
    curr = curr->next;
    }

    if(prev == NULL)
        *head = element;
    else
        prev->next = element;

    element->next = curr;
    
}

int  main()
{
    int n;              
    Node* lista;        //tipi di puntatori a node
    Node* l;
    char nom[30];
    lista=NULL;     //è vuoto
    
    do
    {   
        for(int k = 0; k < NUM; k++){
            printf("inserisci %d elemento");
            scanf("%d", & vett[k]);
        }
        if(n != -1){
            Node *elem;
            elem = (Node*)  malloc(sizeof(Node));

            strcpy(elem->nome, nom);
            elem->valore = n;
            elem->next = NULL;

            inserisciPosizioneCasuale(&lista, elem);
        }
    
    } while (n>=0); 
    
    /*inserisciHead(&lista,15);*/

    l = lista;
    stampa(l);
    dealloca(lista);
    
   
    }