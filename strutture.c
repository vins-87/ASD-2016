#include "strutture.h"

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

void strutture(){
    persona *p1=(persona*)malloc(sizeof(persona));
    p1=creaPersona();
    printf("nome: %s\ncognome: %s\nanni: %d",p1->nome,p1->cognome,p1->anni);
    free(p1);
}
