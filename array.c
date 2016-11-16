/************************************************-ATTENZIONE-**********************************************************
Tutti i metodi sono in ordine di utilizzo nella funzione vet(), così come sono nell'ordine specificato nel file array.h
***********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//CREA ARRAY DA INPUT E RITORNA IL PUNTATORE AD ESSA
int* creaArray(int dim){
    int *v;
    int i;
    v=(int*)calloc(M,sizeof(int));
    printf("\nInserisci %d elementi nell'array\n",M);
    for(i=0;i<M;i++)
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
    for(i=0;i<M;i++){
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

    for(i=0;i<M;i++){       //Per ogni elemento a[i] del vettore
        posmin=i;
        min=a[i];

        for(j=i+1;j<M;j++){ //Per ogni elemento della parte successiva a a[i] del vettore

            if(min>a[j]){   //Condizione di minimo
                posmin=j;
                min=a[j];
            }

        }

        if(posmin!=i){          // Scambio l'elemento in posizione i-esima con l'elemento in posizione di minimo
            a[posmin] = a[i];
            a[i] = min;
        }

    }
}


/* Utilizza la logica degli indirizzi per stampare l'array */
void stampaArray(int *v){
    int i;

    for(i=0; i<M;i++)
        printf("%d ",v[i]);
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
    int max;

    v=creaArray(M);
    max=maxElemArray(v,M);
    printf("massimo elemento dell'array = %d\n",max);
    pariDispari(v,M);

    v=creaArray(M);
    sort(v);
    printf("\nArray ordinato:\n");
    stampaArray(v);

    v=creaArray(M);
    max=maxElemArray(v,M);
    printf("\nmassimo elemento dell'array = %d\n",max);
    pariDispari(v,M);
    potenza(3,2);

    int ris;
    int n1,n2;

    n1=3;
    n2=4;
    ris=potenzaRicorsiva(n1,n2);
    printf("\npotenza ricorsiva di %d elevato a %d = %d\n",n1,n2,ris);
}
