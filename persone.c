#include <stdio.h>
#include <stdlib.h>
#include "persone.h"
#include "main.h"

/**
Si considerino le elezioni americane per la nomina del presidente degli stati uniti.
Si vuole gestire un insieme di candidati (non si conosce a priori la dimensione di tale insieme).
Ogni elemento di questo insieme � caratterizzato da un codice alfanumerico, nome e cognome del candidato
(si considerino tre stringhe). Quindi si vuole gestire l�insieme delle votazioni (non si conosce a priori
la dimensione di tale insieme). Ogni votazione � caratterizzata dal codice del candidato votato,
nome e cognome del votante (si considerino tre stringhe).

Es.

Candidati: ("abc","Barack","Obama"), (123","Mitt","Romney")

Voti: ("abc","Roberto","De Virgilio"), ("abc","Andrea","Rossi"),
      ("123","Mario","Verdi"), ("aaa","Mario","Neri");
*/

//CONTROLLA CHE IL CODICE SI TROVI NELLA LISTA CANDIDATI
int trovaElem(plist *p, stringa cod){
    plist temp=*p;
    while(temp!=NULL){
        if(temp->codice==cod){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//CANCELLA UN ELEMENTO DALLA LISTA PASSANDO LA POSIZIONE DELL'ELEMENTO DA CANCELLARE
void cancellaInPos(plist* l, int pos){
    plist prev,cur;
    int ln = personeTotali(l);
    if (ln<pos){
        printf("La lunghezza della lista %d e' minore della posizione fornita %d\n",ln,pos);
    }
    else{
        switch(pos) {
            case 0: printf("Hai fornito una posizione non valida\n");
            break;
            case 1: if (*l != NULL) {
                        plist temp = *l;
                        *l = temp->next;
                        free(temp);
                    }
                    else printf("La lista e' vuota\n");
            break;
            default:
                prev = *l;
                cur=prev->next;
                while (pos>2){
                    prev = cur;
                    cur = cur->next;
                    pos--;
                }
                prev->next=cur->next;
                free(cur);
        }
    }
}

//RESTITUISCE IL CODICE DEL CANDIDATO PASSANDO IL NOME ED IL COGNOME
stringa trovaCandidato(plist *p, stringa nome, stringa cognome){
    plist temp=*p;
    while(temp!=NULL){
        if(temp->nome==nome&&temp->cognome==cognome){
            return temp->codice;
        }
        temp=temp->next;
    }
    return 0;
}

//PERSONETOTALI FUNZIONANTE
int personeTotali(plist* persone){
    plist temp=*persone;
    int cont=0;
    while(temp!=NULL){
        cont++;
        temp=temp->next;
    }
    return cont;
}

//CONTEGGIO DEI VOTI NON VALIDI
int votiNonValidi(plist* voti, plist* candidati){
    plist temp=*voti;
    plist temp2=*candidati;
    int cont=0;
    while(temp!=NULL){
        if(trovaElem(&temp2,temp->codice)==0){
            cont++;
        }
        temp=temp->next;
    }
    return cont;
}

//CONTEGGIO VOTI DI UN CANDIDATO PASSANDO NOME E COGNOME
int numVotiCandidato(plist* votazioni, plist* candidati, stringa nomeCand, stringa cognCand){
    plist temp=*votazioni;
    plist temp2=*candidati;
    int cont=0;
    stringa codCand=trovaCandidato(&temp2,nomeCand,cognCand);
    if(codCand!=0){
        while(temp!=NULL){
            if(temp->codice==codCand){
                cont++;
            }
            temp=temp->next;
        }
    }
    return cont;
}

//RIMOZIONE VOTI NON VALIDI
void rimuoviVotiNonValidi(plist* voti, plist* candidati){
    plist temp=*voti;
    plist temp2=*candidati;
    int indice=0;;
    while(temp!=NULL){
        indice++;
        if(trovaElem(&temp2,temp->codice)==0){
            cancellaInPos(voti, indice);
        }
        temp=temp->next;
    }
}

//AGGIUNGE UNA PERSONA ALLA LISTA CANDIDATI O ALLA LISTA VOTAZIONI
void addPersona(plist* persone, stringa codice, stringa nome, stringa cognome){
    plist temp=(plist)malloc(sizeof(elist));
    temp->codice=codice;
    temp->nome=nome;
    temp->cognome=cognome;
    temp->next=*persone;
    *persone=temp;
    printf("persona aggiunta\n");
}

void elezioniByVins(){
    printf("*********************************************\n");
    printf("**************ELEZIONI BY VINS***************\n");
    printf("*********************************************\n");
    plist candidati=(plist)malloc(sizeof(elist));
    candidati=NULL;
    plist votazioni=(plist)malloc(sizeof(elist));
    votazioni=NULL;
    addPersona(&candidati, "aaa","davide","fella");
    addPersona(&votazioni, "aaa","andrea","barbadoro");
    addPersona(&votazioni, "a23","valerio","falcone");
    printf("numero di candidati %d\n",personeTotali(&candidati));
    printf("numero di votazioni %d\n",personeTotali(&votazioni));
    printf("numero di votazioni non valide %d\n",votiNonValidi(&votazioni,&candidati));
    printf("numero di votazioni ottenute dal candidato davide fella: %d\n",numVotiCandidato(&votazioni,&candidati,"davide","fella"));
    printf("rimozione voti non validi\n");
    rimuoviVotiNonValidi(&votazioni,&candidati);
    printf("numero di votazioni %d\n",personeTotali(&votazioni));
    printf("numero di votazioni non valide %d\n",votiNonValidi(&votazioni,&candidati));
    printf("\n---------------------------------------------\n");
    main();
}
