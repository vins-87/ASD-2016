#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"

void addcandidato(candidati *lista, stringa nome, stringa cognome, stringa codice){
    candidato *nuovo = (candidato*)malloc(sizeof(candidato));

    /* Inizializza il nuovo candidato */

    copia(nome, nuovo->nome);
    copia(cognome, nuovo->cognome);
    copia(codice, nuovo->codice);

    /* Aggiungi il candidato alla lista INSERIMENTO IN TESTA */

    candidati l = (candidati)malloc(sizeof(cnode));

    l->info = *nuovo;
    l->next = *lista;
    *lista = l;

}

