#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//CREA ARRAY DA INPUT E RITORNA IL PUNTATORE AD ESSA
int* creaArray(int dim){
    int *v;
    int i;
    v=(int*)calloc(dim,sizeof(int));
    printf("inserisci %d elementi nell'array\n",dim);
    for(i=0;i<dim;i++)
        scanf("%d",&v[i]);
    return v;
}

int maxElemArray(int *v, int dim){
    int i;
    int max;
    max=v[0];
    for(i=0;i<dim;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

/*  Esercizio: Scrivere un programma che data una sequenza di 10 numeri interi calcoli
    Il numero di valori pari (e quindi anche di valori dispari)
    Quale dei due numeri sia maggiore (messaggio su video)
*/
void pariDispari(int *a, int dim){
    int i;
    int np=0;
    int nd=0;
    for(i=0;i<dim;i++){
        printf("%d ",a[i]);
        if(a[i]%2==0)
            np++;
        else
            nd++;
    }
    if(np>nd)
        printf("ci sono piu numeri pari che dispari\n");
    else{
        if(np<nd)
            printf("ci sono piu numeri dispari che pari\n");
        else
            printf("c'e la stessa quantita di numeri pari e dispari\n");
    }
}

void vet(){
    int *v;
    int dim=10;
    int max;
    v=creaArray(dim);
    max=maxElemArray(v,dim);
    printf("massimo elemento dell'array = %d\n",max);
    pariDispari(v,dim);
}
