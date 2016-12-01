#include "lines.h"

#ifndef VOTANTE_H
#define VOTANTE_H


#endif // VOTANTE_H

typedef struct{
    line nome;
    line cognome;
    line codice;
}votante;

typedef struct elem2{
    votante info;
    struct elem2 *next
}vnode;

typedef vnode *votanti;   // Adesso 'votanti' è un tipo, per definire il nodo radice di una lista con informazione votante

void addVotante(vnode *votanti, line nome, line cognome, line codice);
