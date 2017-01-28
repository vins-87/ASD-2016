#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>  /* ora puoi usare le funzioni di allocazione dinamica della memoria */
#include "main.h"

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi:
il primo campo ha nome info ed è di tipo intero,
il secondo campo ha nome sx (il puntatore al sottoalbero sinistro),
il terzo campo ha nome dx (un puntatore al sottoalbero destro).
ATTENZIONE: non invertire l'ordine dei campi della struttura. */

typedef struct nodo_albero{
    int info;
    struct nodo_albero *sx;
    struct nodo_albero *dx;
}nodo_alb;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_alb *albero;



/* scrivi qui eventuali funzioni di appoggio */

int* albero_cammino_aux(albero a1, int n, int* vet, int i){
    if(a1){
        vet[i]=a1->info;
        if(a1->sx==NULL && a1->dx==NULL){
            if(a1->info==n){
                vet[i+1]=0;
                return vet;
            }
        }else{
            if(n<a1->info){
                vet = albero_cammino_aux(a1->sx,n,vet,++i);
            }else{
                vet = albero_cammino_aux(a1->dx,n,vet,++i);
            }
        }
    }
    return vet;
}

/* INIZIO FUNZIONE */

int* albero_cammino(albero T, int v){

    /* Si consideri un albero binario di ricerca T e un intero v
    (si ricorda che rispetto ad ogni nodo, il figlio sinistro avrà un valore minore rispetto al padre,
     il figlio destro avrà un valore maggiore rispetto al padre):
     allocare dinamicamente un array A di interi contenente i valori info dei nodi del cammino
     dalla radice di T alla foglia di T contenente il valore v. Alla fine restituire l'array A così costruito.
     Se l'albero T è vuoto, oppure non esiste una foglia in T contenente il valore v allora restituire NULL.
     Se l'albero T non presenta alcuna foglia contenente v, ma presenta un nodo intermedio con il valore v,
     la funzione deve restituire NULL */

    int* vet = (int*)malloc(sizeof(int));
    return albero_cammino_aux(T,v,vet,0);
}

albero creaAlberoHW5(){
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

void hw5(){
    printf("*********************************************\n");
    printf("*****************HOMEWORK 5******************\n");
    printf("*********************************************\n");
    albero T = creaAlberoHW5();
    int* vet = albero_cammino(T,65);
    int i;
    printf("cammino = ");
    for(i=0;vet[i]!=0;i++){
        printf("%d ",vet[i]);
    }
    printf("\n---------------------------------------------\n");
    main();
}
