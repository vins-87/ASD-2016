#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"

//CREA E RIEMPI MATRICE PASSANDOGLI LE SUE DIMENSIONI
int** creaMatricePiena(int r, int c){
    int **A;
    int i;
    A = (int**)calloc(r,sizeof(int*));
    for (i=0; i<r; i++)
        A[i] = (int*)calloc(c,sizeof(int));
    A[0][0]=5;
    A[0][1]=8;
    A[1][0]=7;
    A[1][1]=9;
    return A;
}

//CREA MATRICE RIEMPIENDOLA DA INPUT PASSANDOGLI LE SUE DIMENSIONI
int** creaMatriceDaInput(int r, int c){
    int** A;
    int i,j;
    printf("inserire gli elementi della matrice\n");
    A = (int**)calloc(r,sizeof(int*));
    for (i=0; i<r; i++)
        A[i] = (int*)calloc(c,sizeof(int));
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            scanf("%d",&A[i][j]);
  return A;
}

/*
* Completa questo codice in linguaggio C in modo che la funzione valore_massimo ritorni il valore massimo della matrice A
*/
int valore_massimo(int **A, int r, int c){
    /* scrivi qui il codice che ritorna il valore massimo di una matrice A di interi con r righe e c colonne */
    int i;
    int j;
    int max=A[0][0];

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(max<A[i][j])
                max=A[i][j];
        }
    }
    return max;
}

void matrice(){
    printf("*********************************************\n");
    printf("*******************MATRICI*******************\n");
    printf("*********************************************\n");
    int **A;
    int r=2;
    int c=2;
    int rit;

    A=creaMatriceDaInput(r,c);
    //A=creaMatricePiena(r,c);
    rit=valore_massimo(A,r,c);

    printf("Valore max della matrice = %d",rit);
}

