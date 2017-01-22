#include <stdio.h>  /* ora puoi usare NULL */

/*ESERCIZIO 1 ======================================================================================================================================================================================*/

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi:
primo campo ha nome info ed è di tipo intero, secondo campo ha nome sx (un puntatore al sottoalbero sinistro),
terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non scambiare l'ordine dei campi] */

typedef struct elemento_albero_hw4{
    int info;
    struct elemento_albero_hw4 *dx;
    struct elemento_albero_hw4 *sx;
}elem_hw4;


/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef elem_hw4 *albero_hw4;


/* INIZIO FUNZIONE */

int albero_pieno(albero_hw4 T){

    /* Dato un un albero binario T di interi, la funzione albero_pieno deve ritornare un booleano: 1 se l'albero T è "pieno",
    0 altrimenti. Un albero binario “pieno” è un albero binario in cui tutti i nodi hanno esattamente 0 o 2 figli,
    e nessun nodo ha 1 figlio. Se l'albero T è vuoto la funzione deve ritornare 1.*/

    if(T == NULL)
        return 1;

    if(T->dx == NULL && T->sx == NULL)  // 0 figli
        return 1;
    if((T->dx == NULL && T->sx != NULL) || (T->dx != NULL && T->sx == NULL))
        return 0;

    return albero_pieno(T->dx) && albero_pieno(T->sx);

}



/*ESERCIZIO 2 ==============================================================================================================================================================================================*/

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: primo campo ha nome info ed è di tipo intero, secondo campo ha nome sx (un puntatore al sottoalbero sinistro), terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non scambiare l'ordine dei campi] */


/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */
//20



/* scrivi qui eventuali funzioni di appoggio */


int verifica_foglie(albero_hw4 T, int l){
    if(T==NULL)
        return 0;
    if ((T->sx==NULL&&T->dx==NULL)&&(l==0))
        return 1;
    return verifica_foglie(T->sx, l-1)&&verifica_foglie(T->dx,l-1);
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int altezza(albero_hw4 T){
    if(T==NULL)
        return 0;
    if(T->sx==NULL&&T->dx==NULL)
        return 1;
    return 1+max(altezza(T->sx),altezza(T->dx));
}

int verifica_nodi(albero_hw4 T, int l){
    if (T==NULL)
        return 0;
    if ((T->sx!=NULL&&T->dx!=NULL)&&(l=1))
        return 1;
    return verifica_nodi(T->sx, l-1)&&verifica_nodi(T->dx, l-1);
}

/* INIZIO FUNZIONE */

int albero_completo(albero_hw4 T){

    /* Dato un un albero binario T di interi, la funzione albero_completo deve ritornare un booleano: 1 se l'albero T è completo, 0 altrimenti. Un albero binario completo di altezza k è un albero binario in cui tutti i nodi, tranne le foglie, hanno esattamente due figli, e tutte le foglie si trovano al livello k. Se l'albero T è vuoto la funzione deve ritornare 0.*/

    if(T==NULL)
        return 0;
    if(T->sx==NULL&&T->dx==NULL)
        return 1;
    if((verifica_nodi(T, altezza(T)))&&(verifica_foglie(T, altezza(T))))
        return 1;
    return 0;

}


/*ESERCIZIO 3 ==============================================================================================================================================================================================*/



/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: primo campo ha nome info ed è di tipo intero,
secondo campo ha nome sx (un puntatore al sottoalbero sinistro), terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non modificare l'ordine dei campi] */



/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */



/* scrivi qui eventuali funzioni di appoggio */

int b(albero_hw4 T, int l){
    if(T==NULL)
        return 0;
    if(l==0)
        return 1;
    else
        if(l>0)
            return b(T->sx,l-1) + b(T->dx,l-1);
    return 0;
}

int a(albero_hw4 T, int l){
    int i;
    int result = 0;
    int temp;

    for(i=0; i<l+1; i++) {
        temp = b(T, i);
            if(temp > result)
                result = temp;
    }

    return result;
}

/* INIZIO FUNZIONE */

int larghezza_albero(albero_hw4 T){

    /* Dato un un albero binario T di interi, la funzione larghezza_albero deve ritornare la larghezza di T; la larghezza di un albero binario è il numero massimo di nodi che stanno tutti al medesimo livello. Nel caso in cui T sia vuoto la funzione ritornerà 0.*/

  if(T == NULL)
    return 0;

  return a(T, altezza(T));
}
