#include "stringheLib.h"
#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED
#endif // CANDIDATO_H_INCLUDED

typedef struct{
    stringa nome;
    stringa cognome;
    stringa codice;
}candidato;

typedef struct elem{
    candidato info;
    struct elem *next;
}cnode;

typedef cnode *candidati;

/* Aggiunge alla "lista" un candidato con nome, cognome e codice passati per parametro */
void addcandidato(candidati *lista, stringa nome, stringa cognome, stringa codice);

