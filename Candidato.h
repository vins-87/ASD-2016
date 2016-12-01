#include "lines.h"

#ifndef CANDIDATO_H
#define CANDIDATO_H


#endif // CANDIDATO_H

typedef struct{
    line nome;
    line cognome;
    line codice;
}candidato;

typedef struct elem{
    candidato info;
    struct elem *next
}cnode;

typedef cnode *candidati;   // Adesso 'candidati' è un tipo, per definire il nodo radice di una lista con informazione candidati

void addCandidato(cnode *listaCandidati, line nome, line cognome, line codice);
