#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "array.h"
#include "stringhe.h"
#include "strutture.h"
#include "liste.h"
#include "elezioni.h"
#include "persone.h"
#include "alberi.h"
#include "alberiParent.h"
#include "alberiNari.h"
#include "main.h"

int main(){

    int sel=0;
    printf("Vins ebreo?\n(-1=esci,0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=elezioni, 6=EsercitazioneByVins,\n");
    printf("(7=alberiBinari, 8=alberiBinariParent, 9=alberiNari)\n");
    scanf("%d",&sel);
    switch(sel){
        case -1: break;

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
        case 6: elezioniByVins();
                break;
        case 7: alberi();
                break;
        case 8: alberiParent();
                break;
        case 9: alberiNari();
                break;
    }
    return 0;
}
