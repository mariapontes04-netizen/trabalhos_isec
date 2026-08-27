// Programação 2024/25
// Aula Prática 3 - Ponteiros e Endereços: Comunicação entre funções e manipulação de tabelas

#include <stdio.h>

// Exercicio 1
void f1()
{
    int a = 12, *p;
    float x = 3.5, *q;
    p = &a;
    q = &x;

    printf("Valores: a=%d\tx=%.2f\n", a, x);
    printf("Valores: a=%d\tx=%.2f\n", *p, *q);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", &a, &x);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", p, q);
}

// Exercicio 2
void f2(int x, int *p)
{
    printf("F2: Endereco/Localizacao: x=%p\tb=%p\n", &x, p);
    x++;
    (*p)++;
    printf("Valores em F2: a=%d\tb=%d\n", x, *p);
}

// Exercicio 3
void rotacao(float *p1, float *p2, float *p3)
{
    float temp= *p3;
    *p3 = *p2;
    *p2 = *p1;
    *p1 = temp;
}

// Exercicio 4
void conta(int *v, int tam, int *np, int *ni, int *maior, int *pos)
{
    *np = *ni = *pos = 0;
    for(int i = 0; i < tam; i++)
    {
        if(* (v+i) % 2 == 0)
        {
            (*np)++;
        }
        else
        {
            (*ni)++;
        }
        if(* (v+i) > * (v + *pos)){
            *pos = i;
        }
    }
    *maior = *(v + *pos);
    return;
}

// Exercicio 5
void procuraDupla(int *a, int tam, int *prim, int *seg)
{
    if(tam < 2)
    {
        printf("\n O vetor precisa ter, pelo menos, dois elementos.\n");
        return;
    }
    int pmax = 0, smax = 0;

    if(*(a + 1) > *a)
    {
        pmax = 1;
    }
    else
    {
        smax = 1;
    }
    for(int i = 2; i < tam; i++)
    {
        if(*(a + i) > *(a + pmax))
        {
            smax = pmax;
            pmax = i;
        }
        else if(*(a + i) > *(a + smax))
        {
            smax = i;
        }
    }
    *prim = *(a + pmax);
    *seg = *(a + smax);
}


int main(){
    float x = 1.2, y = 4.9, z = -2.3;
    int a = 1, b = 2;

    int tab1[10] = {12, 7, 9, 4, 1, 4, 41, 7, 21, 14};
    int tab2[5] = {-2, -7, -8, -9, -1};
    int tab3[8] = {12, 10, 11, 5, 8, 3, -4, -1};

    int pares = 0, impares = 0, maior = 0, posMaior = 0;
    int prim = 0, seg = 0;

    printf("Valores Iniciais: a=%d\tb=%d\n", a, b);
    printf("Main: Endereco/Localizacao: a=%p\tb=%p\n", &a, &b);
    f2(a, &b);
    printf("Valores Finais: a=%d\tb=%d\n", a, b);

    printf("Antes: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);
    rotacao(&x, &y, &z);
    printf("Depois: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);

    conta(tab1, 10, &pares, &impares, &maior, &posMaior);
    printf("Pares: %d\tImpares: %d\tMaior: %d\tPosicao: %d\n", pares, impares, maior, posMaior);

    procuraDupla(tab1, 10, &prim, &seg);
    printf("Maior: %d\tSegundo Maior: %d\n", prim, seg);

    return 0;
}