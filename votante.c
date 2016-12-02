#include <stdio.h>
#include "votante.h"

votanti *creaNodoConVotante(votante vot){
    votanti *result = (votanti*)malloc(sizeof(votanti));

    result->info = vot;
    result->next = NULL;

    return result;
}

void aggiungiInCodaVotante(votanti v, votante temp){
    if(v==NULL)
        return;

    while(v->next!=NULL)
        v=v->next;

    v->next=creaNodoConVotante(temp);
}

/*  Aggiunge alla lista votanti, un votante con i parametri passati nell'argomento */

void addvoto(votanti *v, line nome, line cognome, line codice){
    votante temp;
    temp->nome = nome;
    temp->cognome = cognome;
    temp->codice = codice;

    aggiungiInCodaVotante(*v,temp);
}

/* Conta la dimensione della lista v di votanti */
int numbervoti(votanti v){
    int result = 0;

    while(v!=NULL){
        result++;
        v=v->next;
    }

    return result;
}

int checkValiditaVotoSuListaCandidati(votante v, candidati c){
    int result = 0;

    while(c!=NULL){
        line codice = v->codice;
        if(confrontaLinee(codice,c->info->codice))
            result++;
        c = c->next;
    }

    return result;
}

/* Restituisce il numero di voti validi */
int checkvoti(votanti v, candidati c){
    int result = 0;

    while(v!=NULL){
        result = result + checkValiditaVotoSuListaCandidati(v->info,c);
        v=v->next;
    }

    return result;
}
