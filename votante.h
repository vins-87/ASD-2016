#ifndef VOTANTE_H_INCLUDED
#define VOTANTE_H_INCLUDED
#endif // VOTANTE_H_INCLUDED
#include "candidato.h"
#include "lines.h"

/* Tipi e strutture */

typedef struct {
    line nome;
    line cognome;
    line codice;
}votante;

typedef struct elem2{
    votante info;
    struct elem2 *next;
}listaVotanti;

typedef listaVotanti *votanti;

/* Metodi */


/*  Aggiunge alla lista votanti, un votante con i parametri passati nell'argomento */
void addvoto(votanti *v, line nome, line cognome, line codice);

/* Conta la dimensione della lista v di votanti */
int numbervoti(votanti v);

/* Restituisce il numero di voti validi */
int checkvoti(votanti v, candidati c);

/* Restituisce il numero di voti che ha ottenuto quel candidato */
int counter(votanti v, candidati c, line nome, line cognome);

/* Rimuove dalla lista dei votanti, tutti i votanti che non hanno votato correttamente <Il loro codice non e' presente nella lista dei candidati>*/
void removeinvalid(votanti v, candidati c);
