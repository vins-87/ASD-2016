#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED
#endif // CANDIDATO_H_INCLUDED
#include "lines.h"

/* Tipi e strutture */

typedef struct{
    line nome;
    line cognome;
    line codice;
}candidato;

typedef struct elemC{
    candidato info;
    struct elem *next;
}listaCandidati;

typedef listaCandidati *candidati;

/* Metodi */

