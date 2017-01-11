//stringhe.h
#ifndef STRINGHE_H
#define STRINGHE_H

typedef char* stringa;

typedef struct{     // Struttura dati
    char cOcc;      // Carattere piu ricorrente
    int numOcc;     // Numero di volte che questo carattere compare nella sequqnza
}Container;

#define N 5
#endif // STRINGHE_H

void leggiStringaArray(char s[]);
int lunghezzaStringa(stringa s);
int contieneMaiuscole(stringa s);
int contieneMinuscole(stringa s);
int isPalindroma(stringa s);
int isSottostringa(stringa s1,stringa s2);
stringa creaStringa();
void stampaStringaArray(char s[]);
void stampaStringaPuntatore(stringa s);
stringa copiaStringa(stringa s1, stringa s2);
int confrontaStringhe(stringa s1,stringa s2);
stringa concatenaStringhe(stringa s1, stringa s2);
int numeroDiOccorrenze(char s[], char c);
Container letteraPiuRicorrente(char s[]);
void stringheVins();
void stringheVale();
void stringhe();
