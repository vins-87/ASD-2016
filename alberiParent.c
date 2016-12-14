#include <stdio.h>
#include <stdlib.h>
#include "alberiParent.h"
#include "alberi.h"

/** VISITE ALBERO
----->INIZIO */
void visitaAlberoParentPreorder(nodoAlberoParent a1){
    if(a1){
        printf("%d ",a1->info);
        visitaAlberoParentPreorder(a1->sx);
        visitaAlberoParentPreorder(a1->dx);
    }
}

void visitaAlberoParentInorder(nodoAlberoParent a1){
    if(a1){
        visitaAlberoParentInorder(a1->sx);
        printf("%d ",a1->info);
        visitaAlberoParentInorder(a1->dx);
    }
}

void visitaAlberoParentPostorder(nodoAlberoParent a1){
    if(a1){
        visitaAlberoParentPostorder(a1->sx);
        visitaAlberoParentPostorder(a1->dx);
        printf("%d ",a1->info);
    }
}
/** VISITE ALBERO
<-----FINE */

/** PROFONDITA' NODO
----->INIZIO*/
int profonditaNodoAux(nodoAlberoParent a1){
    if(a1){
        return 1+profonditaNodoAux(a1->parent);
    }else{
        return 0;
    }
}

int profonditaNodo(nodoAlberoParent a1, int n){
    if(a1){
        if(a1->info==n){
            return profonditaNodoAux(a1);
        }else{
            return maggiore(profonditaNodo(a1->sx,n),profonditaNodo(a1->dx,n));
        }
    }else{
        return -1;
    }
}
/** PROFONDITA' NODO
<-----FINE*/

/** NUMERO TOTALI DI NODI DELL'ALBERO
----->INIZIO*/
int contaNodi(nodoAlberoParent a1){
    if(a1){
        return 1+contaNodi(a1->sx)+contaNodi(a1->dx);
    }else{
        return 0;
    }
}
/** NUMERO TOTALI DI NODI DELL'ALBERO
<-----FINE*/

/** NUMERO DI NODI AL LIVELLO level
----->INIZIO*/
int contaNodiLivello(nodoAlberoParent a1, int level){
    if(a1){
        if(level==0){
            return 1;
        }
        return contaNodiLivello(a1->sx,level-1)+contaNodiLivello(a1->dx,level-1);
    }else{
        return 0;
    }
}
/** NUMERO DI NODI AL LIVELLO L
<-----FINE*/

/** CREA ALBERO CON PARENT
----->INIZIO*/
nodoAlberoParent creaAlberoParent(){
    nodoAlberoParent al=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    nodoAlberoParent root=al;
    al->info=50;
    al->parent=NULL;
    al->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->info=20;
    al->sx->parent=al;
    al->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->info=80;
    al->dx->parent=al;
    al->sx->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->sx->info=10;
    al->sx->sx->parent=al->sx;
    al->sx->sx->sx=NULL;
    al->sx->sx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->sx->dx->info=15;
    al->sx->sx->dx->parent=al->sx->sx;
    al->sx->sx->dx->sx=NULL;
    al->sx->sx->dx->dx=NULL;
    al->sx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->dx->info=30;
    al->sx->dx->parent=al->sx;
    al->sx->dx->sx=NULL;
    al->sx->dx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->dx->dx->info=40;
    al->sx->dx->dx->parent=al->sx->dx;
    al->sx->dx->dx->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->dx->dx->sx->info=35;
    al->sx->dx->dx->sx->parent=al->sx->dx->dx;
    al->sx->dx->dx->sx->sx=NULL;
    al->sx->dx->dx->sx->dx=NULL;
    al->sx->dx->dx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->sx->dx->dx->dx->info=45;
    al->sx->dx->dx->dx->parent=al->sx->dx->dx;
    al->sx->dx->dx->dx->sx=NULL;
    al->sx->dx->dx->dx->dx=NULL;
    al->dx->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->sx->info=60;
    al->dx->sx->parent=al->dx;
    al->dx->sx->sx=NULL;
    al->dx->sx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->sx->dx->info=70;
    al->dx->sx->dx->parent=al->dx->sx;
    al->dx->sx->dx->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->sx->dx->sx->info=65;
    al->dx->sx->dx->sx->parent=al->dx->sx->dx;
    al->dx->sx->dx->sx->sx=NULL;
    al->dx->sx->dx->sx->dx=NULL;
    al->dx->sx->dx->dx=NULL;
    al->dx->dx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->dx->info=90;
    al->dx->dx->parent=al->dx;
    al->dx->dx->sx=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
    al->dx->dx->sx->info=85;
    al->dx->dx->sx->parent=al->dx->dx;
    al->dx->dx->sx->sx=NULL;
    al->dx->dx->sx->dx=NULL;
    al->dx->dx->dx=NULL;
    return root;
}
/** CREA ALBERO CON PARENT
<-----FINE*/

void alberiParent(){
    nodoAlberoParent a1=creaAlberoParent();
    visitaAlberoParentPreorder(a1);
    printf("\n");
    visitaAlberoParentInorder(a1);
    printf("\n");
    visitaAlberoParentPostorder(a1);
    printf("\n");
    printf("profondita del nodo %d = %d\n",45,profonditaNodo(a1,45));
    printf("numero totale di nodi albero = %d\n",contaNodi(a1));
    printf("numero di nodi al livello %d = %d\n",0,contaNodiLivello(a1,0));
    printf("numero di nodi al livello %d = %d\n",1,contaNodiLivello(a1,1));
    printf("numero di nodi al livello %d = %d\n",2,contaNodiLivello(a1,2));
    printf("numero di nodi al livello %d = %d\n",3,contaNodiLivello(a1,3));
    printf("numero di nodi al livello %d = %d\n",4,contaNodiLivello(a1,4));
    printf("numero di nodi al livello %d = %d\n",5,contaNodiLivello(a1,5));
}
