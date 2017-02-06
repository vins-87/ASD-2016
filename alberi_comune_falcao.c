#include <stdio.h>
#include <stdlib.h>

typedef struct elem_de_tu_zia{
    int info;
    struct elem_de_tu_zia* sx;
    struct elem_de_tu_zia* dx;
} nodo_albero;

typedef nodo_albero* albero;

int num_nodi_livello_falcao(albero T, int l){
    if(T){
        if(l==0){
            return 1;
        }
        return num_nodi_livello_falcao(T->sx,l-1)+num_nodi_livello_falcao(T->dx,l-1);
    }
    return 0;
}

int costruisci_livello_nodo_aux(albero T,int *array, int l, int cont){
    if(T==NULL)
        return cont;

    if(l==0){
        *(array+cont) = T->info;
        cont = cont+1;
        return cont;
    }

    cont = costruisci_livello_nodo_aux(T->sx, array, l-1, cont);
    cont = costruisci_livello_nodo_aux(T->dx, array, l-1, cont);

    return cont;
}

int *costruisci_livello_nodo(albero T, int l){
    if(T==NULL)
        return NULL;

    int *result;
    int nodiAlLivello = num_nodi_livello_falcao(T, l);           // Calcolo il numero di nodi al livello i
    result = (int*)malloc(nodiAlLivello*sizeof(int));            // E mallocco un array di dimensione adeguata

    costruisci_livello_nodo_aux(T,result,l,0);

    return result;
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int height(albero T){
    if(T==NULL)
        return 0;
    if(T->sx==NULL && T->dx == NULL)
        return 1;
    return 1 + max(height(T->sx), height(T->dx));
}

/*
dato un albero T1, e un albero T2, costruire (dinamicamente) un array A tale per cui:
l’indice di tale array corrisponde agli indici dei livelli di T1
ad ogni indice i di A bisogna associare un array B che sarà NULL se T1 e T2 non hanno alcun nodo con lo stesso valore contenuto al
livello i (di entrambi) altrimenti B conterrà i valori dei nodi al livello i di T1.
*/

int nodo_in_comune_livello_falcao(int l, albero T1, albero T2){
    if(T1 == NULL || T2 == NULL)
        return 0;
    if(l == 0 && T1->info==T2->info)
        return 1;
    return nodo_in_comune_livello_falcao(l-1, T1->sx, T2->sx) || nodo_in_comune_livello_falcao(l-1, T1->dx, T2->dx) ||
           nodo_in_comune_livello_falcao(l-1, T1->sx, T2->dx) || nodo_in_comune_livello_falcao(l-1, T1->dx, T2->sx);
}

int** livelli_nodo_comune_falcao(albero T1, albero T2){
    int i;
    int livelliT1 = height(T1);

    int **result;

    result = (int**)malloc(livelliT1*(sizeof(int*)));

    for(i=0; i<livelliT1; i++){                                        // i = livello di T1
        if(nodo_in_comune_livello_falcao(i,T1,T2))                     // Se ho un nodo in comune al livello i tra T1 e T2
                *(result+i) = costruisci_livello_nodo(T1,i);           // Costruisco l'array di elementi al livello i
        else
            *(result+i) = NULL;
    }

    return result;
}

albero creaAlberaccioFalcao(){
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

albero crea_alberetto_falco(){
    albero a1=(albero)malloc(sizeof(nodo_albero));
    albero root=a1;

    a1->info=52;
    a1->sx=(albero)malloc(sizeof(nodo_albero));
    a1->dx=(albero)malloc(sizeof(nodo_albero));
    a1->sx->info=18;
    a1->dx->info=81;
    a1->sx->sx=(albero)malloc(sizeof(nodo_albero));
    a1->sx->sx->info=10;
    a1->sx->sx->sx=NULL;
    a1->sx->sx->dx=NULL;
    a1->sx->dx=NULL;
    a1->dx->sx=(albero)malloc(sizeof(nodo_albero));
    a1->dx->dx=(albero)malloc(sizeof(nodo_albero));
    a1->dx->dx->info=90;
    a1->dx->dx->sx=NULL;
    a1->dx->dx->dx=NULL;
    a1->dx->sx->info=61;
    a1->dx->sx->sx=(albero)malloc(sizeof(nodo_albero));
    a1->dx->sx->dx=(albero)malloc(sizeof(nodo_albero));
    a1->dx->sx->sx->info=42;
    a1->dx->sx->sx->sx=NULL;
    a1->dx->sx->sx->dx=NULL;
    a1->dx->sx->dx->info=73;
    a1->dx->sx->dx->sx=NULL;
    a1->dx->sx->dx->dx=NULL;
    return root;
}

void esercitazioneDellaZiaDeFalcao(){
    printf("Esercitazione della zia de falcao\n");

    albero a = creaAlberaccioFalcao();
    albero b = crea_alberetto_falco();

    printf("L'altezza dell'albero e' 5. Ritorna %d\n", height(a));

    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",0,1,num_nodi_livello_falcao(a,0));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",1,2,num_nodi_livello_falcao(a,1));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",2,4,num_nodi_livello_falcao(a,2));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",3,4,num_nodi_livello_falcao(a,3));
    printf("Il numero di nodi al livello %d e' %d. Ritorna %d\n",4,3,num_nodi_livello_falcao(a,4));

    int* arr2 = costruisci_livello_nodo(a,2);
    int x;
    for(x=0;x<num_nodi_livello_falcao(a,2);x++){
        printf("%d ",arr2[x]);
    }
    printf("\n");

    int** arr1=livelli_nodo_comune_falcao(a,b);
    int i,j;
    for(i=0; i<height(a) ;i++){
        if(arr1[i]!=NULL)
            for(j=0; j<num_nodi_livello_falcao(a,i); j++){
                printf("%d ", arr1[i][j]);
            }
        printf("\n");
    }
}
