#include <stdio.h>
#include <stdlib.h>
#include "alberiNari.h"
#include "main.h"

void visitaAlberoNarioPreorder(nodoAlberoNario a1){
    nodoAlberoNario temp;
    if(a1){
        printf("%d ",a1->info);
        temp = a1->figlio;
        while(temp!=NULL){
            visitaAlberoNarioPreorder(temp);
            temp=temp->fratello;
        }
    }
}

void visitaAlberoNarioPreorderOld(nodoAlberoNario a1){
    if(a1){
        printf("%d ",a1->info);
        visitaAlberoNarioPreorderOld(a1->figlio);
        visitaAlberoNarioPreorderOld(a1->fratello);
    }
}

void visitaAlberoNarioInorder(nodoAlberoNario a1){
    if(a1){
        visitaAlberoNarioInorder(a1->figlio);
        printf("%d ",a1->info);
        visitaAlberoNarioInorder(a1->fratello);
    }
}

void visitaAlberoNarioPostorder(nodoAlberoNario a1){
    if(a1){
        visitaAlberoNarioPostorder(a1->figlio);
        visitaAlberoNarioPostorder(a1->fratello);
        printf("%d ",a1->info);
    }
}

int maxElemAlberoNario(nodoAlberoNario a1){
    int max=-1;
    if(a1){
        max = a1->info;
        int maxAttuale1,maxAttuale2;
        maxAttuale1=maxElemAlberoNario(a1->figlio);
        maxAttuale2=maxElemAlberoNario(a1->fratello);
        if(maxAttuale2>maxAttuale1){
            printf("%d>%d\n",maxAttuale2,maxAttuale1);
            maxAttuale1=maxAttuale2;
        }
        if(maxAttuale1>max){
            printf("%d>%d\n",maxAttuale1,max);
            max=maxAttuale1;
        }
    }
    return max;
}

int trovaElemAlberoNario(nodoAlberoNario a1,int n){
    if(a1){
        if(a1->info==n){
            return 1;
        }else{
            return trovaElemAlberoNario(a1->figlio,n) || trovaElemAlberoNario(a1->fratello,n);
        }
    }
    return 0;
}

int tuttiPariAlberioNario(nodoAlberoNario a1){
    if(a1){
        if(a1->info%2!=0){
            return 0;
        }else{
            return tuttiPariAlberioNario(a1->figlio) || tuttiPariAlberioNario(a1->fratello);
        }
    }
    return 1;
}

int contaFoglieAlberoNario(nodoAlberoNario a1){
    if(a1){
        if(a1->figlio==NULL){
            return 1+contaFoglieAlberoNario(a1->fratello);
        }else{
            return contaFoglieAlberoNario(a1->figlio)+contaFoglieAlberoNario(a1->fratello);
        }
    }else{
        return 0;
    }
}

int altezzaAlberoNario(nodoAlberoNario a1){
    if(a1){
        nodoAlberoNario temp;
        int altezza=0;
        int altezzaAttuale;
        temp=a1->figlio;
        while(temp) {
            altezzaAttuale=altezzaAlberoNario(temp);
            if (altezzaAttuale > altezza)
                altezza=altezzaAttuale;
            temp=temp->fratello;
        }
        return altezza+1;
    }
    return 0;
}

int numNodiConKfigli(nodoAlberoNario a1, int k){
    int cont=0;
    int contTot=0;
    if(a1){
        nodoAlberoNario temp=a1->figlio;
        while(temp){
            cont++;
            temp=temp->fratello;
        }
        contTot=numNodiConKfigli(a1->figlio,k)+numNodiConKfigli(a1->fratello,k);
        if(cont==k){
            contTot++;
        }
        return contTot;
    }
    return 0;
}

int verificaNodiPariConSoliFigliDispari(nodoAlberoNario a1){
    int rit=1;
    if(a1){
        if(a1->info%2==0){
            nodoAlberoNario temp=a1->figlio;
            while(temp){
                if(temp->info%2==0){
                    return 0;
                }else{
                    temp=temp->fratello;
                }
            }
        }
        rit=verificaNodiPariConSoliFigliDispari(a1->figlio)&&verificaNodiPariConSoliFigliDispari(a1->fratello);
    }
    return rit;
}

int cammino_alberoNario(nodoAlberoNario T, int n, int* A, int *j){
    if(T){
        if(T->info==n && T->figlio==NULL){
            A[*j]=T->info;
            return 1;
        }
        if(cammino_alberoNario(T->figlio,n,A,j) || cammino_alberoNario(T->fratello,n,A,j)){
            *j=*j+1;
            A[*j]=T->info;
            return 1;
        }
    }
    return 0;
}

void livello2array_alberoNario(nodoAlberoNario T, int* arr, int lev, int* n){
    nodoAlberoNario temp;
    if(T!=NULL){
            printf("livello = %d\n",lev);
        if(lev==0){
            temp=T;
            arr[*n] = T->info;
            *n = *n + 1;
            temp=temp->fratello;
            livello2array_alberoNario(temp,arr,lev,n);
        }else{
            livello2array_alberoNario(T->figlio,arr,lev-1,n);
            livello2array_alberoNario(T->fratello,arr,lev,n);
        }

    }
}

void stampaAlberoNarioGrafico(nodoAlberoNario a1){
    nodoAlberoNario a2=a1;
    printf("              %d",a1->info);
    printf("\n             /|\\ ");
    printf("\n            / | \\ ");
    printf("\n           /  |  \\ "); a1=a1->figlio;
    printf("\n          %d   %d   %d\n",a1->info,a1->fratello->info,a1->fratello->fratello->info);
    printf("         / \\      |\n");
    printf("        %d   %d     %d",a1->figlio->info,a1->figlio->fratello->info,a1->fratello->fratello->figlio->info);
    printf("\n                 / \\");a1=a1->fratello->fratello->figlio->figlio;
    printf("\n                %d   %d\n",a1->info,a1->fratello->info);
    printf("---------------------------------------------\n");
    printf("              %d",a2->info);
    printf("\n             /");
    printf("\n            /");
    printf("\n           /"); a2=a2->figlio;
    printf("\n          %d---%d---%d\n",a2->info,a2->fratello->info,a2->fratello->fratello->info);
    printf("         /        |\n");
    printf("        %d---%d     %d",a2->figlio->info,a2->figlio->fratello->info,a2->fratello->fratello->figlio->info);
    printf("\n                 / ");a2=a2->fratello->fratello->figlio->figlio;
    printf("\n                %d---%d\n",a2->info,a2->fratello->info);
}

nodoAlberoNario creaAlberoNarioDaInputPreorder(){
    nodoAlberoNario a1 = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    nodoAlberoNario temp;
    int i,j,k;
    printf("inserire valore e numero di figli separati da uno spazio\n");
    scanf("%d %d",&i,&j);
    if(a1==NULL)
        printf("mem\n");
    else{
        a1->info = i;
        a1->fratello = NULL;
        if(j==0){
            a1->figlio = NULL;
        }else{
            a1->figlio = creaAlberoNarioDaInputPreorder();
            temp=a1->figlio;
            for(k=0;k<j-1;k++){
                printf("entrato nel ciclo con i fratelli di %d\n",a1->figlio->info);
                temp->fratello=creaAlberoNarioDaInputPreorder();
                printf("valore figlio attuale e del fratello %d %d\n",temp->info, temp->fratello->info);
                temp=temp->fratello;
            }
        }
    }return a1;
}

nodoAlberoNario creaAlberoNario(){
    nodoAlberoNario a1 = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->info = 1;
    a1->figlio = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->info = 2;
    a1->figlio->fratello = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->fratello->info = 3;
    a1->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->fratello->fratello->info = 4;
    a1->figlio->fratello->fratello->fratello = NULL;
    a1->figlio->figlio = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->figlio->info = 5;
    a1->figlio->figlio->figlio = NULL;
    a1->figlio->figlio->fratello = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->figlio->fratello->info = 6;
    a1->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->figlio->fratello->fratello = NULL;
    a1->figlio->fratello->fratello->figlio = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->fratello->fratello->figlio->info = 7;
    a1->figlio->fratello->fratello->figlio->fratello = NULL;
    a1->figlio->fratello->fratello->figlio->figlio = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->fratello->fratello->figlio->figlio->info = 8;
    a1->figlio->fratello->fratello->figlio->figlio->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->figlio->fratello->fratello->figlio->figlio->fratello->info = 9;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->figlio = NULL;
    a1->figlio->fratello->fratello->figlio->figlio->fratello->fratello = NULL;
    a1->fratello = NULL;
    return a1;
}

void alberiNari(){
    printf("*********************************************\n");
    printf("*****************ALBERI NARI*****************\n");
    printf("*********************************************\n");
    nodoAlberoNario a1 = creaAlberoNario();
    stampaAlberoNarioGrafico(a1);
   /* printf("inserire i numeri in preordine\n");
    nodoAlberoNario a2 = creaAlberoNarioDaInputPreorder();
    printf("---------------------------------------------\n");
    printf("*************visita preordine-a2*************\n");
    visitaAlberoNarioPreorder(a2);
    */printf("---------------------------------------------\n");
    printf("**************visita preordine***************\n");
    visitaAlberoNarioPreorder(a1);
    printf("\n---------------------------------------------\n");
    printf("*************visita preordineOld*************\n");
    visitaAlberoNarioPreorderOld(a1);
    printf("\n---------------------------------------------\n");
    printf("***************visita inordine***************\n");
    visitaAlberoNarioInorder(a1);
    printf("\n---------------------------------------------\n");
    printf("**************visita postordine**************\n");
    visitaAlberoNarioPostorder(a1);
    printf("\n---------------------------------------------\n");
    /*printf("numero di foglie = %d\n",contaFoglieAlberoNario(a1));
    printf("---------------------------------------------\n");
    printf("max elemento dell'albero n-ario = %d\n",maxElemAlberoNario(a1));
    printf("---------------------------------------------\n");
    printf("ricerca del valore %d nell'albero n-ario\n",4);
    if(trovaElemAlberoNario(a1,4)){
        printf("trovato\n");
    }else{
        printf("non trovato\n");
    }
    printf("---------------------------------------------\n");
    printf("controlla che tutti gli elementi dell'albero siano pari:\n");
    if(tuttiPariAlberioNario(a1)){
        printf("tutti pari\n");
    }else{
        printf("non tutti pari\n");
    }
    printf("---------------------------------------------\n");
    printf("altezza dell'albero = %d\n",altezzaAlberoNario(a1));
    printf("---------------------------------------------\n");
    printf("inserire il numero di figli per sapere quanti nodi hanno questa quantita' di figli:\n");
    int k;
    scanf("%d",&k);
    printf("num di nodi con %d figli = %d\n",k,numNodiConKfigli(a1,k));
    printf("---------------------------------------------\n");
    if(verificaNodiPariConSoliFigliDispari(a1)){
        printf("tutti i nodi pari hanno solo figli dispari\n");
    }else{
        printf("non tutti i nodi pari hanno solo figli dispari\n");
    }

    printf("---------------------------------------------\n");
    printf("cammino dell'albero con nodo %d\n",9);
    int i;
    int *A=(int*)malloc(sizeof(int));
    int j=0;
    cammino_alberoNario(a1,9,A,&j);
    A[j+1]=-1;
    for(i=0;A[i]!=-1;i++){
        if(A[i])
            printf("%d ",A[i]);
    }
    printf("\n");
    free(A);*/
    int* B=(int*)malloc(20*sizeof(int));
    int m=0;
    int z;
    //int livello=3;
    livello2array_alberoNario(a1,B,2,&m);
    B[m]=-1;
    for(z=0;B[z]!=-1;z++){
        if(B[z]!=-1)
            printf("%d ",B[z]);
    }
    printf("\n");
    free(B);
    free(a1);
    //free(a2);
    printf("---------------------------------------------\n");
    main();
}
