#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
typedef struct  node     //struttura autoreferenziale perchè presenta un campo next,
{                        //un puntatore dalla struttura stessa
    int  valore;
    char nome[100];
    struct  node* next;
}Node;

/*int contaRic(Node* l){
    if(l != NULL){
        contaRic(l->next) + 1;
    }else{
        return 0;
    }
}*/

/*void stampa(Node* l){
    Node* temp;
    int k = 0;
    while (l!=NULL && k < 5){ //l!=NULL equivale a farlo finchè non arrivo all'ultima cella
        printf("%d - %s \n",l->valore,l->nome);
        l = l->next;
        }
    k++;
    }*/


/*void inserisciHead(Node** head, int new_valore){ //node con doppio asterisco perchè poi devo andare ad essegnarlo alla testa

    Node* new_testa = (Node*) malloc (sizeof(Node));
    
    new_testa->valore = new_valore; //carico il nuovo valore nel node nuovo
    new_testa->next = (*head);      //il next punta alla testa attuale
    
    (*head) = new_testa;             // assegno la nuova testa

}*/

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

void elimina(Node* l){
    Node* temp;
    int k = 0;
    while(l->next!=NULL){
        printf("%d - %s \n",l->valore,l->nome);
        l = l->next;
        if(k == 4){
            temp = l->next;
            l->next = NULL;
            free(temp);
        }
    
        k++;
    }

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
        printf("Inserisci  un  valore e il nome del videogioco o -1 per  terminare\n");
        scanf("%d",&n);
        fflush(stdin);
        gets(nom);
        if(n != -1){
            Node *elem;
            elem = (Node*)  malloc(sizeof(Node));

            strcpy(elem->nome, nom);
            elem->valore = n;
            elem->next = NULL;

            inserisciPosizioneCasuale(&lista, elem);
            elimina(lista);
        }
    
    } while (n>=0); 
    
    /*inserisciHead(&lista,15);*/
    //stampa(l);
    
    
   
    }