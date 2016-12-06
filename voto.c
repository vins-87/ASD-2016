#include <stdio.h>
#include <stdlib.h>
#include "voto.h"



/*  Aggiunge alla lista votanti, un votante con i parametri passati nell'argomento */
void addvoto(voti *v, stringa nome, stringa cognome, stringa codice){
    voto *nuovo = (voto*)malloc(sizeof(voto));

    /* Inizializza nuovo voto */

    copia(nome, nuovo->nome);
    copia(cognome, nuovo->cognome);
    copia(codice, nuovo->codice);

    /* Inserisci il nuovo voto nella lista IN TESTA*/

    voti temp = (voti)malloc(sizeof(vnode));

    temp->info = *nuovo;
    temp->next = *v;
    *v=temp;
}

/* Conta la dimensione della lista v di votanti */
int numbervoti(voti v){

    int result = 0;

    while(v!=NULL){
        result++;
        v = v->next;
    }

    return result-1;    // il numero di nodi della lista meno la radice
}

int checkVotoSuListaCandidati(voto v, candidati c){

    while(c!=NULL){
        if(confronta(v.codice, c->info.codice)==1)
            return 1;
        c = c->next;
    }
    return 0;
}

/* Restituisce il numero di voti validi */
int checkvoti(voti v, candidati c){

    int result = 0;

    while(v!=NULL){
        result = result + checkVotoSuListaCandidati(v->info, c);
        v = v->next;
    }

    return result-1;    // il numero di nodi della lista meno la radice
}

candidato *selezionaCandidato(candidati c,stringa nome,stringa cognome){

candidato *temp = (candidato*)malloc(sizeof(candidato));

    while(c!=NULL){
        *temp = c->info;
        if(confronta(temp->nome, nome)==1 && confronta(temp->cognome, cognome)==1)
            return temp;
        c = c->next;
    }

    return NULL;
}

int contaVotiDelCandidato(voti v, candidato c){

    voto temp;
    int result = 0;

    while(v!=NULL){
        temp = v->info;

        if(confronta(temp.codice, c.codice)==1)
            result++;

        v = v->next;
    }

    return result;
}

/* Restituisce il numero di voti che ha ottenuto quel candidato */
int counter(voti v, candidati c, stringa nome, stringa cognome){

    /* Seleziona il candidato dalla lista */
    candidato *temp = (candidato*)malloc(sizeof(candidato));

    temp = selezionaCandidato(c,nome,cognome);

    if(temp!=NULL)
        return contaVotiDelCandidato(v,*temp);

    return 0;
}

/* Rimuove dalla lista dei votanti, tutti i votanti che non hanno votato correttamente <Il loro codice non e' presente nella lista dei candidati>*/
void removeinvalid(voti v, candidati c){



}
