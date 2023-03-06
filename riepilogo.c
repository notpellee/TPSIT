#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20
#define MAX 100
#define NUM 4


typedef char* stringa[DIM];

typedef struct
{
    stringa *cognome;
    stringa *nome;
    int data;
}Dati;

void readFile(Dati *p){

    Dati *a = p;
    FILE *fp;
    char* riga;

    fp = fopen("riepilogo.cvs","r");

    if (fp != NULL){
        riga = (char*) malloc( 100 * sizeof(char));
        while (fgets(riga,MAX,fp))
        {
            (*a).cognome = strtok(riga, ",");
            (*a).nome = strtok(NULL, ",");
            (*a).data = atoi(strtok(NULL,","));

            printf ("%s %s %d\n", a->cognome, a->nome, a->data);

            a++;

            riga = (char*) malloc( 100 * sizeof(char));
            
        }

        free(riga);
    }

    fclose(fp);
}

void ordina(Dati *a){
    Dati temp;
    Dati *b = a;

    for (int k = NUM-1; k > 0; k--)
    {
        for (int j = 0; j < k; j++)
        {
            if ((b).data > (b+1).data)
            {
                temp = *(b);
                *(b) = *(b + 1);
                *(b + 1) = temp;
            }

            b++;
        }
    }

        b = a;

    for (int k = 0; k < NUM; k++,b++){

        printf("%s %s %d\n", b->cognome, b->nome, b->data);


    }

}

int main(){

Dati *p;
p = (Dati*) malloc( 4 * sizeof(Dati));
readFile(p);
ordina(p);

}
