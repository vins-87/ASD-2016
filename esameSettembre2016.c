#include <stdio.h>
#include <stdlib.h>
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

/*========================= FUNZIONI DI APPOGGIO PER TESTING =========================*/

BTree creaAlbero_settembre_2016(){
    BTree bT=(BTree)malloc(sizeof(nodo_albero_settembre_2016));
    BTree root = bT;

    bT->valore = 1;

    /* ALLOCAZIONE SOTTOALBERO SINISTRO DELLA RADICE*/

    /* LIVELLO 2 */

    bT->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));

    /* LIVELLO 3 */

    bT->sx->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia
    bT->sx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));

    bT->sx->sx->dx = NULL;
    bT->sx->sx->sx = NULL;

    /* LIVELLO 4 */

    bT->sx->dx->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia
    bT->sx->dx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia

    bT->sx->dx->sx->sx = NULL;
    bT->sx->dx->sx->dx = NULL;

    bT->sx->dx->dx->sx = NULL;
    bT->sx->dx->dx->dx = NULL;

    /* ALLOCAZIONE SOTTOALBERO DESTRO DELLA RADICE */

    /* LIVELLO 2 */

    bT->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));

    /* LIVELLO 3 */

    bT->dx->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));
    bT->dx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));

    /* LIVELLO 4 */

    bT->dx->sx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia
    bT->dx->dx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));

    bT->dx->sx->dx->sx = NULL;
    bT->dx->sx->dx->dx = NULL;

    /* LIVELLO 5 */

    bT->dx->dx->dx->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016));
    bT->dx->dx->dx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia

    bT->dx->dx->dx->dx->sx = NULL;
    bT->dx->dx->dx->dx->dx = NULL;

    /* LIVELLO 6 */

    bT->dx->dx->dx->sx->sx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia
    bT->dx->dx->dx->sx->dx = (BTree)malloc(sizeof(nodo_albero_settembre_2016)); // Foglia

    bT->dx->dx->dx->sx->sx->sx = NULL;
    bT->dx->dx->dx->sx->sx->dx = NULL;

    bT->dx->dx->dx->sx->dx->sx = NULL;
    bT->dx->dx->dx->sx->dx->sx = NULL;

    /* VALORI SOTTOALBERO SINISTRO DELLA RADICE*/

    bT->sx->valore = 0; // Livello 2

    bT->sx->sx->valore = 0; // Livello 3
    bT->sx->dx->valore = 0;

    bT->sx->dx->sx->valore = 0; // Livello 4
    bT->sx->dx->dx->valore = 0;

    /* VALORI SOTTOALBERO DESTRO DELLA RADICE */

    bT->dx->valore = 1; // Livello 2

    bT->dx->sx->valore = 1; // Livello 3
    bT->dx->dx->valore = 1;

    bT->dx->sx->dx->valore = 0; // Livello 4
    bT->dx->dx->dx->valore = 1;

    bT->dx->dx->dx->sx->valore = 1; // Livello 5
    bT->dx->dx->dx->dx->valore = 1;

    bT->dx->dx->dx->sx->sx->valore = 0; // Livello 6
    bT->dx->dx->dx->sx->dx->valore = 1;


    return root;
}

/*========================= FUNZIONE PRINCIPALE PER TEST =============================*/

void esame_settembre_2016(){

    BTree bT = creaAlbero_settembre_2016();

    printf("\nLa funzione cammino_vero ritorna %d. Deve ritornare 1\n", cammino_vero(bT));

    printf("La funzione livello_vero(1) ritorna %d. Deve ritornare 1\n", livello_vero(bT,1));
    printf("La funzione livello_vero(2) ritorna %d. Deve ritornare 0\n", livello_vero(bT,2));
    printf("La funzione livello_vero(3) ritorna %d. Deve ritornare 0\n", livello_vero(bT,3));
    printf("La funzione livello_vero(4) ritorna %d. Deve ritornare 0\n", livello_vero(bT,4));
    printf("La funzione livello_vero(5) ritorna %d. Deve ritornare 1\n", livello_vero(bT,5));
    printf("La funzione livello_vero(6) ritorna %d. Deve ritornare 0\n", livello_vero(bT,6));
}
