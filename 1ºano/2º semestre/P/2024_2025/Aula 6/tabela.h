#ifndef P2324_AULA5_TABELA_H
#define P2324_AULA5_TABELA_H

#include "retangulo.h"

void printV(ret a[], int total);

int addRet(ret a[], int *total);

void duplicaAltLarg(ret a[], int total);

int quadrante1(ret a[], int total);

void eliminaMenor(ret a[], int *total);

static int procurar_mais_pequeno(struct retangulo rt[], int n);

static int eliminar_elemento(struct retangulo rt[], int n, int index);

void eliminaVarios(struct retangulo tr[], int *n, int area_m);


#endif //P2324_AULA5_TABELA_H
