#include <stdio.h>  /* ora puoi usare NULL */
#include "terzoHomeWork.h"

/* scrivi qui eventuali funzioni di appoggio */

int massimo(int a, int b){
    if(a>b)
        return a;
    return b;
}

int profonditaAlbero(albero T){

    if(T==NULL)
        return -1;

    return 1 + massimo(profonditaAlbero(T->sx), profonditaAlbero((T->dx)));
}

int numeroFoglie(albero T){

    if(T==NULL)
        return 0;

    if(T->dx==NULL && T->sx==NULL)
        return 1;

    return numeroFoglie(T->sx) + numeroFoglie(T->dx);
}


/* INIZIO FUNZIONE */

int albero_altezza_foglie(albero T){

    /* Si consideri un albero binario T di interi. La funzione albero_altezza_foglie deve ritornare un booleano: 1 (true) se l'altezza di T è pari al numero di foglie di T, 0 (false) altrimenti. Si ricorda che in un albero binario vuoto l'altezza è pari a -1 mentre il numero di foglie è pari a 0; quindi se T è vuoto allora la funzione albero_altezza_foglie deve ritornare 0.*/

    if(T==NULL)
        return 0;

    if(profonditaAlbero(T) == numeroFoglie(T))
        return 1;

    return 0;
}
