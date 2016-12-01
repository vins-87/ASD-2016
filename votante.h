#ifndef VOTANTE_H_INCLUDED
#define VOTANTE_H_INCLUDED
#endif // VOTANTE_H_INCLUDED
#include "candidato.h"

/* Tipi e strutture */

typedef struct {

}votante;

typedef struct elem2{
    votante info;
    struct elem2 *next;
}listaVotanti;

typedef listaVotanti *votanti;

/* Metodi */

void addvoto(votanti *v, line nome, line cognome, line codice);

int numbervoti(votanti *v);

int checkvoti(votanti *v, candidati *c);

int counter(votanti *v, candidati *c, line nome, line cognome);

void removeinvalid(votanti v, candidati c);
