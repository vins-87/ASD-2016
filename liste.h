#include "stringhe.h"
#ifndef LISTE_H
#define LISTE_H

typedef struct nodo{
    struct nodo *prev;
    struct nodo *next;
    int info;
}nodoLista;
typedef nodoLista* lista;

typedef struct nodoTarga {
char abbr[2];
stringa estesa;
struct nodoTarga *next;
}targa;

typedef targa* targhe;

#endif // LISTE_H

void stampaLista(lista p);
void stampaArrayDiListe(lista *l, int dim);
void inserisciInCoda(int x, lista *p);
void inserisciInTesta(int x, lista *p);
int trovaTarga(targhe t, char abb[2], char *ext);
int indiceListaMax(lista *v, int dim);
int testInserimentoInCoda();
targhe creaListaTarghe();
lista* creaArrayDiListe(int dim);
lista creaLista(int dim);

void liste();
