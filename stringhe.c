#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringhe.h"
#include "main.h"

/** MODI PER CREARE STRINGHE
    printf("quanti caratteri vuoi inserire?\n");
    int dim;
    scanf("%d",&dim);
    char* s= (char*)malloc(dim*sizeof(char));
        printf("Inserisci una stringa qualsiasi:\n");
    while(i<dim){
        char temp;
        scanf("%c",&temp);
        s[i]=temp;
    }
    -------------------------------------
    char str[]="Questa e' una Prova";
    -------------------------------------
    stringa s=(stringa)malloc(sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%c",s);
    -------------------------------------
    stringa s=(stringa)calloc(4,sizeof(char));
    s[0]='c';
    s[1]='i';
    s[2]='a';
    s[3]='o';
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

int lunghezzaStringa(stringa s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}

int contieneMaiuscole(stringa s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='A'&&s[i]<='Z'){
            return 1;
        }
        i++;
    }
    return 0;
}

int contieneMinuscole(stringa s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='a'&&s[i]<='z'){
            return 1;
        }
        i++;
    }
    return 0;
}

int isPalindroma(stringa s){
    int i=0;
    int j=lunghezzaStringa(s)-1;
    while(i<j){
        if(s[i]!=s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int isSottostringa(stringa s1,stringa s2){
    int i=0;
    int j;
    int trovato=0;
    int lung1=lunghezzaStringa(s1);
    int lung2=lunghezzaStringa(s2);
    if(lung1>=lung2){
        int cont=0;
        int k=0;
        for(j=0;j<lung2;j++){
            if(s1[k]==s2[j]){
                cont++;
            }
            k++;
        }
        if(cont==lung2){
            trovato = 1;
        }else{
            trovato = isSottostringa(&s1[i+1],s2);
        }
    }
    return trovato;
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

void stampaArrayDiStringhe(stringa* as, int dim){
    int i;
    printf("|");
    for(i=0;i<dim;i++){
        printf(" %s |",as[i]);
    }
    printf("\n");
}

stringa copiaStringa(stringa s1,stringa s2){
    int i=0;
    while(s2[i]!='\0'){
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
    return s1;
}

int confrontaStringhe(stringa s1,stringa s2){
    int i;
    int ret=0;
    int cont1=0;
    int cont2=0;
    if(s1[0]!='\0'&&s2[0]!='\0'){
        if(lunghezzaStringa(s1)>lunghezzaStringa(s2)){
            return 1;
        }else if(lunghezzaStringa(s1)<lunghezzaStringa(s2)){
            return -1;
        }
        for(i=0;i<lunghezzaStringa(s1);i++){
            if(s1[i]>s2[i]){
                cont1++;
            }else if(s1[i]<s2[i]){
                cont2++;
            }
        }
        if(cont1>cont2){
            ret=1;
        }else if(cont1<cont2){
            ret=-1;
        }
    }
    if(s1[0]=='\0'&&s2[0]!='\0'){
        ret = 1;
    }else if(s1[0]!='\0'&&s2[0]=='\0'){
        ret = -1;
    }
    return ret;
}

stringa concatenaStringhe(stringa s1, stringa s2){
    int i,j;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++){
        s1[i+j]=s2[j];
    }
    s1[i+j]='\0';
    return s1;
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

/*Si scriva una funzione C che prende come parametri una stringa ed un carattere e
restituisce un'altra stringa, da cui sono state rimosse tutte le occorrenze del carattere.
Ad esempio, se la funzione viene chiamata con parametri "tutta statistica" e 't' deve
restituire la stringa "ua saisica".
La lunghezza della stringa di ingresso non e nota. E' richiesto di non sprecare memoria.
In particolare, la memoria allocata per la stringa in uscita deve essere esattamente uguale
a quella necessaria per la sua memorizzazione. Si richiede inoltre di gestire eventuali errori
nella fase di allocazione di memoria, restituendo NULL in caso di insuccesso.*/
stringa rimuoviOccorrenze(stringa s, char c){
    printf("cerco il carattere %c da %s\n",c,s);
    int i=0;
    int cont=0;
    while(s[i]!='\0'){
        if(s[i]!=c){
            cont++;
        }
        i++;
    }
    stringa s1 = calloc(cont,sizeof(char));
    i=0;
    int j=0;
    while(s[i]!='\0'){
        if(s[i]!=c){
            s1[j]=s[i];
            j++;
        }
        i++;
    }
    s1[j]='\0';
    return s1;
}

stringa* trasformaStringhe(stringa *v,int dim){
    int i;
    for(i=0;i<dim;i++){
        int lungs=lunghezzaStringa(v[i]);
        int j;
        char c1=v[i][lungs-2];
        char c2=v[i][lungs-1];
        for(j=i+1;j<dim;j++){
            if(v[j][0]==c1&&v[j][1]==c2){
                int k=2;
                stringa stemp=(stringa)calloc(20,sizeof(char));
                int x=0;
                while(v[j][k]!='\0'){
                    char c=v[j][k];
                    stemp[x]=c;
                    lungs++;
                    k++;
                    x++;
                }
                concatenaStringhe(v[i],stemp);
                j=dim;
            }
        }
    }
    return v;
}

//CREA STRINGA DI DIMENSIONE 100 E RITORNA IL PUNTATORE AD ESSA
stringa creaStringa(){
    stringa st=(stringa)malloc(100*sizeof(char));
    printf("Inserisci una stringa qualsiasi:\n");
    scanf("%s",st);
    return st;
}

stringa* creaArrayDiStringhe(){
    stringa s1=(stringa)calloc(50,sizeof(char));
    strcpy(s1,"stoca");
    stringa s2=(stringa)calloc(50,sizeof(char));
    strcpy(s2,"cazzo");
    stringa *v=(stringa*)calloc(2,sizeof(stringa));
    v[0]=s1;
    v[1]=s2;
    return v;
}

void stringheVins(){
    stringa str1,str2;
    str1=creaStringa();
    str2=creaStringa();
    printf("---------------------------------------------\n");
    printf("lunghezza di %s = %d\n",str1,lunghezzaStringa(str1));
    printf("---------------------------------------------\n");
    if(contieneMaiuscole(str1)){
        printf("%s contiene maiuscole\n",str1);
    }else{
        printf("%s non contiene maiuscole\n",str1);
    }
    printf("---------------------------------------------\n");
    if(contieneMinuscole(str1)){
        printf("%s contiene minuscole\n",str1);
    }else{
        printf("%s non contiene minuscole\n",str1);
    }
    printf("---------------------------------------------\n");
    if(isPalindroma(str1)){
        printf("%s palindroma\n",str1);
    }else{
        printf("%s non palindroma\n",str1);
    }
    printf("---------------------------------------------\n");
    if(isSottostringa(str1,str2)){
        printf("stringa %s inclusa in %s\n",str2,str1);
    }else{
        printf("stringa %s non inclusa %s\n",str2,str1);
    }
    printf("---------------------------------------------\n");
    if(confrontaStringhe(str1,str2)==0)
        printf("le stringhe sono uguali\n");
    else
        printf("le stringhe sono diverse\n");
    printf("---------------------------------------------\n");
    printf("copia %s in %s = ","ciao",str1);
    printf("%s\n",copiaStringa(str1,"ciao"));
    printf("---------------------------------------------\n");
    printf("%s + %s =",str1,str2);
    printf(concatenaStringhe(str1,str2));
    printf("\n---------------------------------------------\n");
    printf("scegliere la lettera da rimuovere dalla stringa %s\n",str1);
    char ch;
    scanf(" %c",&ch);
    printf("carattere %c inserito\n",ch);
    stringa sr=rimuoviOccorrenze(str1,ch);
    printf("risultato = %s\n",sr);
    printf("---------------------------------------------\n");
    printf("array di stringhe da trasformare:\n");
    stringa* v= creaArrayDiStringhe();
    stampaArrayDiStringhe(v,2);
    trasformaStringhe(v,2);
    printf("array di stringhe modificato:\n");
    stampaArrayDiStringhe(v,2);
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
    printf("\n---------------------------------------------\n");
    main();
}

