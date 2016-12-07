#ifndef LISTE_H
#define LISTE_H

typedef struct nodo{
    struct nodo *prev;
    struct nodo *next;
    int info;
}lista;

/* scrivi qui sotto la definizione del tipo "elist" (elemento
   della lista) con i campi "info" (intero) e "next"
   (prossimo elemento) */
typedef struct elem{
    int info;
    struct elem *next;
}elist;

/* scrivi qui sotto la definizione del tipo "plist" che e'
   un riferimento ad un oggetto di tipo "elist" */
typedef elist *plist;

#endif // LISTE_H
void stampaLista(plist p);
int valore_massimo_lista(plist p);
int compara_array_lista(int A[], int n, plist p);
void inserisciInCoda(plist *p, int n);
int trovaElem(plist *p, int n);
lista* creaLista();
plist creaElist();
void liste();
