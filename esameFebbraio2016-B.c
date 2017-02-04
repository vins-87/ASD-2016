#define lunghezzaStringhe 19

#include <stdio.h>
#include <stdlib.h>

typedef char str[lunghezzaStringhe+1];  // +1 perchè l'ultimo elemento è il carattere terminatore

typedef struct elem_febbraio_2016 {
    str nome;
    struct elem_febbraio_2016* sx;
    struct elem_febbraio_2016* dx;
} nodo_albero_febbraio_2016;

typedef nodo_albero_febbraio_2016* BTree;

typedef struct elem2_febbraio_2016 {
    str nome;
    struct elem2_febbraio_2016* primofiglio;
    struct elem2_febbraio_2016* fratello;
} nodo_alberoN_febbraio_2016;

typedef nodo_alberoN_febbraio_2016* NTree;


/*  ===================================== ESERCIZIO 0 =====================================*/

int verificaCarattere(str s, char c){
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

    if(verificaCarattere(T->nome, c))
        return 1 + conta_occorrenza(T->sx,c) + conta_occorrenza(T->dx,c);

    return conta_occorrenza(T->sx,c) + conta_occorrenza(T->dx,c);
}



/*  ===================================== ESERCIZIO 1 =====================================*/



/* int distanza(BTree T, str S1, str S2), che restituisca la lunghezza del
cammino (numero di archi) in T dal nodo contenente S1 al nodo contenente S2. Se l’albero T è
vuoto oppure non esiste il nodo contenente S1 oppure S2, oppure non esiste un cammino da S1 a
S2, la funzione restituirà il valore 0. Ad esempio distanza(T1, “abc”, “aczbd”)
restituirà il valore 2. */

int nomeFunzione(BTree T, str s, int cont){

    if(T==NULL)
        return 0;

    if(T->nome == s)                                                    // Se trovo la seconda str, ritorno il la distanza
        return cont;                                                    // Ritorno il la distanza

    return nomeFunzione(T->sx,s,cont+1) + nomeFunzione(T->dx,s,cont+1); // Somma distanze sottoalbero destro e sinistro incrementando di uno il livello (contatore)
}

int distanza(BTree T, str S1, str S2){

    if(T==NULL)
        return 0;

    if(T->nome == S1)                                       // Se trovo S1
        return nomeFunzione(T,S2,0);                        // Ritorna la distanza fino a S2

    return distanza(T->dx,S1,S2) + distanza(T->sx,S1,S2);
}



/*  ===================================== ESERCIZIO 2 =====================================*/



/* int conta_nodi(Btree T, int x, char c) che dato un albero binario T, un intero x e
un carattere c, conta quanti nodi in T sono radici di sottoalberi che contengono almeno x nodi in cui
occorre il carattere c nella str del nodo. Ad esempio conta_nodi(T1, 3, ‘a’) restituirà il
valore 2 (nell’albero T1 solamente i nodi contenenti “abc” e “abcd” sono radici di alberi che
contengono rispettivamente 6 e 3 nodi nella cui str occorre la lettera ‘a’). */



int conta_nodi(BTree T, int x, char c){

    if(T==NULL)
        return 0;

    if(conta_occorrenza(T,c)>x-1)
        return 1 + conta_nodi(T->sx, x, c) + conta_nodi(T->dx, x, c);

    return conta_nodi(T->sx, x, c) + conta_nodi(T->dx, x, c);
}



/*  ===================================== ESERCIZIO 3 =====================================*/



/* int conta_figli(NTree T, int x, char c), che dato un albero di grado arbitrario T,
un intero x e un carattere c, conta quanti nodi in T hanno esattamente x figli la cui str contiene il
carattere c. Ad esempio conta_figli(T2, 3, ‘d’) restituirà il valore 1 (nell’albero T2
solamente il nodo contenente “abcd” ha esattamente 3 figli in cui occorre la lettera ‘d’). */


/******* */
int conta_figli(NTree T, int x, char c){
    if(T){
        NTree Tf=T->primofiglio;
        int cont=0;
        while(Tf){
            if(verificaCarattere(Tf->nome,c)){
                cont++;
            }
            Tf=Tf->fratello;
        }
        if(cont==x){
            return 1+conta_figli(T->primofiglio,x,c)+conta_figli(T->fratello,x,c);
        }
        return conta_figli(T->primofiglio,x,c)+conta_figli(T->fratello,x,c);
    }
    return 0;
}

/*  ============================== FUNZIONE DI LANCIO SU MAIN ==============================*/

char* stringCopy(str dest, str sorg){
    int i;
    for(i=0; sorg[i]!='\0'; i++)
        dest[i] = sorg[i];

    dest[i] = sorg[i];

    return dest;
}

/** TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO***** */
BTree creaAlbero_esame_febbraio_2016(){
    BTree root = (BTree)malloc(sizeof(nodo_albero_febbraio_2016));
    str str1;
    str1[0]='a';
    str1[1]='b';
    str1[2]='c';
    //root->nome[0]='\0';
    stringCopy(root->nome, str1);
    root->dx = NULL;
    root->sx = NULL;

    return root;
}

NTree creaAlberoNario_esamefeb2016(){
    NTree T =(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char s1[20];
    s1[0]='a';
    s1[1]='b';
    s1[2]='c';
    //T->nome=s1;
    stringCopy(T->nome,s1);
    T->fratello=NULL;
    T->primofiglio=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s2=(char*)malloc(sizeof(char));
    s2="cabz";
    stringCopy(T->primofiglio->nome,s2);
    T->primofiglio->fratello=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s3=(char*)malloc(sizeof(char));
    s3="abcd";
    stringCopy(T->primofiglio->fratello->nome,s3);
    T->primofiglio->fratello->fratello=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s4=(char*)malloc(sizeof(char));
    s4="cbah";
    stringCopy(T->primofiglio->fratello->fratello->nome,s4);
    T->primofiglio->fratello->fratello->fratello=NULL;
    T->primofiglio->fratello->fratello->primofiglio=NULL;
    T->primofiglio->primofiglio=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s5=(char*)malloc(sizeof(char));
    s5="czabw";
    stringCopy(T->primofiglio->primofiglio->nome,s5);
    T->primofiglio->primofiglio->primofiglio=NULL;
    T->primofiglio->primofiglio->fratello=NULL;
    T->primofiglio->fratello->primofiglio=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s6=(char*)malloc(sizeof(char));
    s6="bcdam";
    stringCopy(T->primofiglio->fratello->primofiglio->nome,s6);
    T->primofiglio->fratello->primofiglio->primofiglio=NULL;
    T->primofiglio->fratello->primofiglio->fratello=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s7=(char*)malloc(sizeof(char));
    s7="bacdn";
    stringCopy(T->primofiglio->fratello->primofiglio->fratello->nome,s7);
    T->primofiglio->fratello->primofiglio->fratello->primofiglio=NULL;
    T->primofiglio->fratello->primofiglio->fratello->fratello=(NTree)malloc(sizeof(nodo_alberoN_febbraio_2016));
    char * s8=(char*)malloc(sizeof(char));
    s8="cdbax";
    stringCopy(T->primofiglio->fratello->primofiglio->fratello->fratello->nome,s8);
    T->primofiglio->fratello->primofiglio->fratello->fratello->primofiglio=NULL;
    T->primofiglio->fratello->primofiglio->fratello->fratello->fratello=NULL;
    return T;
}

/** TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO*****TODO***** */
void esame_febbraio_2016_B(){
    //BTree n = creaAlbero_esame_febbraio_2016();
    //printf("%d", distanza(n,"",""));
    NTree T = creaAlberoNario_esamefeb2016();
    printf("num figli = %d\n",conta_figli(T,3,'d'));
}
