#ifndef VOTO_H_INCLUDED
#define VOTO_H_INCLUDED
#endif // VOTO_H_INCLUDED
#include "stringheLib.h"
#include "candidato.h"

typedef struct{
    stringa nome;
    stringa cognome;
    stringa codice;
}voto;

typedef struct elem2{
    voto info;
    struct elem2 *next;
}vnode;

typedef vnode *voti;


/*  Aggiunge alla lista votanti, un votante con i parametri passati nell'argomento */
void addvoto(voti *v, stringa nome, stringa cognome, stringa codice);

/* Conta la dimensione della lista v di voti */
int numbervoti(voti v);

/* Restituisce il numero di voti validi */
int checkvoti(voti v, candidati c);

/* Restituisce il numero di voti che ha ottenuto quel candidato */
int counter(voti v, candidati c, stringa nome, stringa cognome);

/* Rimuove dalla lista dei votanti, tutti i votanti che non hanno votato correttamente <Il loro codice non e' presente nella lista dei candidati>*/
void removeinvalid(voti v, candidati c);
