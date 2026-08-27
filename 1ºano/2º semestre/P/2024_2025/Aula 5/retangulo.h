#ifndef RETANGULO_H
#define RETANGULO_H
#include "ponto.h"

typedef struct retangulo rt;
struct retangulo{
    ponto2D c;
    int alt, larg;
};

// Prototipos das funções definidas no modulo retangulo.c

void printRet(rt r);

void initRet(rt* p);

int areaR(rt r);

int dentroR(rt r, ponto2D a);

int overlap(rt r1, rt r2);

#endif

