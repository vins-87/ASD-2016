/************************************************-ATTENZIONE-********************************************************************
Tutti i metodi sono in ordine di utilizzo nella funzione strutture(), così come sono nell'ordine specificato nel file strutture.h
********************************************************************************************************************************/

#include "strutture.h"
#include <math.h>

persona* creaPersona(){
    persona *p=(persona*)malloc(sizeof(persona));
    p->nome=(stringa)malloc(sizeof(char));
    p->cognome=(stringa)malloc(sizeof(char));
    printf("nome: ");
    scanf("%s",p->nome);
    printf("\ncognome: ");
    scanf("%s",p->cognome);
    printf("\nanni: ");
    scanf("%d",&p->anni);
    return p;
}


/*  Legge una sequenza di punti*/
void leggiPunto(Punto a[]){
    int i;

    for(i=0;i<N;i++){
        printf("(%d)X: ",i+1);
        scanf("%f", &a[i].x);
        printf("(%d)Y: ",i+1);
        scanf("%f", &a[i].y);
    }
}

void stampaPunto(Punto a[]){
    int i;

    for(i=0;i<N;i++){
        printf("(%d) (%f",i+1, a[i].x);
        printf(",%f)\n", a[i].y);
    }
}

Punto puntoMedio(Punto a, Punto b){
    Punto result;

    result.x = (a.x+b.x)/2;
    result.y = (a.y+b.y)/2;

    return result;
}

float calcolaDistanza(Punto a, Punto b){
    float result;
    float deltaX;
    float deltaY;

    if(a.x>b.x)
        deltaX=a.x-b.x;
    else
        deltaX=b.x-a.x;

    if(a.y>b.y)
        deltaY=a.y-b.y;
    else
        deltaY=b.y-a.y;

    result = sqrt(deltaX*deltaX + deltaY*deltaY);

    return result;
}

void strutture(){
    persona *p1=(persona*)malloc(sizeof(persona));
    p1=creaPersona();
    printf("nome: %s\ncognome: %s\nanni: %d",p1->nome,p1->cognome,p1->anni);
    free(p1);
}
