#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringhe.h"

typedef char* stringa;

char* creaStringa(){
    char s[100];
    stringa str;
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",s);
    str=s;
    return str;
}

char* creaStringaDin(){
    stringa s;
    s=(stringa)malloc(sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",s);
    return s;
}

char* creaStringaDim(int dim){
    stringa s;
    s=(stringa)calloc(dim,sizeof(char));
    s="ciao";
    return s;
}

void stampaStringa(stringa s){
    int i;
    int len;
    len=strlen(s);
    printf("\nlunghezza stringa: %d",len);
    printf("\nStringa creata:\n");
    for(i=0;i<len;i++){
        printf("%c",s[i]);
    }

}

void stringhe(){
    int dim=4;
    stringa str1;
    //s = creaStringaDim(dim);
    str1=creaStringaDim(dim);
    stampaStringa(str1);
    //printf("\nStringa creata:\n%s\n",s);
}
