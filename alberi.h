#ifndef ALBERI_H
#define ALBERI_H

typedef struct nodoAlb{
    int info;
    struct nodoAlb *sx;
    struct nodoAlb *dx;
}nodoAlbe;

typedef nodoAlbe* nodoAlbero;

#endif // ALBERI_H

void visitaAlberoPreorder(nodoAlbero a1);
void visitaAlberoInorder(nodoAlbero a1);
void visitaAlberoPostorder(nodoAlbero a1);
int maggiore(int n, int m);
int altezzaAlbero(nodoAlbero a1);
int ricerca(nodoAlbero t, int k);
int max3(int a, int b, int c);
int get_max(nodoAlbero t);
int uguali(nodoAlbero a1, nodoAlbero a2);
void arr2alberoAux(nodoAlbero a1, int arr[], int i, int dim);
nodoAlbero arr2albero(int arr[], int dim);
nodoAlbero creaAlbero();
void alberi();
