#ifndef PERSONE_H
#define PERSONE_H


typedef char* stringa;

typedef struct elem{
    stringa codice;
    stringa nome;
    stringa cognome;
    struct elem *next;
}elist;

typedef elist* plist;

#endif // PERSONE_H

int trovaElem(plist *p, stringa cod);
void cancellaInPos(plist* l, int pos);
stringa trovaCandidato(plist *p, stringa nome, stringa cognome);

//funzioni per aggiungere una votazione e un candidato ai rispettivi insiemi
void addPersona(plist* persone, stringa codice, stringa nome, stringa cognome);

//dato l’insieme di voti, ritornare la dimensione dell’insieme (numero di voti). Nell’esempio abbiamo 4 voti
int personeTotali(plist* persone);

/*dato l’insieme di voti e l’insieme di candidati, contare quanti voti non sono validi
(voti che hanno un codice che non corrisponde ad alcun candidato nell’insieme dei candidati).
Nell’esempio abbiamo solo 3 voti validi. Il voto ("aaa","Mario","Neri") non è valido
poiché contiene il codice "aaa" che non corrisponde ad alcun candidato*/
int votiNonValidi(plist* voti, plist* candidati);

/*dato l’insieme dei voti, l’insieme dei candidati e nome e cognome di un candidato,
contare quanti voti ha ottenuto quel candidato. Nell’esempio, dato "Barack" "Obama"
otteniamo 2 voti aventi codice "abc" corrispondente al candidato con quel nome e quel cognome.*/
int numVotiCandidato(plist* votazioni, plist* candidati, stringa nomeCand, stringa cognCand);

/*dato l’insieme dei voti e l’insieme dei candidati, rimuovere dall’insieme dei voti tutti gli elementi non validi
(quei voti che hanno un codice che non corrisponde ad alcun candidato nell’insieme dei candidati).
Nell’esempio dobbiamo eliminare l’elemento ("aaa","Mario","Neri")*/
void rimuoviVotiNonValidi(plist* voti, plist* candidati);
void elezioniByVins();
