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
char* creaStringa();
void stampaStringaArray(char s[]);
void stampaStringaPuntatore(char *s);
char* copiaStringa(stringa ss);
int confrontaStringhe(stringa s1,stringa s2);
char* concatenaStringhe(stringa s1, stringa s2);
Container letteraPiuRicorrente(char s[]);
void stringheVins();
void stringheVale();
void stringhe();
