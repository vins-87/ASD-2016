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

nodoAlberoParent creaAlberoParent();
void alberiParent();
