#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int* creaArray(int dim){
    int *v;
    int i;
    v=(int*)calloc(dim,sizeof(int));
    printf("inserisci %d elementi nell'array\n",dim);
    for(i=0;i<dim;i++)
        scanf("%d",&v[i]);
    return v;
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

void vet(){
    int *v;
    int dim=5;
    int max;
    v=creaArray(dim);
    max=maxElemArray(v,dim);
    printf("massimo elemento dell'array = %d\n",max);
}
