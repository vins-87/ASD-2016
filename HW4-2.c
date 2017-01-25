
#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>
#include "alberi.h"

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

/* scrivi qui eventuali funzioni di appoggio */

int altezza_albero(albero a1){
    if(a1){
        return 1+maggiore(altezza_albero(a1->sx),altezza_albero(a1->dx));
    }else{
        return -1;
    }
}

int livelloNodo(albero T, int n){
    if(T){
        if(T->info==n){
            return 0;
        }else{
            if(n<T->info){
                return 1+livelloNodo(T->sx,n);
            }else{
                return 1+livelloNodo(T->dx,n);
            }
        }
    }
    return 0;
}

int albero_completoV_aux(albero T, albero root){
    if(T){
        printf("nodo = %d\n",T->info);
        if(T->sx==NULL && T->dx==NULL){
            int liv = livelloNodo(root,T->info);
            printf("livello = %d\n",liv);
            if(altezza_albero(root)!=liv){
                return 0;
            }else{
                return 1;
            }
        }
        albero_completoV_aux(T->sx,root);
        albero_completoV_aux(T->dx,root);
    }
    return 0;
}

/* INIZIO FUNZIONE */

int albero_completoV(albero T){

    /* Dato un un albero binario T di interi, la funzione albero_completo deve ritornare un booleano:
    1 se l'albero T è completo, 0 altrimenti. Un albero binario completo di altezza k è un albero binario
    in cui tutti i nodi, tranne le foglie, hanno esattamente due figli, e tutte le foglie si trovano al livello k.
    Se l'albero T è vuoto la funzione deve ritornare 0.*/

    if(T){
        return albero_completoV_aux(T,T);
    }
    return 0;

}

albero creaAlberoHW4_2(){
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

void hw4_2(){
    albero T =creaAlberoHW4_2();
    printf("albero_completo = %d\n",albero_completoV(T));
}
