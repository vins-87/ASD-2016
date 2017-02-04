#include <stdio.h>
#include <stdlib.h>
#include "alberi_comune.h"

int magg(int n, int m){
    if(n>m)
        return n;
    return m;
}


int esiste_foglia(albero T, int v){
    if(T){
        if(T->sx==NULL && T->dx==NULL){
            if(T->info==v){
                return 1;
            }
        }
        return esiste_foglia(T->sx,v)||esiste_foglia(T->dx,v);
    }
    return 0;
}

int esiste_nodo_al_livello(albero T,int v, int l){
    if(T){
        if(l==0 && T->info==v){
            return 1;
        }
        return esiste_nodo_al_livello(T->sx,v,l-1)||esiste_nodo_al_livello(T->dx,v,l-1);
    }
    return 0;
}


/** PROFONDITA' NODO
----->INIZIO*/

int livello_foglia(albero a1, int n){
    if(a1){
        if(a1->sx==NULL&&a1->dx==NULL&&a1->info==n){
            return 0;
        }else{
            if(n<a1->info)
                return 1+livello_foglia(a1->sx,n);
            else
                return 1+livello_foglia(a1->dx,n);
        }
    }else{
        return 0;
    }
}
/** PROFONDITA' NODO
<-----FINE*/



int costruisci_aux(albero T, int l, int* A, int cont, albero root){

    if(T){
        if(esiste_nodo_al_livello(root,T->info,l)){
            A[cont] = T->info;
            cont=cont+1;
            return cont;
        }
        cont=costruisci_aux(T->sx,l,A,cont,root);
        cont=costruisci_aux(T->dx,l,A,cont,root);
    }
    return cont;
}

int *costruisci_livello_foglia(albero T, int v){

    if(T){
        if(esiste_foglia(T,v)){
            int l = livello_foglia(T,v);
            int nnl = num_nodi_livello(T,l);
            int *A = (int*)calloc(nnl,sizeof(int));
            costruisci_aux(T,l,A,0,T);
            return A;
        }
    }
    return 0;
}

int altezza_alberi_comune(albero T){
    if(T){
        return 1+magg(altezza_alberi_comune(T->sx),altezza_alberi_comune(T->dx));
    }
    return -1;
}

int num_nodi_livello(albero T, int l){
    if(T){
        if(l==0){
            return 1;
        }
        return num_nodi_livello(T->sx,l-1)+num_nodi_livello(T->dx,l-1);
    }
    return 0;
}

albero creaAlberaccio(){
    albero al=(albero)malloc(sizeof(nodo_albero));
    albero root=al;

    al->info=50;
    al->sx=(albero)malloc(sizeof(nodo_albero));
    al->sx->info=20;
    al->dx=(albero)malloc(sizeof(nodo_albero));
    al->dx->info=80;
    al->sx->sx=(albero)malloc(sizeof(nodo_albero));
    al->sx->sx->info=10;
    al->sx->sx->sx=NULL;
    al->sx->sx->dx=(albero)malloc(sizeof(nodo_albero));
    al->sx->sx->dx->info=15;
    al->sx->sx->dx->sx=NULL;
    al->sx->sx->dx->dx=NULL;
    al->sx->dx=(albero)malloc(sizeof(nodo_albero));
    al->sx->dx->info=30;
    al->sx->dx->sx=NULL;
    al->sx->dx->dx=(albero)malloc(sizeof(nodo_albero));
    al->sx->dx->dx->info=40;
    al->sx->dx->dx->sx=(albero)malloc(sizeof(nodo_albero));
    al->sx->dx->dx->sx->info=35;
    al->sx->dx->dx->sx->sx=NULL;
    al->sx->dx->dx->sx->dx=NULL;
    al->sx->dx->dx->dx=(albero)malloc(sizeof(nodo_albero));
    al->sx->dx->dx->dx->info=45;
    al->sx->dx->dx->dx->sx=NULL;
    al->sx->dx->dx->dx->dx=NULL;
    al->dx->sx=(albero)malloc(sizeof(nodo_albero));
    al->dx->sx->info=60;
    al->dx->sx->sx=NULL;
    al->dx->sx->dx=(albero)malloc(sizeof(nodo_albero));
    al->dx->sx->dx->info=70;
    al->dx->sx->dx->sx=(albero)malloc(sizeof(nodo_albero));
    al->dx->sx->dx->sx->info=65;
    al->dx->sx->dx->sx->sx=NULL;
    al->dx->sx->dx->sx->dx=NULL;
    al->dx->sx->dx->dx=NULL;
    al->dx->dx=(albero)malloc(sizeof(nodo_albero));
    al->dx->dx->info=90;
    al->dx->dx->sx=(albero)malloc(sizeof(nodo_albero));
    al->dx->dx->sx->info=85;
    al->dx->dx->sx->sx=NULL;
    al->dx->dx->sx->dx=NULL;
    al->dx->dx->dx=NULL;
    return root;
}

void esercitazioneDeTuZia(){
    printf("Esercitazione de tu zia\n");

    albero a = creaAlberaccio();

    printf("Esiste una foglia di info %d? %d. Deve ritornare 1\n",15,esiste_foglia(a,15));
    printf("Esiste una foglia di info %d? %d. Deve ritornare 1\n",15,esiste_foglia(a,35));
    printf("Esiste una foglia di info %d? %d. Deve ritornare 1\n",15,esiste_foglia(a,45));
    printf("Esiste una foglia di info %d? %d. Deve ritornare 1\n",15,esiste_foglia(a,65));
    printf("Esiste una foglia di info %d? %d. Deve ritornare 1\n",15,esiste_foglia(a,85));
    printf("Esiste una foglia di info %d? %d. Deve ritornare 0\n",16,esiste_foglia(a,16));


    printf("L'altezza dell'albero e' 5. Ritorna %d\n", altezza(a));

    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",0,1,num_nodi_livello(a,0));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",1,2,num_nodi_livello(a,1));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",2,4,num_nodi_livello(a,2));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",3,4,num_nodi_livello(a,3));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",4,3,num_nodi_livello(a,4));

    printf("Esiste un nodo al livello %d con info %d. Deve ritornare 1. Ritorna %d\n",0,50,esiste_nodo_al_livello(a,50,0));
    printf("Esiste un nodo al livello %d con info %d. Deve ritornare 0. Ritorna %d\n",1,50,esiste_nodo_al_livello(a,50,1));
    printf("Esiste un nodo al livello %d con info %d. Deve ritornare 1. Ritorna %d\n",2,30,esiste_nodo_al_livello(a,30,2));
    printf("Esiste un nodo al livello %d con info %d. Deve ritornare 0. Ritorna %d\n",3,50,esiste_nodo_al_livello(a,50,3));
    printf("Esiste un nodo al livello %d con info %d. Deve ritornare 1. Ritorna %d\n",4,65,esiste_nodo_al_livello(a,65,4));

    printf("I nodi allo stesso livello della foglia contenente info 15 sono: \n<");
    int *arr=(int*)malloc(4*sizeof(int));
    arr=costruisci_livello_foglia(a,15);
    printf("%d %d %d %d",arr[0],arr[1],arr[2],arr[3]);
    printf(">\n Dovrebbero essere: 15, 40, 70, 85\n");
    /*printf("I nodi allo stesso livello della foglia contenente info %d sono: <", 65);
    arr=costruisci_livello_foglia(a,65);
    printf("%d %d %d\n",arr[0],arr[1],arr[2]);
    printf(">\n Dovrebbero essere: 35, 45, 65\n");
*/
    }
