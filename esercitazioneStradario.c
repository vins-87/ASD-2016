#include <stdio.h>
#include <stdlib.h>
#include "esercitazioneStradario.h"

int esiste_percorso_aux(stradario st,char* strada1){
    if(st){
        if(st->nome==strada1){
            return 1;
        }
        esiste_percorso_aux(st->puntodipartenza,strada1);
    }
    return 0;
}

int esiste_percorso(stradario st, char* strada1, char* strada2){
    if(st){
        if(st->nome==strada2){
            return esiste_percorso_aux(st,strada1);
        }
        return esiste_percorso(st->sx,strada1,strada2) || esiste_percorso(st->dx,strada1,strada2);
    }
    return 0;
}

void crea_stradario(){

}
