#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "liste.h"
#include "main.h"

void stampaLista(lista p){
    if(p){
        printf("%d ",p->info);
        stampaLista(p->next);
    }
}

void stampaArrayDiListe(lista *l, int dim){
    int i;
    for(i=0;i<dim;i++){
        while(l[i]){
            printf("%d ",(l[i])->info);
            l[i]=(l[i])->next;
        }
    }
}

void inserisciInCoda(int x, lista* p){
    lista temp = (lista)malloc(sizeof(nodoLista));   // Creo un nuovo nodo
    temp->next = NULL;                             // Inizializzo il nuovo nodo
    temp->info = x;
    if(*p){
        lista temp2=*p;
        while(temp2->next){    // Scorre la lista fino all'ultimo elemento
            temp2=temp2->next;
        }
        //k->prev = p;        // Aggiorno il precedente del nuovo nodo
        temp2->next = temp;        // Aggiungo in coda il nuovo nodo
    }else{
        //k->prev=NULL;
        *p=temp;
    }
}

void inserisciInTesta(int x, lista* p){
    lista temp = (lista)malloc(sizeof(nodoLista));
    temp->info = x;
    temp->next = *p;
    *p=temp;
}

/* Si assuma presente in memoria una lista composta di abbreviazioni (ad esempio TO,
MI, RM) e dalle corrispondenti parole estese implementata tramite record e puntatori
utilizzando la seguente struttura:
struct elem {
char abbr[2];
char *estesa;
struct elem *next;
}
Scrivere una funzione C che, ricevendo come parametri il puntatore all'inizio della
lista, una abbreviazione e la corrispondente parola estesa cerchi l'abbreviazione nella lista
e:
a) restituisca 0 se la coppia e' presente nella lista
b) restituisca 1 se la coppia non e' presente nella lista
c) restituisca 2 se l'abbreviazione e' presente ma ad essa corrisponde una parola
differente.
Inoltre, nel caso b) un nuovo record deve essere aggiunto in coda alla lista e nel caso
c) la parola estesa deve essere sostituita da quella passata come parametro.*/
int trovaTarga(targhe t, char abb[2], stringa ext){
    int i;
    if(t){
        while(t){
            printf("confronto %c%c e %s\n",t->abbr[0],t->abbr[1],abb);
            if(t->abbr[0]==abb[0]&&t->abbr[1]==abb[1]){
                printf("sigla trovata\n");
                for(i=0;i<lunghezzaStringa(t->estesa);i++){
                    printf("confronto %c e %c\n",t->estesa[i],ext[i]);
                    if((t->estesa)[i]!=ext[i]){
                        return 2;
                    }
                }
                return 0;
            }
            t=t->next;
        }
    }
    return 1;
}

/* Si assuma presente in memoria un vettore di puntatori a liste di valori interi positivi. Le
liste sono realizzate tramite record del seguente tipo:
struct nodo {
    int info;
    struct nodo *next;
}
Scrivere una funzione C che prende come parametri il vettore e la sua dimensione,
e restituisce l'indice della locazione del vettore contenente il puntatore alla lista in cui
compare l'elemento di valore massimo tra gli elementi di tutte le liste. Nel caso tutte le
liste siano vuote oppure il vettore abbia dimensione 0, la funzione deve restituire 0.*/
int indiceListaMax(lista *v, int dim){
    int i;
    int max=0;
    int indMax=0;
    for(i=0;i<dim;i++){
        if(v[i]){
            lista temp=v[i];
            printf("lista %d ={ ",i);
            stampaLista(temp);
            printf("}\n");
            while(temp){
                if((temp->info)>max){
                    max=temp->info;
                    indMax=i;
                }
                temp=temp->next;
            }
        }
    }
    return indMax;
}

/* TEST */
int testInserimentoInCoda(){
    int result = 0;
    int CASES = 4;
    int i;

    lista l = NULL;
    l = creaLista(4);

    inserisciInCoda(1,&l);
    inserisciInCoda(2,&l);
    inserisciInCoda(3,&l);
    inserisciInCoda(4,&l);

    l=l->next;

    for(i=1;i<CASES+1;i++){
        if(l->info==i)
            result++;
        l=l->next;
    }

    if(result == CASES)
        return 1;
    else
        return 0;
}

targhe creaListaTarghe(){
    targhe ta=(targhe)malloc(sizeof(targa));
    targhe t=ta;
    t->abbr[0]='C';
    t->abbr[1]='E';
    t->estesa="Caserta";
    t->next=(targhe)malloc(sizeof(targa));
    t->next->abbr[0]='R';
    t->next->abbr[1]='M';
    t->next->estesa="Roma";
    t->next->next=(targhe)malloc(sizeof(targa));
    t->next->next->abbr[0]='L';
    t->next->next->abbr[1]='T';
    t->next->next->estesa="Latina";
    t->next->next->next=NULL;
    return ta;
}

lista* creaArrayDiListe(int dim){
    lista *v=calloc(dim,sizeof(lista));
    int i;
    for(i=0;i<dim;i++){
        int j=0;
        lista l=NULL;
        while(j<3){
            printf("inserire elemento da aggiungere alla lista con indice %d\n",i);
            int n;
            scanf("%d",&n);
            inserisciInCoda(n,&l);
            j++;
        }
        printf("\n");
        v[i]=l;
    }
    return v;
}

lista creaLista(int dim){
    int i,n;
    lista l1=NULL;
    for(i=0;i<dim;i++){
        printf("inserire elemento nella lista\n");
        scanf("%d",&n);
        inserisciInCoda(n,&l1);
    }
    return l1;
}

void liste(){
    printf("*********************************************\n");
    printf("********************LISTE********************\n");
    printf("*********************************************\n");
    lista l1=(lista)malloc(sizeof(nodoLista));
    int dim=2;
    l1=creaLista(dim);
    printf("\n---------------------------------------------\n");
    printf("stampa valore nodo: %d\n",l1->info);   // Stampa valore primo elemento della lista
    printf("\nTest di inserimento in coda risulta: %d\n", testInserimentoInCoda());
    free(l1);
    printf("---------------------------------------------\n");
    lista *l2=creaArrayDiListe(dim);
    printf("\nindice max = %d\n",indiceListaMax(l2,dim));
    printf("---------------------------------------------\n");
    targhe t=creaListaTarghe();
    printf("ris targhe = %d\n",trovaTarga(t,"RM","Roma"));
    printf("\n---------------------------------------------\n");
    main();
}
