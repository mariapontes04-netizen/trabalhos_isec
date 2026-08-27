// Programação 2024/25
// Aula Prática 3 - Ponteiros e Endereços: Comunicação entre funções e manipulação de tabelas

#include <stdio.h>

// Exercicio 3
// Recebe: Endereços/ponteiros para 3 variáveis do tipo float
// Deve efetuar a rotação de valores entre essas variáveis
void rotacao(float *p1, float *p2, float *p3){
    float temp = *p3;
    *p3 = *p2;
    *p2 = *p1;
    *p1 = temp;
}

// Exercicio 4
// Recebe: Endereço inicial de uma tabela de inteiros, tamanho da tabela e endereços de 4 variáveis inteiras
// Deve colocar nas variáveis referenciadas pelos 4 ponteiros:
// número de pares, de impares, maior valor e posição do maior valor
void conta(int *tab, int tam, int *np, int *ni, int *maior, int *pos){
    *maior = tab[0];
    *pos = 0;
    *np = 0;
    *ni = 0;
    for (int i = 1; i < tam; i++) {
        if (tab[i]%2 == 0) {
            (*np)++;
        }
        else {
            (*ni)++;
        }
        if (tab[i]>*maior) {
            *maior = tab[i];
            *pos = i;
        }
    }
}

// Exercicio 5
// Recebe: Endereço inicial e tamanho de uma tabela de inteiros e endereços de 2 variáveis inteiras
// Deve colocar nas variáveis referenciadas pelos 2 ponteiros o maior e segundo maior elementos existentes na tabela
void procuraDupla(int *tab, int tam, int *prim, int *seg){
    int temp;
    *prim = tab[0];
    *seg = tab[1];
    for (int i = 2; i < tam; i++) {
        if (tab[i]>*prim) {
            *prim = tab[i];
        }
        else if (tab[i]>*seg) {
            *seg = tab[i];
        }
    }
    if (*seg>*prim) {
        temp = *prim;
        *prim = *seg;
        *seg = temp;
    }
}

// Exercicio 6
//  Endereço inicial e tamanho de duas tabela de inteiros. As tabelas podem ter tamanhos diferentes
// As tabelas nao estao ordenadas. Em cada uma das tabelas, nao existem alementos repetidos
// Devolve o numero de elementos que as tabelas tem em comum
int comuns(int *tabA, int tamA, int *tabB, int tamB) {
    int contador = 0;
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (tabA[i]==tabB[j]) {
                contador++;
            }
        }
    }
    return contador;
}

//Exercicio 7
int comuns2(int *tabA, int tamA, int *tabB, int tamB) {
    int contador = 0;
    for (int i = 0; i < tamA; i++) {
        if (tabA[i] == tabB[i]) {
            contador++;
        }
        else if (tabA[i] < tabB[i]) {
            for (int j = 0; j < tamB; j++) {
                if (tabA[i]==tabB[j]) {
                    contador++;
                    break;
                }
            }
        }
        else if (tabA[i]>tabB[i]) {
            for (int k = i; k < tamB; k++) {
                if (tabA[i]==tabB[k]) {
                    contador++;
                    break;
                }
            }
        }
    }
    return contador;
}
// Deve testar o código das funções com as 3 tabelas exemplificadas na função main()

int main(){
    float x=1.2, y=4.9, z=-2.3;

    int tab1[10] = {12, 7, 9, 4, 1, 4, 41, 7, 21, 14};
    int tab2[5] = {-2, -7, -8, -9, -1};
    int tab3[8] = {12, -7, 11, 5, 8, 3, -4, -1};
    int tabo1[8] = {1, 4, 6, 7, 9, 10, 11, 17};
    int tabo2[8] = {2, 4, 5, 6, 9, 17, 23, 33};

    int pares=0, impares=0, maior=0, posMaior=0;
    int prim=0, seg=0, c=0;
    printf("\nINICIO ROTACAO #################");
    printf("\nAntes: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);

    // Colocar a chamada da funcao rotacao()
    rotacao(&x, &y, &z);

    printf("Depois: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);
    printf("FIM ROTACAO ####################\n");

    printf("\nINICIO CONTA ###################");
    // Colocar chamada da funcao conta()
    conta(tab1, 10, &pares, &impares, &maior, &posMaior);
    printf("\nPares: %d\tImpares: %d\t, Maior: %d\t, Posicao: %d\n", pares, impares, maior, posMaior);

    printf("FIM CONTA ######################\n");

    printf("\nINICIO PROCURADUPLA ############");
    // Colocar chamada da funcao procuraDupla()
    procuraDupla(tab2, 5, &prim, &seg);
    printf("\nMaior: %d\t, Segundo Maior: %d\n", prim, seg);

    printf("FIM PROCURADUPLA ###############\n");

    printf("\nINICIO COMUNS ##################\n");
    // Colocar chamada da funcao comuns() e guardar o valor devolvido na variavel c
    c = comuns(tabo1, 8, tabo2, 8);

    printf("\nElementos em comum: %d\n", c);
    printf("FIM COMUNS #####################\n");

    printf("\nINICIO COMUNS2 #################\n");
    // Colocar chamada da funcao comuns() e guardar o valor devolvido na variavel c
    c = comuns2(tabo1, 8, tabo2, 8);

    printf("\nElementos em comum: %d\n", c);
    printf("FIM COMUNS2 ####################\n");

    return 0;
}