#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

lista* creaLista(){
    lista *l1=(lista*)malloc(sizeof(lista));
    l1->prev=NULL;
    l1->next=NULL;
    l1->info=0;
    return l1;
}

void inserisciInCoda(int x, lista *p){
    lista *k = (lista*)malloc(sizeof(lista));   // Creo un nuovo nodo
    k->next = NULL;                             // Inizializzo il nuovo nodo
    k->info = x;

    while(p->next!=NULL)    // Scorre la lista fino all'ultimo elemento
        p=p->next;

    k->prev = p;        // Aggiorno il precedente del nuovo nodo

    p->next = k;        // Aggiungo in coda il nuovo nodo

}

void inserisciInTesta(int x, lista *p){
    lista *k = (lista*)malloc(sizeof(lista));
    k->prev = NULL;
    k->info = x;
    k->next = p;
    p=k;
}

/* TEST */
int testInserimentoInCoda(){
    int result = 0;
    int CASES = 4;
    int i;

    lista *l = (lista*)malloc(sizeof(lista));
    l = creaLista();

    inserisciInCoda(1,l);
    inserisciInCoda(2,l);
    inserisciInCoda(3,l);
    inserisciInCoda(4,l);

    l=l->next;

    for(i=1;i<CASES+1;i++){
        if(l->info==i)
            result++;
        l=l->next;
    }

    if(result == CASES)
        return 1;
    else
        return 0;

}

void liste(){
    lista *l2=(lista*)malloc(sizeof(lista));
    l2=creaLista();
    printf("stampa valore nodo: %d",l2->info);   // Stampa valore primo elemento della lista
    printf("\nTest di inserimento in coda risulta: %d", testInserimentoInCoda());

    free(l2);
}
