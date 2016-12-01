#ifndef LISTE_H
#define LISTE_H

typedef struct nodo{
    struct nodo *prev;
    struct nodo *next;
    int info;
}lista;

#endif // LISTE_H


lista* creaLista();
void inserisciInCoda(int x, lista *p);
void inserisciInTesta(int x, lista *p);
void liste();
