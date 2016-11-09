#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringhe.h"

/** MODI PER CREARE STRINGHE
    char s[100];
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",s);
    -------------------------------------
    char str[]="Questa e' una Prova";
    -------------------------------------
    stringa s=(stringa)malloc(sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",s);
    -------------------------------------
    stringa s=(stringa)calloc(4,sizeof(char));
    s="ciao";
    -------------------------------------
    char str[100];
    str="Questa e' una Prova";  --> SBAGLIATO
*/

char* creaStringa(){
    stringa s=(stringa)malloc(sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",s);
    return s;
}

void stampaStringa(stringa s){
    printf("%s\n",s);
}

char* copiaStringa(stringa ss){
    stringa sd;
    sd=(stringa)malloc(sizeof(char));
    return strcpy(sd,ss);
}

int confrontaStringhe(stringa s1,stringa s2){
    return strcmp(s1,s2);
}

char* concatenaStringhe(stringa s1, stringa s2){
    return strcat(s1,s2);
}

void stringhe(){
    int cmp;
    stringa str1,str2;
    str1=creaStringa();
    str2=creaStringa();
    stampaStringa(str1);
    str2=copiaStringa(str1);
    printf("\nstringa %s copiata. risultato= %s\n",str1,str2);
    cmp=confrontaStringhe(str1,str2);
    if(cmp==0)
        printf("le stringhe sono uguali\n");
    else
        printf("le stringhe sono diverse\n");
    str2=concatenaStringhe(str1,str2);
    printf("\nstringa risultante = %s",str2);
}
