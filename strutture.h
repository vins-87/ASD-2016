#include<stdio.h>
#include<stdlib.h>
#include "stringhe.h"
//strutture.h
#ifndef STRUTTURE_H
#define STRUTTURE_H
#define H 5

typedef struct{
    stringa nome;
    stringa cognome;
    int anni;
}persona;

typedef struct{
    float x;
    float y;
}Punto;

#endif // STRUTTURE_H

persona* creaPersona();
void strutture();
void leggiPunto(Punto a[], int dim);
void stampaPunto(Punto a[], int dim);
Punto puntoMedio(Punto a, Punto b);
float calcolaDistanza(Punto a, Punto b);

