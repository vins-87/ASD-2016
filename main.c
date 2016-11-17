#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "array.h"
#include "stringhe.h"
#include "strutture.h"
#include "liste.h"

int main(){

    int sel=0;
    printf("Vins ebreo?\n(0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=alberi binari\n");
    scanf("%d",&sel);
    switch(sel){

        case 0: vet();
                break;
        case 1: matrice();
                break;
        case 2: stringhe();
                break;
        case 3: strutture();
                break;
<<<<<<< HEAD
        case 4: liste();
                break;
=======

>>>>>>> 10e1356c4cbd3624d2db0121061716ba74e70df0
        default: printf("esci");
                break;
    }

    return 0;
}
