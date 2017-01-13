#ifndef ALBERINARI_H
#define ALBERINARI_H

typedef struct nodoAlbN{
    int info;
    struct nodoAlbN *figlio;
    struct nodoAlbN *fratello;
}nodoAlbeN;

typedef nodoAlbeN *nodoAlberoNario;

#endif // ALBERINARI_H

void visitaAlberoNarioPreorder(nodoAlberoNario a1);
void visitaAlberoNarioPreorderOld(nodoAlberoNario a1);
void visitaAlberoNarioInorder(nodoAlberoNario a1);
void visitaAlberoNarioPostorder(nodoAlberoNario a1);
int maxElemAlberoNario(nodoAlberoNario a1);
int trovaElemAlberoNario(nodoAlberoNario a1,int n);
int tuttiPariAlberioNario(nodoAlberoNario a1);
int contaFoglieAlberoNario(nodoAlberoNario a1);
int altezzaAlberoNario(nodoAlberoNario a1);
int numNodiConKfigli(nodoAlberoNario a1, int k);
int verificaNodiPariConSoliFigliDispari(nodoAlberoNario a1);
void stampaAlberoNarioGrafico(nodoAlberoNario a1);
nodoAlberoNario creaAlberoNarioDaInputPreorder();
nodoAlberoNario creaAlberoNario();
void alberiNari();
