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

void liste(){
    lista *l2=(lista*)malloc(sizeof(lista));
    l2=creaLista();
    printf("stampa valore nodo: %d",l2->info);
    free(l2);
}
