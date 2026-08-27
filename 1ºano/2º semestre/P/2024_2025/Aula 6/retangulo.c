#include "retangulo.h"
#include <stdio.h>

// Escreve as coordenadas dos 4 cantos do retangulo recebido como parâmetro
void printRet(ret r){
    printf("Ponto 00: (%d,%d)\n", r.canto.x, r.canto.y);
    printf("Ponto 01: (%d,%d)\n", r.canto.x + r.alt, r.canto.y );
    printf("Ponto 10: (%d,%d)\n", r.canto.x, r.canto.y + r.larg);
    printf("Ponto 11: (%d,%d)\n", r.canto.x + r.alt, r.canto.y + r.larg);

}

// Inicializa os dados do retangulo referenciado pelo parâmetro recebido.
// O utilizador indica os valores
void initRet(ret* p){
    int alt=0, larg=0;
    printf("canto x:");
    scanf("%d",&p->canto.x);
    printf("canto y:");
    scanf("%d",&p->canto.y);
    printf("alt:");
    scanf("%d",&alt);
    printf("larg:");
    scanf("%d",&larg);
    p->alt = alt;
    p->larg = larg;
}

// Devolve a area do retangulo recebido como parâmetro
int areaR(ret r){
    int area =0;
    area = r.alt * r.larg;
    return area;
}

// Verifica se o ponto a se encontra dentro do retangulo r
// Devolve 1 se suceder, ou 0, caso contrario
int dentroR(ret r, ponto2D a){
    return 0;
}

// Verifica se os 2 retangulos recebidos como parametro se intersetam.
// Devolve 1 se suceder, ou 0, caso contrario
int overlap(ret r1, ret r2){
    return 0;
}