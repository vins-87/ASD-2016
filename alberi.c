#include <stdio.h>
#include <stdlib.h>
#include "alberi.h"
#include "main.h"

/** VISITE ALBERO
----->INIZIO */
void visitaAlberoPreorder(nodoAlbero a1){
    if(a1){
        printf("%d ",a1->info);
        visitaAlberoPreorder(a1->sx);
        visitaAlberoPreorder(a1->dx);
    }
}

void visitaAlberoInorder(nodoAlbero a1){
    if(a1){
        visitaAlberoInorder(a1->sx);
        printf("%d ",a1->info);
        visitaAlberoInorder(a1->dx);
    }
}

void visitaAlberoPostorder(nodoAlbero a1){
    if(a1){
        visitaAlberoPostorder(a1->sx);
        visitaAlberoPostorder(a1->dx);
        printf("%d ",a1->info);
    }
}
/** VISITE ALBERO
<-----FINE */

/** ALTEZZA ALBERO
----->INIZIO*/
int maggiore(int n, int m){
    if(n>m){
        return n;
    }else{
        return m;
    }
}

int altezzaAlbero(nodoAlbero a1){
    if(a1){
        return 1+maggiore(altezzaAlbero(a1->sx),altezzaAlbero(a1->dx));
    }else{
        return -1;
    }
}
/** ALTEZZA ALBERO
<-----FINE*/

int ricerca(nodoAlbero t, int k){
    if(t == NULL)
        return 0;
    return t->info == k || ricerca(t->dx,k) || ricerca(t->sx, k);

}

/** MAX ELEM ALBERO
----->INIZIO*/
int max3(int a, int b, int c) {
    if (a > b)
        if (c > a)
            return c;
        else
            return a;
    else
        if (c > b)
            return c;
        else
            return b;
}

int get_max(nodoAlbero t) {
   int max_sx, max_dx;
   /* caso base: albero vuoto */
    if (t == NULL) return -1;
        max_sx = get_max(t->sx);
        max_dx = get_max(t->dx);
    return max3(max_sx, max_dx, t->info);
}
/** MAX ELEM ALBERO
<-----FINE*/

/** ALBERI UGUALI
----->INIZIO*/
int uguali(nodoAlbero a1, nodoAlbero a2){
    if(a1==NULL&&a2==NULL){
        return 1;
    }
    if(a1==NULL||a2==NULL){
        return 0;
    }
    return a1->info==a2->info&&uguali(a1->sx,a2->sx)&&uguali(a1->dx,a2->dx);
}
/** ALBERI UGUALI
<-----FINE*/

/** ARRAY 2 ALBERO
----->INIZIO*/
void arr2alberoAux(nodoAlbero a1, int arr[], int i,int dim){
    if(a1!=NULL&&i<dim){
        a1->info=arr[i];
        if(((2*i)+1)<dim){
            a1->sx=(nodoAlbero)malloc(sizeof(nodoAlbe));
            a1->sx->sx=NULL;
            a1->sx->dx=NULL;
            arr2alberoAux(a1->sx,arr,((2*i)+1),dim);
        }
        if(((2*i)+2)<dim){
            a1->dx=(nodoAlbero)malloc(sizeof(nodoAlbe));
            a1->dx->sx=NULL;
            a1->dx->dx=NULL;
            arr2alberoAux(a1->dx,arr,((2*i)+2),dim);
        }
    }
}

nodoAlbero arr2albero(int arr[], int dim){
    nodoAlbero a1=(nodoAlbero)malloc(sizeof(nodoAlbe));
    nodoAlbero root=a1;
    int i=0;
    a1->info=arr[0];
    arr2alberoAux(a1,arr,i,dim);
    return root;
}
/** ARRAY 2 ALBERO
<-----FINE*/

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
    printf("*********************************************\n");
    printf("****************ALBERI BINARI****************\n");
    printf("*********************************************\n");
    nodoAlbero a1=creaAlbero();
    printf("---------------------------------------------\n");
    printf("**************visita preordine***************\n");
    visitaAlberoPreorder(a1);
    printf("\n---------------------------------------------\n");
    printf("***************visita inordine***************\n");
    visitaAlberoInorder(a1);
    printf("\n---------------------------------------------\n");
    printf("**************visita postordine**************\n");
    visitaAlberoPostorder(a1);
    printf("\n---------------------------------------------\n");
    printf("**************CREA ALBERO DA ARRAY************\n");
    printf("arr[]={69,89,28,39,66,44,12,2,71}\n");
    int arr[]={69,89,28,39,66,44,12,2,71};
    nodoAlbero a2=arr2albero(arr,9);
    printf("**************visita postordine**************\n");
    visitaAlberoPostorder(a2);
    printf("\n**************visita preordine***************\n");
    visitaAlberoPreorder(a2);
    printf("\naltezza albero = %d",altezzaAlbero(a2));
    printf("\nmassimo elemento dell'albero = %d",get_max(a2));
    printf("\n---------------------------------------------\n");
    printf("\n**************visita preordine***************\n");
    visitaAlberoPreorder(a2);
    printf("\n");
    visitaAlberoPreorder(a2);
    if(uguali(a2,a2)){
        printf("\nalberi uguali");
    }else{
        printf("\nalberi diversi");
    }
    printf("\n---------------------------------------------\n");
    visitaAlberoPreorder(a1);
    printf("\n");
    visitaAlberoPreorder(a2);
    if(uguali(a1,a2)){
        printf("\nalberi uguali");
    }else{
        printf("\nalberi diversi");
    }
    printf("\n---------------------------------------------\n");
    printf("\nAlbero contiene il numero 10? Si, dovrebbe risultare 1. Risulta: %d", ricerca(a1,10));
    printf("\nAlbero contiene il numero 10? No, dovrebbe risultare 0. Risulta: %d\n", ricerca(a1,0));

    free(a1);
    free(a2);
    main();
}
