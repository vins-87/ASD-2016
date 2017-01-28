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
#include "esameSettembre2016.h"
#include "main.h"

int main(){

    int sel=0;
    printf("Vins ebreo?\n(-1=esci,0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=elezioni, 6=EsercitazioneByVins,\n");
    printf("(7=alberiBinari, 8=alberiBinariParent, 9=alberiNari, 10=HW4-1, 11=HW4-2, 12=HW-3, 13=esame sett 2016, 14=hw5)\n");
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
        case 10: hw4_1();
                break;
        case 11: hw4_2();
               break;
        case 12: hw4_3();
                break;
        case 13: esame_settembre_2016();
                break;
        case 14: hw5();
                break;
    }
    return 0;
}
