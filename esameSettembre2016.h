#ifndef ESAMESETTEMBRE2016_H_INCLUDED
#define ESAMESETTEMBRE2016_H_INCLUDED



#endif // ESAMESETTEMBRE2016_H_INCLUDED


typedef struct elem {
    int valore;
    struct elem* sx;
    struct elem* dx;
} nodo_albero;

typedef nodo_albero* BTree;

typedef struct elem2 {
    int valore;
    struct elem2* primofiglio;
    struct elem2* fratello;
} nodo_alberoN;

typedef nodo_alberoN* BNTree;
