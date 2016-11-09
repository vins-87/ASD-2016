#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringhe.h"

char* creaStringa(){
    char s[100];
/*  char str[]="Questa e' una Prova"; --> CORRETTO
    ---------------------------------------------
    char str[100];
    str="Questa e' una Prova";  --> SBAGLIATO
*/
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

char* copiaStringa(stringa ss){
    stringa sd;
    sd=(stringa)malloc(sizeof(char));
    sd=strcpy(sd,ss);
    return sd;
}

int confrontaStringhe(stringa s1,stringa s2){
    return strcmp(s1,s2);
}

void stringhe(){
    int dim=4;
    int cmp;
    stringa str1;
    str1=creaStringaDim(dim);
    //stampaStringa(str1);
    stringa strd;
    strd=(stringa)malloc(sizeof(char));
    strd=copiaStringa(str1);
    printf("\nstringa %s copiata. risultato= %s\n",str1,strd);
    cmp=confrontaStringhe(str1,strd);
    if(cmp==0)
        printf("le stringhe sono uguali\n");
    else
        printf("le stringhe sono diverse\n");
}
