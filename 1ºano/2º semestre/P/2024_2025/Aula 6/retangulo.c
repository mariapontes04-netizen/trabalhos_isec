#include "retangulo.h"
#include <stdio.h>

// Escreve as coordenadas dos 4 cantos do retangulo recebido como parâmetro
void printRet(ret r){
    printf("Canto 1: %d-%d\n", r.canto.x, r.canto.y);
    printf("Canto 2: %d-%d\n", r.canto.x + r.larg, r.canto.y);
    printf("Canto 3: %d-%d\n", r.canto.x, r.canto.y + r.alt);
    printf("Canto 4: %d-%d\n", r.canto.x + r.larg, r.canto.y + r.alt);
}

// Inicializa os dados do retangulo referenciado pelo parâmetro recebido.
// O utilizador indica os valores
void initRet(ret* p){
    if (p == NULL)
    {
        return;
    }
    printf("\nCoordenada X: ");
    scanf("%d", &p->canto.x);
    printf("Coordenada Y: ");
    scanf("%d", &p->canto.y);

    printf("Introduza a altura: ");
    scanf("%d", &p->alt);

    printf("Introduza a largura: ");
    scanf("%d", &p->larg);
}

// Devolve a area do retangulo recebido como parâmetro
int areaR(ret r){
    return r.larg * r.alt;
}

// Verifica se o ponto a se encontra dentro do retangulo r
// Devolve 1 se suceder, ou 0, caso contrario
int dentroR(ret r, ponto2D a){
    if (a.x >= r.canto.x && a.x <= (r.canto.x + r.larg) && a.y >= r.canto.y && a.y <= (r.canto.y + r.alt))
    {
        return 1;
    }
    return 0;
}

// Verifica se os 2 retangulos recebidos como parametro se intersetam.
// Devolve 1 se suceder, ou 0, caso contrario
int overlap(ret r1, ret r2){
    return 0;
}