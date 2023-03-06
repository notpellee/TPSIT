#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define NR 30
#define LUN 20

void caricaMatrice(char v[][LUN], int n_occorrenze){
    for(int k=0; k<n_occorrenze; k++){
        printf("Inserisci la stringa %d: ", k+1);
        fflush(stdin);
        gets(v[k]);
        }
}

void stampaMatrice(char v[][LUN], int n_occorrenze){
    for(int c=0; c<n_occorrenze; c++){
        printf("%s\n", v[c]);
    }
}

void ordinamentoMatriceCrescente(char v[][LUN], int n_occorrenze){
    int k,sup;
    char t[n_occorrenze];
    bool sca;
    sup=n_occorrenze-1;
    sca=true;
    while ((sup>0) && sca==true) {
        sca=false;
        for (k = 0; k < sup; k++) {
            if (strcmp(v[k], v[k+1])>0) {
                strcpy(t,v[k]);
                strcpy(v[k], v[k+1]);
                strcpy(v[k+1], t);
                sca=true;
            }
        }
        sup--;
    }
}

void ordinamentoMatriceDecrescente(char v[][LUN], int n_occorrenze){
    int k,sup;
    char t[n_occorrenze];
    bool sca;
    sup=n_occorrenze-1;
    sca=true;
    while ((sup>0) && sca==true) {
        sca=false;
        for (k = 0; k < sup; k++) {
            if (strcmp(v[k], v[k+1])<0) {
                strcpy(t,v[k]);
                strcpy(v[k], v[k+1]);
                strcpy(v[k+1], t);
                sca=true;
            }
        }
        sup--;
    }
}

int RicSeqNODMATRICE(char vett[][LUN], int dim, char stringa_cercata[]) {
    int k=0;
    int tro = -1;
    while (k<dim && tro == -1) {
        if (strcmp(vett[k],stringa_cercata)==0) {
            tro = k;
        }
        k++;
    }
    return tro;
}

int RicSeqODMATRICE(char vett[][LUN], int dim, char stringa_cercata[]) {
    int k=0;
    int tro = -1;
    bool continua = true;
    while (k<dim && tro == -1 && continua==true) {
        if (strcmp(vett[k],stringa_cercata)==0) {
            tro = k;
        } else if (strcmp(vett[k],stringa_cercata)<0)
            continua = false;   //inutile continuare a cercarlo
        k++;
    }
    return tro;
}

int RicSeqNONDMATRICE(char vett[][LUN], int dim, char stringa_cercata[]) {
    int k=0;
    int n_occorrenze = 0;
    for (int k=0; k<dim; k++) {
        if (strcmp(vett[k],stringa_cercata)==0)
            n_occorrenze++;
    }
    return(n_occorrenze);
}

int RicSeqONDMATRICE(int vett[], int dim, char stringa_cercata[]) {
    int k=0;
    int n_occorrenze = 0;
    bool continua = true;
    while (k<dim && continua==true) {
        if (strcmp(vett[k],stringa_cercata)) {
            n_occorrenze++;
        } else if (strcmp(vett[k],stringa_cercata)<0)
            continua = false;   //inutile continuare a cercarlo
        k++;
    }
    return n_occorrenze;
}
