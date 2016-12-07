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


/*  Legge una sequenza di punti di dimensione dim*/

void leggiPunti(Punto a[], int dim){
    int i;

    for(i=0;i<dim;i++){
        printf("(%d)X: ",i+1);
        scanf("%f", &a[i].x);
        printf("(%d)Y: ",i+1);
        scanf("%f", &a[i].y);
    }
}

/* Stampa la sequenza di punti di dimensione dim */
void stampaPunti(Punto a[], int dim){
    int i;

    for(i=0;i<dim;i++){
        printf("(%d) (%f",i+1, a[i].x);
        printf(",%f)\n", a[i].y);
    }
}

/* Restituisce il punto medio tra i due passati per parametro */
Punto puntoMedio(Punto a, Punto b){
    Punto result;

    result.x = (a.x+b.x)/2;
    result.y = (a.y+b.y)/2;

    return result;
}


/* Restituisce la distanza tra i due punti passati per parametro (teorema di Pitagora) */
float calcolaDistanza(Punto a, Punto b){
    float result;
    float deltaX;
    float deltaY;

    /* Calcolo della distanza sull'asse delle ascisse se xA>xB*/
    if(a.x>b.x)
        deltaX=a.x-b.x;
    else
        deltaX=b.x-a.x;

    /* Calcolo della distanza sull'asse delle ascisse se yA>yB*/
    if(a.y>b.y)
        deltaY=a.y-b.y;
    else
        deltaY=b.y-a.y;

    result = sqrt(deltaX*deltaX + deltaY*deltaY);   // Teroema di Pitagora

    return result;
}

void persone(){
    persona *p1=(persona*)malloc(sizeof(persona));
    p1=creaPersona();
    printf("nome: %s\ncognome: %s\nanni: %d",p1->nome,p1->cognome,p1->anni);
    free(p1);
}

void punti(){
    Punto p[H];
    printf("\nInserisci le coordinate di %d punti.",H);
    leggiPunti(p,H);
    stampaPunti(p,H);
    Punto medio = puntoMedio(p[0],p[1]);
    printf("Il punto medio tra i primi due punti inseriti e' di coordinate (%f,%f)",medio.x,medio.y);
    float dist = calcolaDistanza(p[0],p[1]);
    printf("La distanza misurata tra i primi due punti e' %f", dist);
}

void strutture(){
    persone();
    punti();

}
