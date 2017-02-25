
#ifndef STRINGHE_H
#define STRINGHE_H

typedef char* stringa;

typedef struct{     // Struttura dati
    char cOcc;      // Carattere piu ricorrente
    int numOcc;     // Numero di volte che questo carattere compare nella sequqnza
}Container;

#define N 5
#endif // STRINGHE_H
/*!
Memorizza nell'array s una stringa di N elementi letta da tastiera
*/
void leggiStringaArray(char s[]);
/*!
Calcola la length della stringa passata in arogomento, e lo restituisce
*/
int lunghezzaStringa(stringa s);
/*!
@return 1 se la stringa contiene almeno una maiuscola
*/
int contieneMaiuscole(stringa s);
/*!
@return 1 se la stringa contiene almeno una minuscola
*/
int contieneMinuscole(stringa s);
int isPalindroma(stringa s);
/*!
@return 1 se la stringa s1 è contenuta in s2
*/
int isSottostringa(stringa s1,stringa s2);
stringa creaStringa();
/*!
Stampa su schermo l'array passato in argomento
*/
void stampaStringaArray(char s[]);
void stampaStringaPuntatore(stringa s);
/*!
Equivalente di strcopy() di string.h : copia in s1 la stringa s2
@return s1: nuova stringa copiata
*/
stringa copiaStringa(stringa s1, stringa s2);
/*!
@return 1 se le stringhe sono uguali, -1 se sono di lunghezza diversa, 0 altrimenti
*/
int confrontaStringhe(stringa s1,stringa s2);
/*!
@return una stringa ottenuta dalla concatenazione delle due passate in argomento
*/
stringa concatenaStringhe(stringa s1, stringa s2);
/*!
@return il numero di volte che il carattere c compare nella stringa passata in argomento
*/
int numeroDiOccorrenze(char s[], char c);
/*!
@return Una struttura dati che contiene il numero di occorrenze e il carattere più occorrente
*/
Container letteraPiuRicorrente(char s[]);
void stringheVins();
void stringheVale();
void stringhe();
