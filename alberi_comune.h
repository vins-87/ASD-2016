#ifndef ESERCITAZIONEDETUZIA_H_INCLUDED
#define ESERCITAZIONEDETUZIA_H_INCLUDED



#endif // ESERCITAZIONEDETUZIA_H_INCLUDED

typedef struct elem_de_tu_zia{
    int info;
    struct elem_de_tu_zia* sx;
    struct elem_de_tu_zia* dx;
} nodo_albero;

typedef nodo_albero* albero;

int esiste_foglia(albero T, int v);

int altezza(albero T);

int num_nodi_livello(albero T, int l);

void esercitazioneDeTuZia();
