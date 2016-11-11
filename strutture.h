#include<stdio.h>
#include<stdlib.h>
#include "stringhe.h"
//strutture.h
#ifndef STRUTTURE_H
#define STRUTTURE_H

typedef struct{
    stringa nome;
    stringa cognome;
    int anni;
}persona;


#endif // STRUTTURE_H

persona* creaPersona();
void strutture();
