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
nodoAlbero creaAlbero();
void alberi();
