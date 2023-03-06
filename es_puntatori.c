#include <stdio.h>
#define MAX 4

int main() {

    int vett[MAX];

    int *a = vett;

    int b = 0;

    while((a - vett) < MAX){
        *a = b;
        a++;
        b++;

    }

    a = vett;

    while((a - vett)  < MAX) {
        printf("%d \t", *a);
        a++;
    }

}


