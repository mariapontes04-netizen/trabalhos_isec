#include "retangulo.h"
#include <stdio.h>

// Escreve as coordenadas dos 4 cantos do retangulo recebido como parâmetro
void printRet(rt r)
{
    printf("\n(%3d, %3d)", (r.c.x), (r.c.y) + r.alt);
    printf("\t\t(%3d, %3d)\n", (r.c.x) + r.larg, (r.c.y) + r.alt);
    printf("\n(%3d, %3d)\t\t", r.c.x, r.c.y);
    printf(" (%3d, %3d)\n\n", (r.c.x) + r.larg, r.c.y);
}

// Inicializa os dados do retangulo referenciado pelo parâmetro recebido.
// O utilizador indica os valores
void initRet(rt* p){

}

// Devolve a area do retangulo recebido como parâmetro
int areaR(rt r){
    return 0;
}

// Verifica se o ponto a se encontra dentro do retangulo r
// Devolve 1 se suceder, ou 0, caso contrario
int dentroR(rt r, ponto2D p)
{
    if((p.x > r.c.x) && (p.x < r.c.x + r.larg) && (p.y > r.c.y) && (p.y < r.c.y + r.alt))
    {
        return 1;
    }
    return 0;
}

// Verifica se os 2 retangulos recebidos como parametro se intersetam.
// Devolve 1 se suceder, ou 0, caso contrario
int overlap(rt r1, rt r2){
    return 0;
}
