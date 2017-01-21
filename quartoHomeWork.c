#include <stdio.h>  /* ora puoi usare NULL */

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: primo campo ha nome info ed è di tipo intero, secondo campo ha nome sx (un puntatore al sottoalbero sinistro), terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non scambiare l'ordine dei campi] */


typedef struct elemento_albero_hw4{
    int info;
    struct elemento_albero_hw4 *dx;
    struct elemento_albero_hw4 *sx;
}elem_hw4;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef elem_hw4 *albero_hw4;


/* scrivi qui eventuali funzioni di appoggio */

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int altezza(albero_hw4 T){
    if(T==NULL)
        return 0;
    return 1 + max(altezza(T->dx),altezza(T->sx));
}

int verifica_nodi(albero_hw4 T){
    if(T==NULL)
        return 0;
    if((T->dx!=NULL && T->sx!=NULL) || (T->dx==NULL && T->sx==NULL))
        return verifica_nodi(T->dx) && verifica_nodi(T->sx);
    return 0;
}

int verifica_foglie(albero_hw4 T, int h){
    if(T==NULL)
        return 0;
    if(h==0)
        return 1;

    return verifica_foglie(T->sx, h-1) && verifica_foglie(T->dx, h-1);
}

/* INIZIO FUNZIONE */

int albero_completo(albero_hw4 T){

    /* Dato un un albero binario T di interi, la funzione albero_completo deve ritornare un booleano:
    1 se l'albero T è completo, 0 altrimenti. Un albero binario completo di altezza k è un albero binario in cui tutti i nodi,
    tranne le foglie, hanno esattamente due figli, e tutte le foglie si trovano al livello k.
    Se l'albero T è vuoto la funzione deve ritornare 0.*/

    if(T == NULL)
        return 0;

    if(T->dx == NULL && T->sx == NULL)
        return 1;

    int h = altezza(T);

    if(verifica_nodi(T) && verifica_foglie(T,h))  // Se ha due figli
        return 1;
    return 0;

}
