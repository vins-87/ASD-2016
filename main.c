#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "array.h"
#include "stringhe.h"
#include "strutture.h"
#include "liste.h"
#include "elezioni.h"

int main(){
int sel;
    while(sel!=-1){
        sel=0;
        printf("Vins ebreo?\n(-1=esci,0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=elezioni, 6=alberi binari\n");
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
            case 4: liste();
                    break;
            case 5: elezioni();
                    break;

            default: printf("esci");
                    break;
        }
    }
    return 0;
}
