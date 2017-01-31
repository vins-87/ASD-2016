#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>  /* ora puoi usare le funzioni di allocazione dinamica della memoria */

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: il primo campo ha nome info ed è di tipo intero, il secondo campo ha nome sx (il puntatore al sottoalbero sinistro), il terzo campo ha nome dx (un puntatore al sottoalbero destro). ATTENZIONE: non invertire l'ordine dei campi della struttura. */

typedef struct nodo_albero{
    int info;
    struct nodo_albero *sx;
    struct nodo_albero *dx;
}nodo_alb;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_alb *albero;


/* scrivi qui eventuali funzioni di appoggio */


int isFoglia(albero T){
    return (T->dx == NULL && T->sx == NULL);
}

int *albero_cammino_ricorsivo(int *A, albero T, int v, int cont){

    /* Controlli */

    if(T==NULL)
        return NULL;

    if(A==NULL)
        return NULL;


    if(!isFoglia(T)){
        if(T->info > v){
            *A = T->info;   // Salva l'informazione nella posizione cont-esima (si, fa schifo cont-esima..) dell'array A (A[cont] = T->info)
            return albero_cammino_ricorsivo(A+1, T->sx, v, cont+1); // A+1 = &A[cont+1]
        }

        if(T->info < v){
            *A = T->info;   // Salva l'informazione nella posizione cont-esima (si, fa schifo cont-esima..) dell'array A (A[cont] = T->info)
            return albero_cammino_ricorsivo(A+1, T->dx, v, cont+1); // A+1 = &A[cont+1]
        }
    }

    if(T->info == v && isFoglia(T)){
        *A = T->info;   // Salva l'informazione nella posizione cont-esima (si, fa schifo cont-esima..) dell'array A
        return A-cont;  //Deve ritornare l'indirizzo del primo elemento dell'array
    }

    return NULL;
}


/* INIZIO FUNZIONE */

int* albero_cammino(albero T, int v){
    /* Si consideri un albero binario di ricerca T e un intero v (si ricorda che rispetto ad ogni nodo,
    il figlio sinistro avrà un valore minore rispetto al padre, il figlio destro avrà un valore maggiore rispetto al padre):
    allocare dinamicamente un array A di interi contenente i valori info dei nodi del cammino dalla radice di T alla foglia di T contenente il valore v.
    Alla fine restituire l'array A così costruito. Se l'albero T è vuoto, oppure non esiste una foglia in T contenente il valore v allora restituire NULL.
    Se l'albero T non presenta alcuna foglia contenente v, ma presenta un nodo intermedio con il valore v, la funzione deve restituire NULL */

    /* Controlli */

    if(T==NULL)
        return NULL;

    if(isFoglia(T))
        return NULL;

    int *A;
    A = (int*)malloc(sizeof(int));


    return albero_cammino_ricorsivo(A,T,v,0);
}
