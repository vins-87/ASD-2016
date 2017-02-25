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
#include "alberi_comune.h"
#include "main.h"

int main(){

    int sel=0;
    printf("Quale tipologia di esercizi vuoi vedere?\n(-1=esci,0=array, 1=matrici, 2=stringhe, 3=strutture, 4=liste, 5=elezioni, 6=EsercitazioneByVins,\n");
    printf("(7=alberiBinari, 8=alberiBinariParent, 9=alberiNari, 10=HW4-1, 11=HW4-2, 12=HW-3, 13=esame sett 2016, 14=hw5)\n");
    printf("(15=esame feb 2016 B, 16=esercitazione de tu zia, 17=esercitazioneDellaZiaDeFalcao, 18=esame giu 2016)\n");
    scanf("%d",&sel);
    switch(sel){
        case -1: break;

        case 0: vet();                      // Già rifattorizzato
                break;
        case 1: matrice();                  // Già rifattorizzato
                break;
        case 2: stringhe();                 // Già rifattorizzato
                break;
        case 3: strutture();                // TODO
                break;
        case 4: liste();                    // TODO
                break;
        case 5: elezioni();                 // TODO
                break;
        case 6: elezioniByVins();           // TODO
                break;
        case 7: alberi();                  // TODO
                break;
        case 8: alberiParent();             // TODO
                break;
        case 9: alberiNari();                // TODO
                break;
        case 10: hw4_1();                // TODO
                break;
        case 11: hw4_2();                // TODO
               break;
        case 12: hw4_3();                // TODO
                break;
        case 13: esame_settembre_2016();                // TODO
                break;
        case 14: hw5();                // TODO
                break;
        case 15: esame_febbraio_2016_B();                // TODO
                break;
        case 16: esercitazioneDeTuZia();                // TODO
                break;
        case 17: esercitazioneDellaZiaDeFalcao();                // TODO
                break;
        case 18: esame_giugno2016();                // TODO
                break;
    }
    return 0;
}
