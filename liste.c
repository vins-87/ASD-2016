#include<stdio.h>
#include<stdlib.h>
#include "liste.h"
#include "array.h"

void stampaLista(plist p){
    printf("lista: ");
    if(p!=NULL){
        while(p->next!=NULL){
            printf("%d",p->info);
            p=p->next;
        }
    }
    printf("%d\n",p->info);
}

int valore_massimo_lista(plist p){

    /* scrivi qui il codice che calcola il valore massimo
       contenuto in una lista semplicemente concatenata di
       interi passata in input e lo ritorna come output.
       Se la lista non ha nessun elemento ritorna zero. */

    int max=0;
    if(p!=NULL){
        max=p->info;
        while(p->next!=NULL){
            //printf("%d",p->info);
            if(p->info>max){
                max=p->info;
            }
            p=p->next;
        }
        if(p->info>max){
            max=p->info;
        }
    }
    return max;
}

int trovaElem(plist *p, int elem){
    plist temp=*p;
    while(temp!=NULL){
        if(temp->info==elem){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void inserisciInCoda(plist *p, int n){
    plist temp=(plist)malloc(sizeof(elist));
    temp->info=n;
    temp->next=NULL;
    if(*p==NULL){
        *p=temp;
    }else{
        plist temp2=*p;
        while(temp2->next!=NULL){
            //scorri lista fino alla fine
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}

int compara_array_lista(int A[], int n, plist p){
    /* Scrivi qui il codice che conta quanti elementi dell'array A
       lungo n siano presenti anche nella lista semplicemente
       concatenata p di interi.
       L'array A ha tutti elementi distinti, mentre la lista p
       potrebbe avere elementi duplicati. Se un elemento di A
       appare duplicato in p, deve essere contato una sola volta.
       Se la lista e' vuota oppure n e' zero allora ritorna zero.  */
    int i;
    int cont=0;
    plist temp=p;
    int ret;
    if(temp!=NULL&&n!=0){
        plist temp2=NULL;
        while(temp!=NULL){
            for(i=0;i<n;i++){
                if(temp->info==A[i]){
                    if(ret==0){
                        inserisciInCoda(&temp2,A[i]);
                        cont++;
                    }
                }
            }
            temp=temp->next;
        }
    }
    return cont;
}

lista* creaLista(){
    lista *l1=(lista*)malloc(sizeof(lista));
    l1->prev=NULL;
    l1->next=NULL;
    l1->info=0;
    return l1;
}

plist creaElist(){
    plist p=NULL;
    printf("inserisci 5 elementi nella lista\n");
    int i;
    int n;
    for(i=0;i<5;i++){
       scanf("%d",&n);
       inserisciInCoda(&p,n);
    }
    printf("\n");
    return p;
}

void liste(){
/*    lista *l2=creaLista();
    printf("stampa valore nodo: %d\n",l2->info);
    free(l2);
*/    plist p=creaElist();
/*    stampaLista(p);
    int max=valore_massimo_lista(p);
    printf("max elem della lista: %d",max);
*/  int A[]={2,5,4,6,1};
    int ret=compara_array_lista(A,5,p);
    printf("totale di num trovati: %d\n",ret);
    free(p);
}
