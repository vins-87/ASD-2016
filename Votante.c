#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include "Votante.h"


void inserisciVotanteInCoda(votante x, vnode *p){
    vnode *k = (vnode*)malloc(sizeof(vnode));   // Creo un nuovo nodo
    k->next = NULL;                             // Inizializzo il nuovo nodo
    k->info = x;

    while(p->next!=NULL)    // Scorre la lista fino all'ultimo elemento
        p=p->next;

    p->next = k;        // Aggiungo in coda il nuovo nodo
}


void addVotante(vnode *listaVotanti, line nome, line cognome, line codice){
    votante temp;

    //TODO: temp va inizializzato con i campi "nome","cognome" e codice

    inserisciVotanteInCoda(temp,listaVotanti);
}
