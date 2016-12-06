#include <stdio.h>
#include <stdlib.h>
#include "stringhe.h"

int lung(stringa s){
    int i=0;

    while(*(s+i)!='\0')
        i++;

    return i;
}

int confronta(stringa s1, stringa s2){
    int i;
    int cont = 0;

    for(i=0; *(s1+i)!='\0'; i++){
        if(*(s1+i) == *(s2+i))
            cont++;
    }

    if(cont == lung(s1))
        return 1;

    return 0;
}


void copia(stringa s1, stringa s2){
    int i;
    for(i=0; s1[i]!='\0'; i++)
        s2[i] = s1[i];


    s2[i] = '\0';
}
