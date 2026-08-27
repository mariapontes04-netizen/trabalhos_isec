#ifndef P2324_AULA5_TABELA_H
#define P2324_AULA5_TABELA_H
#include "retangulo.h"

void printV(ret a[], int total);

int addRet(ret tr[], int *total);

int duplicaAltLarg(ret tr[], int total);

int quadrante1(ret tr[], int total);

void eliminaMenor(ret tr[], int *total);

void eliminaVarios(ret rt[], int *total, int index);

#endif //P2324_AULA5_TABELA_H
