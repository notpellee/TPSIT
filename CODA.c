#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct  node{
    int  valore;
    char nome[100];
    struct  node* next;
}Node;

void push(Node** head, int new_valore){

    Node* new_testa = (Node*) malloc (sizeof(Node));
    
    new_testa->valore = new_valore; 
    new_testa->next = (*head);     
    
    (*head) = new_testa;             

}

void stampa(Node* l){
    Node* temp;
    int k = 0;
    while (l!=NULL && k < 5){ 
        printf("%d \n",l->valore);
        l = l->next;
        }
    k++;
    }
    
int main(){

    int num;
    Node* lista;


    do{

        printf("inserisci il valore da inserire  o -1 per uscire");
        scanf("%d", &num);


        push(&lista,num);

    }while(num!=-1);
    
    stampa(lista);





}