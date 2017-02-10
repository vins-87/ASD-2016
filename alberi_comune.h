#ifndef ESERCITAZIONEDETUZIA_H_INCLUDED
#define ESERCITAZIONEDETUZIA_H_INCLUDED



#endif // ESERCITAZIONEDETUZIA_H_INCLUDED

typedef struct elem_de_tu_zia{
    int info;
    struct elem_de_tu_zia* sx;
    struct elem_de_tu_zia* dx;
} nodo_albero;

typedef nodo_albero* albero;

typedef struct nodN{
    int info;
    struct nodN* figlio;
    struct nodN* fratello;
}nodo_alberoN;

typedef nodo_alberoN* alberoN;

int magg(int n, int m);
int esiste_foglia(albero T, int v);
int esiste_nodo_al_livello(albero T,int v, int l);
int livello_foglia(albero a1, int n);
int costruisci_aux(albero T, int l, int* A, int cont, albero root);
int *costruisci_livello_foglia(albero T, int v);
int altezza_alberi_comune(albero T);
int num_nodi_livello(albero T, int l);
int livello2array_aux(albero T, int l, int* A, int cont, albero root);
int *livello2array(albero T, int lev);
void livelli_nodo_comune_aux(albero root, albero T1, albero T2, int** A, int* B, int lev);
int** livelli_nodo_comune(albero T1, albero T2);
int livelli_figli_nodo(albero T1, alberoN T2, int x, int h);
albero creaAlberaccio();
alberoN crea_alberoN();
void esercitazioneDeTuZia();
