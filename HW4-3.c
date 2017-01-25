#include <stdio.h>  /* ora puoi usare NULL */
#include <stdlib.h>

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi:
primo campo ha nome info ed è di tipo intero,
secondo campo ha nome sx (un puntatore al sottoalbero sinistro),
terzo campo ha nome dx (un puntatore al sottoalbero destro) [IMPORTANTE: non modificare l'ordine dei campi] */

typedef struct nodo_albero{
    int info;
    struct nodo_albero *sx;
    struct nodo_albero *dx;
}nodo_alb;


/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef nodo_alb *albero;


/* scrivi qui eventuali funzioni di appoggio */

int max_array(int *v, int dim){
    int i;
    int max;
    max=v[0];
    for(i=0;i<dim;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

int livello_Nodo(albero T, int n){
    if(T){
        if(T->info==n){
            return 0;
        }else{
            if(n<T->info){
                return 1+livello_Nodo(T->sx,n);
            }else{
                return 1+livello_Nodo(T->dx,n);
            }
        }
    }
    return 0;
}

int* larghezza_albero_aux(albero T, albero root,int* vet){
    if(T){
        int liv=livello_Nodo(root,T->info);
        vet[liv]++;
        larghezza_albero_aux(T->sx,root,vet);
        larghezza_albero_aux(T->dx,root,vet);
    }
    return vet;
}

/* INIZIO FUNZIONE */

int larghezza_albero(albero T){

    /* Dato un un albero binario T di interi, la funzione larghezza_albero deve ritornare la larghezza di T;
    la larghezza di un albero binario è il numero massimo di nodi che stanno tutti al medesimo livello.
    Nel caso in cui T sia vuoto la funzione ritornerà 0.*/

    int *vet = (int*)calloc(50,sizeof(int));
    return max_array(larghezza_albero_aux(T,T,vet),10);
}

albero creaAlberoHW4_3(){
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

void hw4_3(){
    albero T =creaAlberoHW4_3();
    printf("larghezza albero = %d\n",larghezza_albero(T));
}
