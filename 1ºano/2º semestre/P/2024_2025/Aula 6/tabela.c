#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("\nExistem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i+1);
        printRet(a[i]);
    }
}

int addRet(ret a[], int *total){
    if(*total >=10) return 0;
    initRet(&a[*total]);
    *total++;
    return 1;
}

void duplicaAltLarg(ret a[], int total){

}

int quadrante1(ret a[], int total){
    int p=0;
    for(int i=0; i< total;i++){
        if(quadrante(a[i].canto)){
            p++;
}
    }
    return p;
}

static int procurar_mais_pequeno(struct retangulo rt[], int n){
    if(n == 0)
    {
        return -1;
    }
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(areaR(rt[i]) < areaR(rt[index]))
        {
            index = i;
        }
    }
    return index;
}
static int eliminar_elemento(struct retangulo rt[], int n, int index){
    rt[index] = rt[n-1];
    return n-1;
}
void eliminaMenor(struct retangulo tr[], int *n){
    int p = procurar_mais_pequeno(tr, *n);
    if(p == -1)
    {
        printf("\nNao existem retangulos\n");

    }
    else{
        printf("\nRetangulo com a menor area -> id = %d area = %d\n", p, areaR(tr[p]));
        *n = eliminar_elemento(tr, *n, p);
    }
    return;
}

void eliminaVarios(struct retangulo tr[], int *n, int area_m){
    int p = *n;
    for(int i = p-1; i >= 0; i--)
    {
        if(areaR(tr[i]) < area_m)
        {
            *n = eliminar_elemento(tr, *n, i);
        }
    }
    return;
}