#ifndef ESAMESETTEMBRE2016_H_INCLUDED
#define ESAMESETTEMBRE2016_H_INCLUDED



#endif // ESAMESETTEMBRE2016_H_INCLUDED

typedef struct elem_settembre_2016 {
    int valore;
    struct elem_settembre_2016* sx;
    struct elem_settembre_2016* dx;
} nodo_albero_settembre_2016;

typedef nodo_albero_settembre_2016* BTree;

typedef struct elem2_settembre_2016 {
    int valore;
    struct elem2_settembre_2016* primofiglio;
    struct elem2_settembre_2016* fratello;
} nodo_alberoN_settembre_2016;

typedef nodo_alberoN_settembre_2016* BNTree;

int cammino_vero(BTree T);
int max_esame_febbraio_2016(int a, int b);
int altezza_esame_febbraio_2016(BTree T);
int checkEsistenzaLivello(BTree T, int k);
int livello_vero_ricorsivo(BTree T, int livello);
int livello_vero(BTree T, int h);
int check_fratelli_figlio(BNTree T);
int conta_booleani(BNTree T);
BTree creaAlbero_settembre_2016();
void stampaAlbero_settembre_2016(BTree t);
BNTree creaAlberoN_settembre_2016();
void stampaAlberoN_settembre_2016(BNTree t);

void esame_settembre_2016();
