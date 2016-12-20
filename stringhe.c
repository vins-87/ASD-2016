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


void leggiStringaArray(char s[]){
    int i;
    printf("Inserire %d caratteri!\n",N);

    for(i=0;i<N;i++){
        scanf("%s",&s[i]);
    }

}

//CREA STRINGA DI DIMENSIONE 100 E RITORNA IL PUNTATORE AD ESSA
char* creaStringa(){
    stringa st=(stringa)malloc(100*sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",st);
    return st;
}

void stampaStringaArray(char s[]){
    int i;

    printf("La stringa inserita e':\n");
    for(i=0;s[i]!='\0';i++)
        printf("%c",s[i]);
    printf("\n");
}

//STAMPA STRINGA PASSANDO IL SUO PUNTATORE
void stampaStringaPuntatore(stringa s){
    printf("%s\n",s);
}

int numeroDiOccorrenze(char s[], char c){
    int result = 0;
    int i;

    for(i=0; s[i]!='\0' ;i++)     // Per ogni elemento nella parte successiva del vettore
        if(s[i]==c)     //Se il carattere che ho preso in esame e' uguale a uno degli elementi del resto del vettore
            result++;
    return result;
}

Container letteraPiuRicorrente(char s[]){
    Container result;   // Struttura dati

    int i;              // Contatore

    char caratterePiuRicorrente;
    int numeroOccorrenze;

    numeroOccorrenze=1;             // Inizializzazione variabili
    caratterePiuRicorrente = s[0];

    stampaStringaArray(s);

    int temp;      // Variabile temporanea per salvare il numero di ricorrenze di una lettera in un array

    for(i=0;s[i]!='\0';i++){           //Per ogni elemento del vettore
        temp = numeroDiOccorrenze(s, s[i]);

        if(temp > numeroOccorrenze){
            caratterePiuRicorrente = s[i];
            numeroOccorrenze = temp;
        }
    }
/*
    nric=numeroDiOccorrenze(s,s[i]);
    if(nric>numeroOccorrenze){
        numeroOccorrenze=nric;
    }
*/
    result.cOcc=caratterePiuRicorrente;
    result.numOcc=numeroOccorrenze;

    return result;
}


void stringheVins(){
    int cmp=0;
    stringa str1,str2;
    str1=creaStringa();
    str2=creaStringa();
    strcpy(str1,str2);
    printf("\nstringa %s copiata. risultato= %s\n",str1,str2);
    cmp=strcmp(str1,str2);
    if(cmp==0)
        printf("le stringhe sono uguali\n");
    else
        printf("le stringhe sono diverse\n");
    strcat(str1,str2);
    printf("\nstringa risultante = %s",str1);
    free(str1);
    free(str2);
}

void stringheVale(){
    char s[N];
    Container c;

    leggiStringaArray(s);
    stampaStringaArray(s);

    c = letteraPiuRicorrente(s);

    printf("\nLa lettera piu ricorrente nella stringa inserita e': %c\nAppare %d volte.", c.cOcc, c.numOcc);

}

void stringhe(){
    printf("*********************************************\n");
    printf("******************STRINGHE*******************\n");
    printf("*********************************************\n");
    int m=0;
    printf("VALE(1) O VINS(2)?\n");
    scanf("%d",&m);
    if(m==1)
        stringheVale();
    else
        stringheVins();
}

