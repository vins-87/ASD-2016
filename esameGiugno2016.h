#ifndef ALBERO_DISCENDENZA_H
#define ALBERO_DISCENDENZA_H

#endif // ALBERO_DISCENDENZA_H
typedef char stringa[20];

typedef struct elem {
    stringa nome;
    struct elem* sx;
    struct elem* dx;
} nodo_albero;

typedef nodo_albero* BTree;

typedef struct elem2 {
    stringa nome;
    struct elem2* primofiglio;
    struct elem2* fratello;
} nodo_alberoN;

typedef nodo_alberoN* Ntree;

int verificaDiscendenza(BTree T, stringa S1, stringa S2);
