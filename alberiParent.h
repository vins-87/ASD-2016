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
nodoAlberoParent creaAlberoParent();
void alberiParent();
