#include<stdio.h>
#include<stdlib.h>
#include "voto.h"
#include "main.h"

void inizializzaListaCandidati(candidati *c){
    addcandidato(c,"vincenzo","ebreo","0");
    addcandidato(c,"falcao5","nonebreo","1");
}

void inizializzaListaVotanti(voti *v){
//    addvoto(v,"marco", "cappella", "0");
//    addvoto(v,"marco","sbaffoni","1");
//    addvoto(v,"andrea", "cherubini", "1");
//    addvoto(v,"giorgio","lauzi","2");
}

void elezioni(){
    printf("*********************************************\n");
    printf("**************ELEZIONI BY FALCO**************\n");
    printf("*********************************************\n");

    candidati *listaCandidati = (candidati*)malloc(sizeof(cnode));
    voti *listaVotanti = (voti*)malloc(sizeof(vnode));

    inizializzaListaCandidati(listaCandidati);
    inizializzaListaVotanti(listaVotanti);

    /* SI FERMA DA QUI IN POI  */

    printf("il numero di voti e' %d. deve essere 2\n", numbervoti(*listaVotanti));
    printf("il numero di voti validi e' %d. deve essere 1\n", checkvoti(*listaVotanti, *listaCandidati));
    printf("il numero di voti che ha ricevuto aaa e' %d. deve essere 0\n", counter(*listaVotanti, *listaCandidati, "aaa", "aaa"));
    printf("il numero di voti che ha ricevuto vincenzo e' %d. deve essere 0\n", counter(*listaVotanti, *listaCandidati, "vincenzo", "ebreo"));
    printf("il numero di voti che ha ricevuto falcao5 e' %d. deve essere 1\n", counter(*listaVotanti, *listaCandidati, "falcao5", "nonebreo"));
    printf("\n---------------------------------------------\n");
    main();
}
