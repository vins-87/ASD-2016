#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "array.h"
#include "stringhe.h"

int main()
{
    int sel=0;
    printf("cosa vogliamo usare?\n(0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=alberi binari\n");
    scanf("%d",&sel);
    switch(sel){
        case 0: vet();
                break;
        case 1: matrice();
                break;
        case 2: stringhe();
                break;
        default: return 0;
    }

    return 0;
}
