#include <stdio.h>
#include "esameSettembre2016.h"
/*========================= ESERCIZIO 1 =========================*/

/* che restituisca 1 se esiste in T un cammino radice-foglia in cui tutti  i  nodi  contengono  il  booleano  1.  Se  l’albero  T  è  vuoto  oppure  non  esiste  un  cammino  radice-
foglia  come  richiesto,  la  funzione  restituirà  il  valore  0.  Ad  esempio  cammino_vero(T1)restituirà il valore 1. */

int cammino_vero(BTree T){
    if(T==NULL)
        return 0;
    if(T->valore == 0)
        return 0;

    if(T->sx == NULL && T->dx == NULL)   // E' una foglia?
        if(T->valore == 1)
            return 1;

    if(T->valore == 1)                                      // Visto che il nodo corrente è vero,
        return cammino_vero(T->sx) || cammino_vero(T->dx);  // Esiste un cammino vero nel sottoalbero sinistro OPPURE destro?

    return 0;
}



/*========================= ESERCIZIO 2 =========================*/

int max_esame_febbraio_2016(int a, int b){
    if(a>b)
        return a;
    return b;
}

int altezza_esame_febbraio_2016(BTree T){
    if(T == NULL)
        return 0;
    if(T->sx == NULL && T->dx == NULL)
        return 1;

    return 1 + max_esame_febbraio_2016(altezza_esame_febbraio_2016(T->sx), altezza_esame_febbraio_2016(T->dx));
}



int checkEsistenzaLivello(BTree T, int k){
    if(k <= altezza_esame_febbraio_2016(T))
        return 1;
    return 0;
}

int livello_vero_ricorsivo(BTree T, int livello){
    if(T==NULL)
        return 0;
    if(livello==0 && T->valore == 1)    // Se il livello è quello richiesto e il valore è 1, ritorna 1.
        return 1;

    return livello_vero_ricorsivo(T->sx,livello-1) && livello_vero_ricorsivo(T->dx,livello-1); // Scala di un livello e controlla i sottoalberi
}

/*che dato un albero binario T e un intero h, verifica se tutti i nodi al livello h contengono il booleano 1. Se l’albero T è vuoto oppure non esiste il livello h la
funzione restituirà il valore 0. Ad esempio livello_vero(T1, 2)restituirà il valore 0 (nell’albero T1 il livello 2, che è l’ultimo in basso, contiene degli zeri). */

int livello_vero(BTree T, int h){

    if(T==NULL)
        return 0;
    if(!checkEsistenzaLivello(T,h))     // Controlla se il livello esiste o se l'albero è troppo "basso"
        return 0;

    return livello_vero_ricorsivo(T, h-1);
}

/*========================= ESERCIZIO 3 =========================*/

int check_fratelli_figlio(BNTree T){
    if(T==NULL)
        return 0;
    if(T-> valore == 1 && T->fratello == NULL)
        return 1;
    if(T->valore == 1)
        return check_fratelli_figlio(T->fratello);
    return 0;
}

/* che dato un albero di grado arbitrario T conta quanti nodi in   T   hanno   tutti   figli   contenenti   il   booleano   1.   Se   un   nodo   N   non   ha   figli   allora
conta_booleani(N) ritorna 0. Ad esempio  conta_booleani(T2) restituirà il valore 2. */

int conta_booleani(BNTree T){
    if(T==NULL)
        return 0;

    if(check_fratelli_figlio(T))
        return 1 + conta_booleani(T->primofiglio) + conta_booleani(T->fratello);

    return conta_booleani(T->primofiglio) + conta_booleani(T->fratello);
}
