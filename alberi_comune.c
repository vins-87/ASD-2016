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
    return 0;
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

int livello2array_aux(albero T, int l, int* A, int cont, albero root){

    if(T){
        if(esiste_nodo_al_livello(root,T->info,l)){
            A[cont] = T->info;
            cont=cont+1;
            return cont;
        }
        cont=livello2array_aux(T->sx,l,A,cont,root);
        cont=livello2array_aux(T->dx,l,A,cont,root);
    }
    return cont;
}

int *livello2array(albero T, int lev){
    if(T){
        int nnl = num_nodi_livello(T,lev);
        int *A = (int*)calloc(nnl,sizeof(int));
        livello2array_aux(T,lev,A,0,T);
        return A;
    }
    return 0;
}

void riempi(albero T, int* arr, int lev, int* i){
    if(T){
        if(lev==0){
            arr[*i] = T->info;
            *i = *i + 1;
        }
        else{
            riempi(T->sx,arr,lev-1,i);
            riempi(T->dx,arr,lev-1,i);
        }
    }
}

void livelli_nodo_comune_aux(albero root, albero T1, albero T2, int** A, int* B, int lev){
    if(T1){
        if(A[lev]==NULL){
            int dim=num_nodi_livello(root,lev);//numero di nodi di un livello
            int* C=calloc(dim,sizeof(int));
            B=calloc(dim,sizeof(int));
            C=livello2array(root,lev);//mette tutti i nodi del livello lev dentro un array
            int i;
            int j=0;
            //int x=0;
            //riempi(root,C,lev,&x);
            for(i=0;i<dim;i++){
                int n=C[i];
                if(esiste_nodo_al_livello(T2,n,lev)){
                    B[j]=n;
                    j++;
                }
            }
            B[j]=-1;
            A[lev]=B;
        }
        livelli_nodo_comune_aux(root,T1->sx,T2,A,B,lev+1);
        livelli_nodo_comune_aux(root,T1->dx,T2,A,B,lev+1);
    }
}

int** livelli_nodo_comune(albero T1, albero T2){
    if(T1&&T2){
        int altT1=altezza_alberi_comune(T1);
        int altT2=altezza_alberi_comune(T2);
        int altMax=magg(altT1,altT2);
        printf("altezza = %d\n",altMax);
        int** A=calloc(altMax+1,sizeof(int*));
        int* B=NULL;
        int i;
        for(i=0;i<altMax;i++){
            A[i]=NULL;
        }
        livelli_nodo_comune_aux(T1,T1,T2,A,B,0);
        return A;
    }
    return NULL;
}

void livelli_figli_nodo_aux(alberoN T, int x){

}

/*dato un albero binario T1, un albero di grado arbitrario T2, un intero x e un intero h,
ritornare 1 (true) se tutti i figli del nodo in T2 contenente x sono nodi posizionati al livello h di T1.
Ritornare 0 (false) altrimenti.*/
int livelli_figli_nodo(albero T1, alberoN T2, int x, int h){
    if(T2){
        if(T2->info==x){
            T2=T2->figlio;
            while(T2){
                if(!esiste_nodo_al_livello(T1,T2->info,h)){
                    return 0;
                }
                T2=T2->fratello;
            }
            return 1;
        }
        return livelli_figli_nodo(T1,T2->figlio,x,h) || livelli_figli_nodo(T1,T2->fratello,x,h);
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

alberoN crea_alberoN(){
    alberoN a1 = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->info = 1;
    a1->figlio = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->info = 2;
    a1->figlio->fratello = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->info = 3;
    a1->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->fratello->info = 4;
    a1->figlio->fratello->fratello->fratello = NULL;
    a1->figlio->figlio = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->figlio->info = 5;
    a1->figlio->figlio->figlio = NULL;
    a1->figlio->figlio->fratello = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->figlio->fratello->info = 6;
    a1->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->figlio->fratello->fratello = NULL;
    a1->figlio->fratello->fratello->figlio = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->fratello->figlio->info = 7;
    a1->figlio->fratello->fratello->figlio->fratello = NULL;
    a1->figlio->fratello->fratello->figlio->figlio = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->fratello->figlio->figlio->info = 40;
    a1->figlio->fratello->fratello->figlio->figlio->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->fratello->figlio->figlio->fratello->info = 15;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello = (alberoN)malloc(sizeof(nodo_alberoN));
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->info = 85;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->fratello = NULL;
    a1->fratello = NULL;
    return a1;
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


    printf("L'altezza dell'albero e' 5. Ritorna %d\n", altezza_alberi_comune(a));

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
    printf(">\nDovrebbero essere: 15, 40, 70, 85\n");
    printf("I nodi allo stesso livello della foglia contenente info %d sono: \n<", 65);
    arr=costruisci_livello_foglia(a,65);
    printf("%d %d %d",arr[0],arr[1],arr[2]);
    printf(">\nDovrebbero essere: 35, 45, 65\n");

    int** arr1=livelli_nodo_comune(a,a);
    int i,j;
    for(i=0;arr1[i];i++){
        for(j=0;arr1[i][j]!=-1;j++){
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }

    alberoN a2 = crea_alberoN();
    printf("risultato di livelli_figli_nodo = %d\n",livelli_figli_nodo(a,a2,7,3));
}
