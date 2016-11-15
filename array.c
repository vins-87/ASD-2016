/************************************************-ATTENZIONE-**********************************************************
Tutti i metodi sono in ordine di utilizzo nella funzione vet(), così come sono nell'ordine specificato nel file array.h
***********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int N = 10;     // Dimensione array (il #define non mi funzionava..

//CREA ARRAY DA INPUT E RITORNA IL PUNTATORE AD ESSA
int* creaArray(int N){
    int *v;
    int i;
    v=(int*)calloc(N,sizeof(int));
    printf("inserisci %d elementi nell'array\n",N);
    for(i=0;i<N;i++)
        scanf("%d",&v[i]);
    return v;
}

int maxElemArray(int *v, int N){
    int i;
    int max;
    max=v[0];
    for(i=0;i<N;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

/*  Esercizio: Scrivere un programma che data una sequenza di 10 numeri interi calcoli
    Il numero di valori pari (e quindi anche di valori dispari)
    Quale dei due numeri sia maggiore (messaggio su video)
*/
void pariDispari(int *a, int N){
    int i;
    int np=0;
    int nd=0;
    for(i=0;i<N;i++){
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

/*
    Funzione che prende il puntatore a un vettore come parametro. Ordina il vettore tramite selection sort.
    La logica utilizzata per scandire è quella degli indirizzi.
    Per chiarezza:  a[0] = *a;
                    a[4] = *(a+4);
    E' stato utilizzato un aloritmo di selection-sort come richiesto dall'esercizio
*/
void sort(int *a){
    int i;
    int j;
    int posmin;
    int min;

    for(i=0;*(a+i)<N;i++){       //Per ogni elemento a[i] del vettore
        posmin=i;
        min=*(a+i);

        for(j=i+1;*(a+j)<N;j++){ //Per ogni elemento della parte successiva a a[i] del vettore

            if(min>*(a+j)){   //Condizione di minimo
                posmin=j;
                min=*(a+j);
            }

        }

        if(posmin!=i){          // Scambio l'elemento in posizione i-esima con l'elemento in posizione di minimo
            *(a+posmin)=*(a+i); // a[posmin] = a[i]
            *(a+i)=min;         // a[i] = min
        }

    }
}


/* Utilizza la logica degli indirizzi per stampare l'array */
void stampaArray(int *v){
    int i;

    for(i=0; *(v+i)<N;i++)
        printf("%d ",*(v+i));
}

void vet(){
    int *v;
    int max;
    v=creaArray(N);
    max=maxElemArray(v,N);
    printf("massimo elemento dell'array = %d\n",max);
    pariDispari(v,N);
    sort(v);
    printf("Array ordinato:\n");
    stampaArray(v);
}
