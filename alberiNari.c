#include <stdio.h>
#include <stdlib.h>
#include "alberiNari.h"
#include "main.h"

nodoAlberoNario creaAlberoNario(){
    nodoAlberoNario a1 = (nodoAlberoNario)malloc(sizeof(nodoAlbeN));
    a1->info=3;
    return a1;
}

void alberiNari(){
    creaAlberoNario();
    printf("\n---------------------------------------------\n");
    main();
}
