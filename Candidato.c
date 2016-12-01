#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include "Candidato.h"

void inserisciCandidatoInCoda(candidato x, cnode *p){
    cnode *k = (cnode*)malloc(sizeof(cnode));   // Creo un nuovo nodo
    k->next = NULL;                             // Inizializzo il nuovo nodo
    k->info = x;

    while(p->next!=NULL)    // Scorre la lista fino all'ultimo elemento
        p=p->next;

    p->next = k;        // Aggiungo in coda il nuovo nodo
}


void addCandidato(cnode *listaCandidati, line nome, line cognome, line codice){
    candidato temp;

    //TODO: temp va inizializzato con i campi "nome","cognome" e codice

    inserisciCandidatoInCoda(temp, listaCandidati);
}
