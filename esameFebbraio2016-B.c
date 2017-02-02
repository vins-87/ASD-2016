#define lunghezzaStringhe 19

#include <stdio.h>
#include <stdlib.h>

typedef char stringa[lunghezzaStringhe+1];  // +1 perchè l'ultimo elemento è il carattere terminatore

typedef struct elem_febbraio_2016 {
    stringa nome;
    struct elem_febbraio_2016* sx;
    struct elem_febbraio_2016* dx;
} nodo_albero_febbraio_2016;

    typedef nodo_albero_febbraio_2016* BTree;

typedef struct elem2_febbraio_2016 {
    stringa nome;
    struct elem2_febbraio_2016* primofiglio;
    struct elem2_febbraio_2016* fratello;
} nodo_alberoN_febbraio_2016;

typedef nodo_alberoN_febbraio_2016* NTree;


/*  ===================================== ESERCIZIO 0 =====================================*/

int verificaCarattere(stringa s, char c){
    int i;
    for(i=0; s[i]!= '\0'; i++)
        if(s[i]==c)
            return 1;
    return 0;
}

/*Il metodo conta_occorrenza conta quanti nodi dell’albero binario T contengono la lettera c.
Ad esempio conta_occorrenza(T1, ‘b’) restituisce il valore 6.*/

int conta_occorrenza(BTree T, char c){
    if(T==NULL)
        return 0;

    if(verificaCarattere(T->nome,c))
        return 1 + conta_occorrenza(T->sx,c) + conta_occorrenza(T->dx,c);

    return conta_occorrenza(T->sx,c) + conta_occorrenza(T->dx,c);
}



/*  ===================================== ESERCIZIO 1 =====================================*/



/* int distanza(BTree T, stringa S1, stringa S2), che restituisca la lunghezza del
cammino (numero di archi) in T dal nodo contenente S1 al nodo contenente S2. Se l’albero T è
vuoto oppure non esiste il nodo contenente S1 oppure S2, oppure non esiste un cammino da S1 a
S2, la funzione restituirà il valore 0. Ad esempio distanza(T1, “abc”, “aczbd”)
restituirà il valore 2. */

int nomeFunzione(BTree T, stringa s, int cont){

    if(T==NULL)
        return 0;

    if(T->nome == s)                                                    // Se trovo la seconda stringa, ritorno il la distanza
        return cont;                                                    // Ritorno il la distanza

    return nomeFunzione(T->sx,s,cont+1) + nomeFunzione(T->dx,s,cont+1); // Somma distanze sottoalbero destro e sinistro incrementando di uno il livello (contatore)
}

int distanza(BTree T, stringa S1, stringa S2){

    if(T==NULL)
        return 0;

    if(T->nome == S1)                                       // Se trovo S1
        return nomeFunzione(T,S2,0);                        // Ritorna la distanza fino a S2

    return distanza(T->dx,S1,S2) + distanza(T->sx,S1,S2);
}



/*  ===================================== ESERCIZIO 2 =====================================*/



/* int conta_nodi(Btree T, int x, char c) che dato un albero binario T, un intero x e
un carattere c, conta quanti nodi in T sono radici di sottoalberi che contengono almeno x nodi in cui
occorre il carattere c nella stringa del nodo. Ad esempio conta_nodi(T1, 3, ‘a’) restituirà il
valore 2 (nell’albero T1 solamente i nodi contenenti “abc” e “abcd” sono radici di alberi che
contengono rispettivamente 6 e 3 nodi nella cui stringa occorre la lettera ‘a’). */


/*********************************TODO */
int conta_nodi(BTree T, int x, char c){
    return 0;
}



/*  ===================================== ESERCIZIO 3 =====================================*/



/* int conta_figli(NTree T, int x, char c), che dato un albero di grado arbitrario T,
un intero x e un carattere c, conta quanti nodi in T hanno esattamente x figli la cui stringa contiene il
carattere c. Ad esempio conta_figli(T2, 3, ‘d’) restituirà il valore 1 (nell’albero T2
solamente il nodo contenente “abcd” ha esattamente 3 figli in cui occorre la lettera ‘d’). */


/** TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO***** */
int conta_figli(NTree T, int x, char c){
    return 0;
}

/*  ============================== FUNZIONE DI LANCIO SU MAIN ==============================*/

/** TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO***** */
BTree creaAlbero_esame_febbraio_2016(){
    BTree root = (BTree)malloc(sizeof(nodo_albero_febbraio_2016));

    root->nome;
    root->dx = NULL;
    root->sx = NULL;

    return root;
}

/** TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO***** */
void esame_febbraio_2016_B(){
    BTree n = creaAlbero_esame_febbraio_2016();

    printf("%d", distanza(n,"",""));
}
