#include <stdio.h>
#include <stdlib.h>
#include "alberiParent.h"
#include "alberi.h"
#include "main.h"

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

/** NUMERO DI FOGLIE
----->INIZIO*/
int contaFoglie(nodoAlberoParent a1){
    if(a1){
        if(a1->sx==NULL && a1->dx==NULL){
            return 1;
        }else{
            return contaFoglie(a1->sx)+contaFoglie(a1->dx);
        }
    }else{
        return 0;
    }
}
/** NUMERO DI FOGLIE
<-----FINE*/

/** INSERIMENTO NODO IN ALBERO BINARIO DI RICERCA
----->INIZIO*/
int addNodoAlbero(nodoAlberoParent *a1, nodoAlberoParent genitore, int n){
    if(*a1==NULL){
        *a1=(nodoAlberoParent)malloc(sizeof(nodoAlbeP));
        (*a1)->info=n;
        (*a1)->parent=genitore;
        (*a1)->sx=NULL;
        (*a1)->dx=NULL;
    }else{
        if((*a1)->info==n){
            return 0;
        }else{
            if(n<(*a1)->info){
                printf("%d < %d\n",n,(*a1)->info);
                return addNodoAlbero(&(*a1)->sx,*a1,n);
            }else{
                printf("%d > %d\n",n,(*a1)->info);
                return addNodoAlbero(&(*a1)->dx,*a1,n);
            }
        }
    }
    return 1;
}
/** INSERIMENTO NODO IN ALBERO BINARIO DI RICERCA
<-----FINE*/

/** RICERCA DEL MINIMO ELEMENTO NELL'ALBERO
----->INIZIO*/
int nodoMinBST(nodoAlberoParent a1){
    if(a1){
        if(a1->sx==NULL){
            return a1->info;
        }else{
            return nodoMinBST(a1->sx);
        }
    }
    return 0;
}
/** RICERCA DEL MINIMO ELEMENTO NELL'ALBERO
<-----FINE*/

/** RICERCA DEL MASSIMO ELEMENTO NELL'ALBERO
----->INIZIO*/
int nodoMaxBST(nodoAlberoParent a1){
    if(a1){
        if(a1->dx==NULL){
            return a1->info;
        }else{
            return nodoMaxBST(a1->dx);
        }
    }
    return 0;
}
/** RICERCA DEL MASSIMO ELEMENTO NELL'ALBERO
<-----FINE*/

/** RICERCA DI UN NODO NELL'ALBERO
----->INIZIO*/
int trovaNodo(nodoAlberoParent a1, int n){
    if(a1){
        if(a1->info==n){
	    return 1;
        }else{
            if(n<a1->info){
                return trovaNodo(a1->sx,n);
            }else{
                return trovaNodo(a1->dx,n);
            }
        }
    }
    return 0;
}
/** RICERCA DI UN NODO NELL'ALBERO
<-----FINE*/

/** STAMPA DEL CAMMINO DEL NODO
----->INIZIO*/
void stampaCamminoAux(nodoAlberoParent a1, int n){
    if(a1){
        printf("%d ",a1->info);
        if(a1->info==n){
            return;
        }else{
            if(n<a1->info){
                stampaCamminoAux(a1->sx,n);
            }else{
                stampaCamminoAux(a1->dx,n);
            }
        }
    }
}

void stampaCammino(nodoAlberoParent a1, int n){
    if(trovaNodo(a1,n)){
        stampaCamminoAux(a1,n);
    }else{
        printf("non trovato\n");
    }
}
/** STAMPA DEL CAMMINO DEL NODO
<-----FINE*/

/** STAMPA DELL'ALBERO IN VERSIONE GRAFICA
----->INIZIO*/
void stampaAlberoGrafico(nodoAlberoParent a1){
    printf("               %d\n",a1->info);
    printf("       %d              %d\n",a1->sx->info,a1->dx->info);
    printf("   %d      %d      %d      %d\n",a1->sx->sx->info,a1->sx->dx->info,a1->dx->sx->info,a1->dx->dx->info);
    printf("     %d      %d      %d  %d\n",a1->sx->sx->dx->info,a1->sx->dx->dx->info,a1->dx->sx->dx->info,a1->dx->dx->sx->info);
    printf("           %d  %d  %d\n",a1->sx->dx->dx->sx->info,a1->sx->dx->dx->dx->info,a1->dx->sx->dx->sx->info);
}
/** STAMPA DELL'ALBERO IN VERSIONE GRAFICA
<-----FINE*/

/** CREA ALBERO DA INPUT
----->INIZIO*/
nodoAlberoParent creaAlberoParentDaInput(){
    int numNodi;
    int i;
    int nodoAttuale;
    nodoAlberoParent a1 = NULL;
    printf("Creazione albero da input\n");
    printf("Da quanti nodi deve essere composto l'albero?\n");
    scanf("%d",&numNodi);
    for(i=0;i<numNodi;i++){
        printf("Inserire il nodo in posizione %d\n",i);
        scanf("%d",&nodoAttuale);
        if(i==0){
            addNodoAlbero(&a1,NULL,nodoAttuale);
        }else{
            addNodoAlbero(&a1,a1->parent,nodoAttuale);
        }
    }
    return a1;
}
/** CREA ALBERO DA INPUT
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
    printf("*********************************************\n");
    printf("********ALBERI BINARI CON NODO PADRE*********\n");
    printf("*********************************************\n");
    int n;
    nodoAlberoParent a1=creaAlberoParent();
    stampaAlberoGrafico(a1);
    printf("*********************************************\n");
    printf("visita preordine\n");
    visitaAlberoParentPreorder(a1);
    printf("\n*********************************************\n");
    printf("visita inordine\n");
    visitaAlberoParentInorder(a1);
    printf("\n*********************************************\n");
    printf("visita postordine\n");
    visitaAlberoParentPostorder(a1);
    printf("\n*********************************************\n");
    printf("Inserire il nodo del quale percorrere il cammino\n");
    scanf("%d",&n);
    printf("cammino del nodo %d\n",n);
    stampaCammino(a1,n);
    printf("\n*********************************************\n");
    printf("profondita del nodo %d = %d\n",45,profonditaNodo(a1,45));
    printf("*********************************************\n");
    printf("numero totale di nodi albero = %d\n",contaNodi(a1));
    printf("*********************************************\n");
    printf("numero di nodi al livello %d = %d\n",0,contaNodiLivello(a1,0));
    printf("numero di nodi al livello %d = %d\n",1,contaNodiLivello(a1,1));
    printf("numero di nodi al livello %d = %d\n",2,contaNodiLivello(a1,2));
    printf("numero di nodi al livello %d = %d\n",3,contaNodiLivello(a1,3));
    printf("numero di nodi al livello %d = %d\n",4,contaNodiLivello(a1,4));
    printf("numero di nodi al livello %d = %d\n",5,contaNodiLivello(a1,5));
    printf("*********************************************\n");
    printf("numero di foglie = %d\n",contaFoglie(a1));
    printf("*********************************************\n");
    printf("ADD NODO TO ALBERO\n");
    printf("Inserire il nodo da aggiungere all'albero\n");
    scanf("%d",&n);
    if(addNodoAlbero(&a1,a1->parent,n)){
        printf("nodo aggiunto\n");
    }else{
        printf("nodo non aggiunto\n");
    }
    printf("visita preordine\n");
    visitaAlberoParentPreorder(a1);
    printf("\n*********************************************\n");
    a1=creaAlberoParentDaInput();
    printf("visita inordine\n");
    visitaAlberoParentInorder(a1);
    printf("\n*********************************************\n");
    printf("Ricerca del nodo minimo = %d",nodoMinBST(a1));
    printf("\n*********************************************\n");
    printf("Ricerca del nodo massimo = %d",nodoMaxBST(a1));
    printf("\n*********************************************\n");
    printf("Inserisci il nodo da cercare nell'albero\n");
    scanf("%d",&n);
    if(trovaNodo(a1,n)){
        printf("nodo trovato");
    }else{
        printf("nodo non trovato");
    }
    printf("\n---------------------------------------------\n");
    main();
}
