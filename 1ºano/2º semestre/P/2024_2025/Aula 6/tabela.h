#ifndef TABELA_H
#define TABELA_H
#include "retangulo.h"

void printV(ret a[], int total);

int addRet(ret a[], int *total);

void duplicaAltLarg(ret a[], int total);

int quadrante1(ret a[], int total);

void eliminaMenor(ret a[], int *total);

void eliminaVarios(ret a[], int *total, int lim);

#endif //TABELA_H
