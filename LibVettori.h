#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

/*
- non ord       disg
-     ord       disg
- non ord   non disg
-     ord   non disg
*/

int chiediDimensione(int max) {
    int n;
    do {
        printf("Inserisci la dimensione: \n");
        scanf("%d", &n);
    } while (n<0 || n>max);

    return n;
}
int RicSeqNOD(int vett[], int dim, int x) {
    int k=0;
    int tro = -1;
    while (k<dim && tro == -1) {
        if (vett[k]==x) {
            tro = k;
        }
        k++;
    }
    return tro;
}

int RicSeqOD(int vett[], int dim, int x) {
    int k=0;
    int tro = -1;
    bool continua = true;
    while (k<dim && tro == -1 && continua==true) {
        if (vett[k]==x) {
            tro = k;
        } else if (vett[k] > x)
            continua = false;   //inutile continuare a cercarlo
        k++;
    }
    return tro;
}

int RicSeqNOND(int vett[], int dim, int x) {
    int k=0;
    int n_occorrenze = 0;
    for (int k=0; k<dim; k++) {
        if (vett[k] ==x)
            n_occorrenze++;
    }
    return(n_occorrenze);
}

int RicSeqOND(int vett[], int dim, int x) {
    int k=0;
    int n_occorrenze = 0;
    bool continua = true;
    while (k<dim && continua==true) {
        if (vett[k]==x) {
            n_occorrenze++;
        } else if (vett[k] > x)
            continua = false;   //inutile continuare a cercarlo
        k++;
    }
    return n_occorrenze;
}


//SCAMBIOFLOAT
//scambia i valori tra due variabili
void scambiaFloat(float *x, float *y) {
    float t;
    t=*y;
    *y=*x;
    *x=t;
}

//COPIA VETTORI:
//copia i valori interi di un vettore in un altro
void copiaVettoriInteri (int vett[], int dim, int vet[]) {
    int i=dim-1;//contatore
    for (int c = 0; c<dim; c++) {
        vet[c]=vett[i];//inizializzazione vettore da 0 alvettore da DV
        i--;//aggiornamento del contatore
    }
}

//COPIA VETTORI:
//copia i valori reali di un vettore in un altro
void copiaVettoriReali (float vett[], int dim, float vet[]) {
    int i=dim-1;//contatore
    for (int c = 0; c<dim; c++) {
        vet[c]=vett[i];//inizializzazione vettore da 0 alvettore da DV
        i--;//aggiornamento del contatore
    }
}

//INVERTI CON VETTORE DI SUPPORTO:
//inverte i valori del vettore di interi passato tramite un vettore di supporto
void invertiConVettoreInteri (int vett[], int dim, int vet[]) {
    int i=dim-1;
    for (int c = 0; c<dim; c++) {
        vet[c]=vett[i];
        i--;
    }
}

//INVERTI CON VETTORE DI SUPPORTO:
//inverte i valori del vettore di reali passato tramite un vettore di supporto
void invertiConVettoreReali (float vett[], int dim, float vet[]) {
    int i=dim-1;
    for (int c = 0; c<dim; c++) {
        vet[c]=vett[i];
        i--;
    }
}

//INVERTI SENZA VETTORE DI SUPPORTO:
//inverte i valori del vettore di interi passato senza l'utilizzo di un vettore di supporto
void invertiSenzaVettoreInteri(int vett[], int dim) {
    int t;
    int i=dim-1;
    for (int c=0; c<dim/2; c++, i--) {
        t = vett[c];
        vett[c] = vett[i];
        vett[i] = t;
    }
}

//INVERTI SENZA VETTORE DI SUPPORTO:
//inverte i valori del vettore di reali passato senza l'utilizzo di un vettore di supporto
void invertiSenzaVettoreReali(int vett[], int dim) {
    float t;
    int i=dim-1;
    for (int c=0; c<dim/2; c++, i--) {
        t = vett[c];
        vett[c] = vett[i];
        vett[i] = t;
    }
}

//CARICA VALORI REALI SU UN VETTORE:
//carica su un vettore dei valori reali
void caricaReali (float vett[], int dim) {
    for (int c =0; c<dim; c++) {
        printf("Inserisci l'elemento [%d]: ", c);
        scanf("%f", &vett[c]);
    }
}

//CARICA VALORI INTERI SU UN VETTORE:
//carica su un vettore dei valori interi
void caricaInteri (int vett[], int dim) {
    for (int c =0; c<dim; c++) {
        printf("Inserisci l'elemento [%d]: ", c);
        scanf("%d", &vett[c]);
    }
}

//CARICA VALORI INTERI CASUALI SU UN VETTORE:
//carica su un vettore dei valori interi
void caricaInteriCasuali (int vett[], int dim, int maxn, int minn) {
    int q=maxn-minn +1;
    int x;
    srand(time(NULL));
    for (int c =0; c<dim; c++) {
        x=minn+rand() % q;
        vett[c]=x;
    }
}

//STAMPA A SCHERMO I VALORI INTERI DI UN VETTORE
//stampa a schermo tramite un for i valori in ordine di un vettore di interi
void visualizzaInteri (int vett[], int dim) {
    for (int c=0; c<dim; c++) {
        printf("%d\t", vett[c]);
    }
    printf("\n");
}

//STAMPA A SCHERMO I VALORI REALI DI UN VETTORE
//stampa a schermo tramite un for i valori in ordine di un vettore di reali
void visualizzaReali (float vett[], int dim) {
    for (int c=0; c<dim; c++) {
        printf("%f\t", vett[c]);
    }
}

//INIZIALIZZA AL DOPPIO
//inizializza i valori di un numero al proprio doppio
void vettoreDoppio (int v1[], int v2[], int dim) {
    for (int c=0; c<dim; c++) {
        v2[c]=v1[c]*2;
    }
}

//CONTROLLO VALORE
//controllo di un determinato valore scritto da tastiera nel vettore, e conta quante volte esso appare
void controlloValore (float vett[], int dim1, float val, int k) {
    for (int c=0; c<dim1; c++) {
        if (vett[c]==val)//se il vettore vale come il valore scelto
            k++;//aumento del contatore
    }
    printf("Il numero scelto appare %d volte", k);
}

//SOMMA PARI E DISPARI
//somma i valori del vettore presenti in posizione pari e dei valori del vettore presenti in posizione dispari
void sommaPosPariDispari(int vett[], int dim, int sop, int sod) {
    for (int c=0; c<dim; c++) {
        if (c%2==0)
            sop=sop+vett[c];//se posizione pari aggiornamento della somma più valore del vettore
        else
            sod=sod+vett[c];//se posizione dispari aggiornamento della somma più valore del vettore
    }
    printf("La somma dei numeri pari e': %d\n", sop);//output, somma dei valori della somma dei numeri nelle posizioni pari
    printf("La somma dei numeri dispari e': %d", sod);//output, somma dei valori della somma dei numeri nelle posizioni dispari
}

//SOMMA NUMERI POSIZIONE E MULTIPLI
//somma i valori del vettore presenti in posizione pari al numero e ai suoi multipli
int sommaNumPosizione(int vett[], int dim, int pos) {
    int s=0;
    for (int c=3; c<dim; c+=pos) {
        s=s+vett[c];
    }
    return(s);
}

//SOMMA DEI NUMERI NEL VETTORE
//somma tutti i numeri
int sommaNumeri(int vett[], int dim) {
    int s=0;
    for (int c=0; c<dim ; c++) {
        s=s+vett[c];
    }
    return(s);
}

//CONTROLLO SE SONO TUTTI POSITIVI
bool tuttiPositivi(int vett[], int dim) {
    bool pos=true;
    int k;
    while (pos == true && k<dim) {
        if (vett[k]<0)
            pos=false;
        k++;
    }
    return (pos);
}

//SOMMA PARI
//somma dei numeri pari
int sommaPari(int vett[], int dim) {
    int s=0;
    for (int c=0; c<dim; c++) {
        if (vett[c]%2==0)
            s=s+vett[c];
    }
    return(s);
}

//SOMMA DISPARI
//somma dei numeri dispari
int sommaDispari(int vett[], int dim) {
    int s=0;
    for (int c=0; c<dim; c++) {
        if (vett[c]%2==1)
            s=s+vett[c];
    }
    return(s);
}

void bubbleSort1(int vett[], int n) {
    int k, sup, t;
    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k+1])
                t=vett[k];
                vett[k]=vett[k+1];
                vett[k+1]=t;
        }
    }
}

void selectionSort(int v[],int n) {
    /*Si cerca il minimo ad ogni ciclo e si fa al massimo un solo scambio a ciclo.
    Quando sistemo il penultimo elemento automaticamente è sistemato l’ultimo*/
    int k,kmin,j,t;
    for(k = 0; k < n-1; k++) {
        kmin = k;
        for(j = k+1; j < n; j++) {
            if(v[kmin] > v[j]) // confronti
                kmin = j;
        }
        if(kmin != k)
            t=v[k];
                v[k]=v[k+1];
                v[k+1]=t; //scambi
    }
    return;
}


//vettore in ordine decrescente
void bubbleSort1DEC(int vett[], int n) {
    int k, sup, t;
    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] < vett[k+1])
                t=vett[k];
                vett[k]=vett[k+1];
                vett[k+1]=t;
        }
    }
}
