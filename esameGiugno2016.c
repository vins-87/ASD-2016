#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esameGiugno2016.h"

/*dato un albero
binario T, e due stringhe S1 e S2 ritorni 1 se il nodo contenente S2 discende dal nodo contenente S1, 0
altrimenti. Nel caso in cui l�albero T sia vuoto, la stringa S1 non esista in T o la stringa S1 non esista in T
(o entrambe), la funzione deve ritornare 0. Ad esempio verificaDiscendenza(T1, �Alice�,
�John�) ritorner� 1, mentre verificaDiscendenza(T1, �Max�, �John�) ritorner� 0.*/

int verificaDiscendenza_aux(BTree T, stringa S2){
   /* if(T){
        return strcmp(T->nome,S2) || verificaDiscendenza_aux(T->dx,S2) || verificaDiscendenza_aux(T->sx, S2);
    }
*/

    if(T){
        //stampaStringaArray(T->nome);
        printf("\n");
        if(strcmp(T->nome,S2)==0){
            printf("%s = %s\n",T->nome,S2);
            return 1;
        }
        return verificaDiscendenza_aux(T->sx,S2) || verificaDiscendenza_aux(T->dx,S2);
    }
    return 0;
}

int trova_nodo(BTree a1, stringa n){
    if(a1){
        if(strcmp(a1->nome,n)==0){
            printf("%s = %s\n",a1->nome,n);
            return 1;
        }else{
            if(n<a1->nome){
                return trova_nodo(a1->sx,n);
            }else{
                return trova_nodo(a1->dx,n);
            }
        }
    }
    return 0;
}

int verificaDiscendenza(BTree T, stringa S1, stringa S2){
    if(T){

        if(strcmp(T->nome,S1)==0){
            printf("%s = %s\n",T->nome,S1);
            return verificaDiscendenza_aux(T,S2);
            //return trova_nodo(T,S2);
        }
        return verificaDiscendenza(T->sx,S1,S2) || verificaDiscendenza(T->dx,S1,S2);
    }
    return 0;
}
/*
int verificaDiscendenza(BTree T, stringa S1, stringa S2){
    if(T){
        stampaStringaArray(T->nome);
        printf("\n");
        if(strcmp(T->nome,S1)){
            if(T->sx!=NULL){
                if(strcmp(T->sx->nome,S2)){
                    return 1;
                }
            }
            if(T->dx!=NULL)
               if(strcmp(T->dx->nome,S2))
                return 1;
        }
        return verificaDiscendenza(T->sx,S1,S2) || verificaDiscendenza(T->dx,S1,S2);
    }
    return 0;
}
*/
BTree crea_albero_discendenza(){
    BTree T=(BTree)malloc(sizeof(nodo_albero));
    BTree root=T;
    char* s1=(char*)malloc(sizeof(char));
    s1="alice";
    char* s2=(char*)malloc(sizeof(char));
    s2="alex";
    char* s3=(char*)malloc(sizeof(char));
    s3="bob";
    char* s4=(char*)malloc(sizeof(char));
    s4="len";
    char* s5=(char*)malloc(sizeof(char));
    s5="max";
    char* s6=(char*)malloc(sizeof(char));
    s6="john";
    strcpy(T->nome,s1);
    T->sx=(BTree)malloc(sizeof(nodo_albero));
    strcpy(T->sx->nome,s2);
    T->dx=(BTree)malloc(sizeof(nodo_albero));
    strcpy(T->dx->nome,s3);
    T->sx->sx=(BTree)malloc(sizeof(nodo_albero));
    strcpy(T->sx->sx->nome,s4);
    T->sx->sx->sx=NULL;
    T->sx->sx->dx=NULL;
    T->sx->dx=NULL;
    T->dx->sx=(BTree)malloc(sizeof(nodo_albero));
    strcpy(T->dx->sx->nome,s5);
    T->dx->sx->sx=NULL;
    T->dx->sx->dx=NULL;
    T->dx->dx=(BTree)malloc(sizeof(nodo_albero));
    strcpy(T->dx->dx->nome,s6);
    T->dx->dx->sx=NULL;
    T->dx->dx->dx=NULL;

    return root;
}

void esame_giugno2016(){
    BTree T=crea_albero_discendenza();
    //printf("%d\n",verificaDiscendenza_aux(T,"john"));
    if(verificaDiscendenza(T,"alice","john")){
        printf("john discende da alice\n");
    }else{
        printf("john non discende da alice\n");
    }
    if(verificaDiscendenza(T,"max","john")){
        printf("john discende da max\n");
    }else{
        printf("john non discende da max\n");
    }
}
