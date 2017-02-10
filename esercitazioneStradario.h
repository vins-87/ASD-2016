#ifndef ESERCITAZIONESTRADARIO_H
#define ESERCITAZIONESTRADARIO_H

#endif // ESERCITAZIONESTRADARIO_H

typedef struct via{
    char* nome;
    struct via* puntodipartenza;
    struct via* sx;
    struct via* dx;
}strada;

typedef strada* stradario;
