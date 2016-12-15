#ifndef TERZOHOMEWORK_H_INCLUDED
#define TERZOHOMEWORK_H_INCLUDED



#endif // TERZOHOMEWORK_H_INCLUDED


/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: un campo info di tipo intero, un campo sx (il puntatore al sottoalbero sinistro), un campo dx (un puntatore al sottoalbero destro) */

typedef struct elemento_albero{
    int info;
    struct elemento_albero *sx;
    struct elemento_albero *dx;
}nodo_albero;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_albero *albero;
