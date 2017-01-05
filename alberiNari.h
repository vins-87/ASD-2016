#ifndef ALBERINARI_H
#define ALBERINARI_H

typedef struct nodoAlbN{
    int info;
    struct nodoAlbN *figlio;
    struct nodoAlbN *fratello;
}nodoAlbeN;

typedef nodoAlbeN *nodoAlberoNario;

#endif // ALBERINARI_H


nodoAlberoNario creaAlberoNario();
void alberiNari();
