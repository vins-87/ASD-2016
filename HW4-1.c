#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>
/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi:
primo campo ha nome info ed è di tipo intero,
secondo campo ha nome sx (un puntatore al sottoalbero sinistro),
terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non scambiare l'ordine dei campi] */

typedef struct nodo_albero{
    int info;
    struct nodo_albero *sx;
    struct nodo_albero *dx;
}nodo_alb;


/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */
typedef nodo_alb *albero;

/* INIZIO FUNZIONE */

int albero_pieno(albero T){

    /* Dato un un albero binario T di interi, la funzione albero_pieno deve ritornare un booleano:
    1 se l'albero T è "pieno", 0 altrimenti. Un albero binario “pieno” è un albero binario in cui
    tutti i nodi hanno esattamente 0 o 2 figli, e nessun nodo ha 1 figlio.
    Se l'albero T è vuoto la funzione deve ritornare 1.*/

    if(T){
        if((T->sx && T->dx) || (T->sx==NULL && T->dx==NULL)){
            return albero_pieno(T->sx) && albero_pieno(T->dx);
        }else{
            return 0;
        }
    }
    return 1;

}

albero creaAlberoHW4_1(){
    albero al=(albero)malloc(sizeof(nodo_alb));
    albero root=al;
    al->info=50;
    al->sx=(albero)malloc(sizeof(nodo_alb));
    al->sx->info=20;
    al->dx=(albero)malloc(sizeof(nodo_alb));
    al->dx->info=80;
    al->sx->sx=(albero)malloc(sizeof(nodo_alb));
    al->sx->sx->info=10;
    al->sx->sx->sx=NULL;
    al->sx->sx->dx=(albero)malloc(sizeof(nodo_alb));
    al->sx->sx->dx->info=15;
    al->sx->sx->dx->sx=NULL;
    al->sx->sx->dx->dx=NULL;
    al->sx->dx=(albero)malloc(sizeof(nodo_alb));
    al->sx->dx->info=30;
    al->sx->dx->sx=NULL;
    al->sx->dx->dx=(albero)malloc(sizeof(nodo_alb));
    al->sx->dx->dx->info=40;
    al->sx->dx->dx->sx=(albero)malloc(sizeof(nodo_alb));
    al->sx->dx->dx->sx->info=35;
    al->sx->dx->dx->sx->sx=NULL;
    al->sx->dx->dx->sx->dx=NULL;
    al->sx->dx->dx->dx=(albero)malloc(sizeof(nodo_alb));
    al->sx->dx->dx->dx->info=45;
    al->sx->dx->dx->dx->sx=NULL;
    al->sx->dx->dx->dx->dx=NULL;
    al->dx->sx=(albero)malloc(sizeof(nodo_alb));
    al->dx->sx->info=60;
    al->dx->sx->sx=NULL;
    al->dx->sx->dx=(albero)malloc(sizeof(nodo_alb));
    al->dx->sx->dx->info=70;
    al->dx->sx->dx->sx=(albero)malloc(sizeof(nodo_alb));
    al->dx->sx->dx->sx->info=65;
    al->dx->sx->dx->sx->sx=NULL;
    al->dx->sx->dx->sx->dx=NULL;
    al->dx->sx->dx->dx=NULL;
    al->dx->dx=(albero)malloc(sizeof(nodo_alb));
    al->dx->dx->info=90;
    al->dx->dx->sx=(albero)malloc(sizeof(nodo_alb));
    al->dx->dx->sx->info=85;
    al->dx->dx->sx->sx=NULL;
    al->dx->dx->sx->dx=NULL;
    al->dx->dx->dx=NULL;
    return root;
}

void hw4_1(){
    albero T =creaAlberoHW4_1();
    printf("albero_pieno = %d\n",albero_pieno(T));
}
