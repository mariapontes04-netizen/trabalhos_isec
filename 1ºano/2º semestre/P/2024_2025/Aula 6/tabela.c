#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("\nExistem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i);
        printRet(a[i]);
    }
}

int addRet(ret a[], int *total){
    if (*total == 10)
    {
        return 0;
    }
    initRet(&a[*total]);
    (*total)++;
    return 1;
}

void duplicaAltLarg(ret a[], int total){
    int i;
    for(i = 0; i < total; i++)
    {
        if (areaR(a[i]) % 2 == 0)
        {
            a[i].alt = a[i].alt * 2;
            a[i].larg = a[i].larg * 2;
        }
    }
}

int quadrante1(ret a[], int total){
    return 0;
}

void eliminaMenor(ret a[], int *total)
{
    if (*total <= 0) {
        return;
    }
    int i, indiceMenor = 0, areaMenor = areaR(a[0]);

    for (i = 1; i < *total; i++) {
        int areaAtual = areaR(a[i]);
        if (areaAtual < areaMenor) {
            areaMenor = areaAtual;
            indiceMenor = i;
        }
    }
    for (i = indiceMenor; i < *total - 1; i++) {
        a[i] = a[i + 1];
    }
    (*total)--;
    printf("\nRetangulo no indice %d (Area: %d) eliminado com sucesso!\n", indiceMenor, areaMenor);
}

void eliminaVarios(ret a[], int *total, int lim)
{
    int i, escrita = 0;
    for (i = 0; i < *total; i++) {
        if (areaR(a[i]) >= lim) {
            a[escrita++] = a[i];
        }
    }
    *total = escrita;
}