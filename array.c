/************************************************-ATTENZIONE-**********************************************************
Tutti i metodi sono in ordine di utilizzo nella funzione vet(), così come sono nell'ordine specificato nel file array.h
***********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "main.h"

/* Utilizza la logica degli indirizzi per stampare l'array */
void stampaArray(vettore v, int lung){
    if(v){
        int i;
        //int n=lunghezzaArray(v);
        for(i=0;i<lung;i++){
            printf("%d ",v[i]);
        }
    }
    printf("\n");
}

/* Una sequenza S di 27 interi si dice perfetta se per ogni i tale che i 2 [1::9] allora i ricorre
esattamente tre volte nella sequenza S. Ad esempio, la sequenza
(1,9,1,2,1,8,2,4,6,2,7,9,4,5,8,6,3,4,7,5,3,9,6,8,3,5,7)
e' perfetta. Si scriva una funzione C che prende come parametro un vettore di 27 interi
e restituisce true (1) se il vettore rappresenta una sequenza perfetta e false (0) altrimenti.*/
int sequenzaPerfetta(vettore v,int dim){
    int perfetta=0;
    if(dim==27){
        int i,j;
        int cont=0;
        perfetta=1;
        for(i=1;i<10;i++){
            for(j=0;j<27;j++){
                if(v[j]==i){
                    cont++;
                }
            }
            if(cont!=3){
                return 0;
            }
            cont=0;
        }
    }
    return perfetta;
}

int trovaElemArray(int v[], int dim, int n){
    int i;
    for(i=0;i<dim;i++){
        if(v[i]==n)
            return 1;
    }
    return 0;
}

int maxElemArray(int *v, int dim){
    int i;
    int max;
    max=v[0];
    for(i=0;i<dim;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

/*  Esercizio: Scrivere un programma che data una sequenza di 10 numeri interi calcoli
    Il numero di valori pari (e quindi anche di valori dispari)
    Quale dei due numeri sia maggiore (messaggio su video)
*/
void pariDispari(int a[], int dim){
    int i;
    int np=0;
    int nd=0;
    for(i=0;i<M;i++){
        if(a[i]%2==0)
            np++;
        else
            nd++;
    }
    if(np>nd)
        printf("\nci sono piu numeri pari che dispari\n");
    else{
        if(np<nd)
            printf("\nci sono piu numeri dispari che pari\n");
        else
            printf("\nc'e la stessa quantita di numeri pari e dispari\n");
    }
}


/*
    Funzione che prende il puntatore a un vettore come parametro. Ordina il vettore tramite selection sort.
    La logica utilizzata per scandire è quella degli indirizzi.
    Per chiarezza:  a[0] = *a;
                    a[4] = *(a+4);
    E' stato utilizzato un aloritmo di selection-sort come richiesto dall'esercizio
*/
void sort(int *a){
    int i;
    int j;
    int posmin;
    int min;

    for(i=0;i<M;i++){       //Per ogni elemento a[i] del vettore
        posmin=i;
        min=a[i];

        for(j=i+1;j<M;j++){ //Per ogni elemento della parte successiva a a[i] del vettore

            if(min>a[j]){   //Condizione di minimo
                posmin=j;
                min=a[j];
            }

        }

        if(posmin!=i){          // Scambio l'elemento in posizione i-esima con l'elemento in posizione di minimo
            a[posmin] = a[i];
            a[i] = min;
        }

    }
}

//  Esercizio: Scrivere un programma per calcolare la potenza b di un numero intero a (con b >= 0).
void potenza(int num, int pot){
    int ris=1;
    int i;
    for(i=0;i<pot;i++){
        ris=ris*num;
    }
    printf("\n%d elevato a %d = %d\n",num,pot,ris);
}

/*  Esercizio: Scrivere un programma per calcolare la potenza b di un numero intero a (con b >= 0).
    Questa volta però utilizzando una funzione ricorsiva.
*/
int potenzaRicorsiva(int num, int pot){
    if(pot==1)
        return num;
    else{
        num=num*potenzaRicorsiva(num,pot-1);
    }
    return num;
}

//CREA ARRAY DA INPUT E RITORNA IL PUNTATORE AD ESSA
vettore creaArray(int dim){
    vettore v=calloc(M,sizeof(int));
    int i;
    printf("\nInserisci %d elementi nell'array\n",M);
    for(i=0;i<M;i++){
        scanf("%d",&v[i]);
    }
    return v;
}

void vet(){
    printf("*********************************************\n");
    printf("********************ARRAY********************\n");
    printf("*********************************************\n");
    vettore v=creaArray(M);
    printf("\nmassimo elemento dell'array = %d\n",maxElemArray(v,M));
    pariDispari(v,M);
    sort(v);
    printf("\nArray ordinato:\n");
    stampaArray(v,10);
    printf("---------------------------------------------\n");
    int w[27]={1,9,1,2,1,8,2,4,6,2,7,9,4,5,8,6,3,4,7,5,3,9,6,8,3,5,7};
    int n=(sizeof(w)/sizeof(w[0]));
    stampaArray(w,n);
    printf("lunghezza array = %d\n",n);
    if(sequenzaPerfetta(w,n)){
        printf("sequenza perfetta\n");
    }else{
        printf("sequenza non perfetta\n");
    }
    free(v);
    printf("---------------------------------------------\n");
    potenza(3,2);

    int ris;
    int n1,n2;

    n1=3;
    n2=4;
    ris=potenzaRicorsiva(n1,n2);
    printf("\npotenza ricorsiva di %d elevato a %d = %d\n",n1,n2,ris);
    printf("\n---------------------------------------------\n");
    main();
}
