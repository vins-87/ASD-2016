#ifndef ARRAY_H
#define ARRAY_H
#define M 10

/* Definizione del tipo vettore, puntatore a un intero. */
typedef int* vettore;

#endif // ARRAY_H

/*!
@param v        Il vettore da stampare
@param lung     La lunghezza del vettore da stampare
*/
void stampaArray(vettore v, int lung);

/*!
@param v        Il vettore da analizzare
@param dim      La lunghezza del vettore da analizzare
@return         1 se l'array contiene una sequenza perfetta
*/
int sequenzaPerfetta(int v[],int dim);

/*!
Cerca un elemento in un array
@param v        Il vettore da analizzare
@param dim      La lunghezza del vettore da analizzare
@param n        L'elemento da cercare nell'array
*/
int trovaElemArray(int v[], int dim, int n);

/*!
Calcola il massimo dell'array
@param v        Il vettore da analizzare
@param D        La lunghezza del vettore da analizzare
@return         Il max dell'array
*/
int maxElemArray(int *v, int D);

/*!
Calcola e stampa una stringa in base al numero di elementi pari o dispari contenuti nell'array
@param a        Il vettore da analizzare
@param D        La lunghezza del vettore da analizzare
*/
void pariDispari(int *a, int D);

/*!
Ordina l'array
@param a        Il vettore da ordinare
*/
void sort(int *a);

/*!
Calcola e stampa la potenza di un numero
@param num      Numero
@param pot      Esponente
*/
void potenza(int num, int pot);

/*!
Calcola e stampa la potenza di un numero
@param num      Numero
@param pot      Esponente
*/
int potenzaRicorsiva(int num, int pot);

/*!
Crea il puntatore a un array vuoto
*/
vettore creaArray();

/*!
E' la funzione chiamata dal main
*/
void vet();
