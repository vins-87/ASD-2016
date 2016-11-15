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

//  Esercizio: Scrivere un programma per calcolare la potenza b di un numero intero a (con b >= 0).
void potenza(int num, int pot){
    int ris=1;
    int i;
    for(i=0;i<pot;i++){
        ris=ris*num;
    }
    printf("%d elevato a %d = %d\n",num,pot,ris);
}

/*  Esercizio: Scrivere un programma per calcolare la potenza b di un numero intero a (con b >= 0).
    Questa volta però utilizzando una funzione ricorsiva.
*/
int potenzaRicorsiva(int num, int pot){
    if(pot==1)
        return num;
    else{
        num=num*potenzaRicorsiva(num,pot-1);
    }
    return num;
}

void vet(){
    int *v;
    int dim=10;
    int max;
    v=creaArray(dim);
    max=maxElemArray(v,dim);
    printf("\nmassimo elemento dell'array = %d\n",max);
    pariDispari(v,dim);
    potenza(3,2);
    int ris;
    int n1,n2;
    n1=3;
    n2=4;
    ris=potenzaRicorsiva(n1,n2);
    printf("\npotenza ricorsiva di %d elevato a %d = %d\n",n1,n2,ris);
}
