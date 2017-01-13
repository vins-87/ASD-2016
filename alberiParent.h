#ifndef ALBERIPARENT_H
#define ALBERIPARENT_H

typedef struct nodoAlbP{
    int info;
    struct nodoAlbP *parent;
    struct nodoAlbP *sx;
    struct nodoAlbP *dx;
}nodoAlbeP;

typedef nodoAlbeP* nodoAlberoParent;

#endif // ALBERI_H

void visitaAlberoParentPreorder(nodoAlberoParent a1);
void visitaAlberoParentInorder(nodoAlberoParent a1);
void visitaAlberoParentPostorder(nodoAlberoParent a1);
int profonditaNodoAux(nodoAlberoParent a1);
int profonditaNodo(nodoAlberoParent a1, int n);
int contaNodi(nodoAlberoParent a1);
int contaNodiLivello(nodoAlberoParent a1, int level);
int contaFoglie(nodoAlberoParent a1);
int addNodoAlbero(nodoAlberoParent *a1, nodoAlberoParent genitore, int n);
int nodoMinBST(nodoAlberoParent a1);
int nodoMaxBST(nodoAlberoParent a1);
int trovaNodo(nodoAlberoParent a1, int n);
void stampaCamminoAux(nodoAlberoParent a1, int n);
void stampaCammino(nodoAlberoParent a1, int n);
void stampaAlberoGrafico(nodoAlberoParent a1);
nodoAlberoParent creaAlberoParentDaInput();
nodoAlberoParent creaAlberoParent();
void alberiParent();
