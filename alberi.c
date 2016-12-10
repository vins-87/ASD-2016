#include <stdio.h>
#include <stdlib.h>
#include "alberi.h"


void visitaAlberoPreorder(nodoAlbero a1){
    if(a1){
        printf("%d\n",a1->info);
        visitaAlberoPreorder(a1->sx);
        visitaAlberoPreorder(a1->dx);
    }
}

void visitaAlberoInorder(nodoAlbero a1){
    if(a1){
        visitaAlberoInorder(a1->sx);
        printf("%d\n",a1->info);
        visitaAlberoInorder(a1->dx);
    }
}

void visitaAlberoPostorder(nodoAlbero a1){
    if(a1){
        visitaAlberoPostorder(a1->sx);
        visitaAlberoPostorder(a1->dx);
        printf("%d\n",a1->info);
    }
}

nodoAlbero creaAlbero(){
    nodoAlbero al=(nodoAlbero)malloc(sizeof(nodoAlbe));
    nodoAlbero root=al;
    al->info=50;
    al->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->info=20;
    al->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->info=80;
    al->sx->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->sx->info=10;
    al->sx->sx->sx=NULL;
    al->sx->sx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->sx->dx->info=15;
    al->sx->sx->dx->sx=NULL;
    al->sx->sx->dx->dx=NULL;
    al->sx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->dx->info=30;
    al->sx->dx->sx=NULL;
    al->sx->dx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->dx->dx->info=40;
    al->sx->dx->dx->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->dx->dx->sx->info=35;
    al->sx->dx->dx->sx->sx=NULL;
    al->sx->dx->dx->sx->dx=NULL;
    al->sx->dx->dx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->sx->dx->dx->dx->info=45;
    al->sx->dx->dx->dx->sx=NULL;
    al->sx->dx->dx->dx->dx=NULL;
    al->dx->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->sx->info=60;
    al->dx->sx->sx=NULL;
    al->dx->sx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->sx->dx->info=70;
    al->dx->sx->dx->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->sx->dx->sx->info=65;
    al->dx->sx->dx->sx->sx=NULL;
    al->dx->sx->dx->sx->dx=NULL;
    al->dx->sx->dx->dx=NULL;
    al->dx->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->dx->info=90;
    al->dx->dx->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
    al->dx->dx->sx->info=85;
    al->dx->dx->sx->sx=NULL;
    al->dx->dx->sx->dx=NULL;
    al->dx->dx->dx=NULL;
    return root;
}

void alberi(){
    nodoAlbero a1=creaAlbero();
    printf("********visita preordine********\n");
    visitaAlberoPreorder(a1);
    printf("********visita inordine********\n");
    visitaAlberoInorder(a1);
    printf("********visita postordine********\n");
    visitaAlberoPostorder(a1);
}
