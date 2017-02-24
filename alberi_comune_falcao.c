#include <stdio.h>
#include <stdlib.h>

typedef struct elem_de_tu_zia{
    int info;
    struct elem_de_tu_zia* sx;
    struct elem_de_tu_zia* dx;
} nodo_albero;

typedef struct elem_de_tu_zia_lista{
    int info;
    struct elem_de_tu_zia_lista *next;
}elem_tu_zia;

typedef struct elem2zia{
    int info;
    struct elem2zia* figlio;
    struct elem2zia* fratello;
} elem2zia_N;

typedef elem2zia_N* alberoNtuzia;

typedef elem_tu_zia* lista_alberi_comune;

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

void costruisci_livello_nodo_aux(albero T,int *array, int l, int *cont){
    if(T==NULL)
        return;

    if(l==0){
        array[*cont] = T->info;
        *cont = *cont+1;
    }
    costruisci_livello_nodo_aux(T->sx, array, l-1, cont);
    costruisci_livello_nodo_aux(T->dx, array, l-1, cont);
}

int *costruisci_livello_nodo(albero T, int l){
    if(T==NULL)
        return NULL;

    int *result;
    int nodiAlLivello = num_nodi_livello_falcao(T, l);           // Calcolo il numero di nodi al livello i
    result = (int*)malloc(nodiAlLivello*sizeof(int));           // E mallocco un array di dimensione adeguata
    int *c = (int*)malloc(sizeof(int));
    *c=0;
    costruisci_livello_nodo_aux(T,result,l,c);

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

/* ========================== ESERCIZIO livelli_figli_nodo ==========================*/

lista_alberi_comune inserisciInTesta_tuzia(int x, lista_alberi_comune p){
    lista_alberi_comune temp = (lista_alberi_comune)malloc(sizeof(elem_tu_zia));

    temp->info = x;
    temp->next = p;
    p=temp;

    return p;
}

lista_alberi_comune creaNodoLista_tuzia(int k){
    lista_alberi_comune result = (lista_alberi_comune)malloc(sizeof(elem_tu_zia));

    result->info = k;
    result->next = NULL;

    return result;
}

lista_alberi_comune figliAlberoLivello(albero T,int l, lista_alberi_comune list){
    if(T==NULL)
        return list;
    if(l==0){
        if(list){
            list = inserisciInTesta_tuzia(T->info, list);
        }
        else{
            list = creaNodoLista_tuzia(T->info);
        }

    }

    list = figliAlberoLivello(T->sx,l-1,list);
    list = figliAlberoLivello(T->dx,l-1,list);

    return list;
}

int lunghezzaLista(lista_alberi_comune l){
    int result = 0;
    while(l){
        result++;
        l=l->next;
    }
    return result;
}

int esisteIn(lista_alberi_comune l, int k){
    while(l){
        if(l->info==k)
            return 1;
        l=l->next;
    }
    return 0;
}

int confrontaListe2zia(lista_alberi_comune l1, lista_alberi_comune l2){
    if(l1==NULL || l2==NULL)
        return 0;

    int cont = 0;
    int lunghList = lunghezzaLista(l2);

    while(l2!=NULL){
        if(esisteIn(l1,l2->info))
            cont++;
        l2 = l2->next;
    }

    return cont >= lunghList;
}

lista_alberi_comune inserisciFigliInLista(alberoNtuzia T, lista_alberi_comune l){
    if(T==NULL)
        return l;

    while(T->fratello!=NULL){
        if(l)
            l = inserisciInTesta_tuzia(T->info,l);
        else
            l = creaNodoLista_tuzia(T->info);

        T = T->fratello;
    }

    l = inserisciInTesta_tuzia(T->info,l);

    return l;
}

lista_alberi_comune figliAlberoInfo(alberoNtuzia T, int x, lista_alberi_comune l){
    if(T==NULL)
        return l;

    if(T->info==x)
        l = inserisciFigliInLista(T->figlio,l);


    l=figliAlberoInfo(T->fratello,x,l);
    l=figliAlberoInfo(T->figlio,x,l);

    return l;
}

/*
 dato un albero binario T1, un albero di grado arbitrario T2, un intero x e un intero h, ritornare 1 (true)
 se tutti i figli del nodo in T2 contenente x sono nodi posizionati al livello h di T1.
 Ritornare 0 (false) altrimenti.
*/

void stampaListatuzia(lista_alberi_comune p){
    if(p){
        printf("%d ",p->info);
        stampaListatuzia(p->next);
    }
}

int livelli_figli_nodo_falcao(albero T1, alberoNtuzia T2, int x, int h){
    if(T1==NULL || T2==NULL)
        return 0;

    lista_alberi_comune l1 = NULL;
    l1 = figliAlberoLivello(T1,h,l1);

    lista_alberi_comune l2 = NULL;
    l2 = figliAlberoInfo(T2,x,l2);

    printf("lista l1: ");
    stampaListatuzia(l1);
    printf("\nlista l2: ");

    stampaListatuzia(l2);
    printf("\n");

    return confrontaListe2zia(l1,l2);
}

alberoNtuzia crea_alberoN_tuzia(){
    alberoNtuzia a1 = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->info = 1;
    a1->figlio = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->info = 2;
    a1->figlio->fratello = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->info = 3;
    a1->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->fratello->info = 4;
    a1->figlio->fratello->fratello->fratello = NULL;
    a1->figlio->figlio = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->figlio->info = 5;
    a1->figlio->figlio->figlio = NULL;
    a1->figlio->figlio->fratello = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->figlio->fratello->info = 6;
    a1->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->figlio->fratello->fratello = NULL;
    a1->figlio->fratello->fratello->figlio = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->fratello->figlio->info = 7;
    a1->figlio->fratello->fratello->figlio->fratello = NULL;
    a1->figlio->fratello->fratello->figlio->figlio = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->fratello->figlio->figlio->info = 40;
    a1->figlio->fratello->fratello->figlio->figlio->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->fratello->figlio->figlio->fratello->info = 15;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello = (alberoNtuzia)malloc(sizeof(elem2zia_N));
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->info = 85;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello->fratello = NULL;
    a1->fratello = NULL;
    return a1;
}

int verificaDiscendenza_falcao(albero T, int a){
    if(T==NULL)
        return 0;

    if(T->info==a)
        return 1;

    return verificaDiscendenza_falcao(T->sx,a) || verificaDiscendenza_falcao(T->dx,a);
}

int funzionaCheFunziona_falcao(albero T, int a, int b){
    if(T==NULL)
        return 0;

    if(T->info==a)
        if(T->sx!=NULL || T->dx!=NULL)
            return verificaDiscendenza_falcao(T->sx,b) || verificaDiscendenza_falcao(T->dx,b);

    return funzionaCheFunziona_falcao(T->sx,a,b) || funzionaCheFunziona_falcao(T->dx,a,b);

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

    alberoNtuzia c = crea_alberoN_tuzia();
    printf("risultato di livelli_figli_nodo = %d\n",livelli_figli_nodo_falcao(a,c,7,3));

    albero t = creaAlberaccioFalcao();
    printf("da 20 discende 35 = %d",funzionaCheFunziona_falcao(t,50,35));
    printf("da 35 non discende 15 = %d",funzionaCheFunziona_falcao(t,35,15));
}
