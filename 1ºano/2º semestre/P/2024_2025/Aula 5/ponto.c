#include <stdio.h>
#include "ponto.h"

// Escreve as coordenadas do ponto recebido como parâmetro
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// Inicializa as coordenadas do ponto referenciado pelo parâmetro recebido. O utilizador indica os valores
void initPonto(ponto2D* p){

}

// Recebe endereço de um ponto e valores para o deslocamento ao longo dos eixos
// Atualiza as coordenadas do ponto
void movePonto(ponto2D* p, int dx, int dy){

}

// Devolve o quadrante a que pertence o ponto recebido por parâmetro
int quadrante(ponto2D p)
{
    if(p.x == 0)
    {
        if(p.y == 0)
        {
            return 0;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        if(p.y == 0)
        {
            return -1;
        }
        else
        {
            if(p.x > 0)
            {
                if(p.y > 0)
                {
                    return 1;
                }
                else
                {
                    return 4;
                }
            }
            else
            {
                if(p.y > 0)
                {
                    return 2;
                }
                else
                {
                    return 3;
                }
            }
        }
    }
}

// Recebe 3 pontos
// Devolve 1 se estiverem na mesma reta, 0 se não estiverem
int eReta(ponto2D p1, ponto2D p2, ponto2D p3)
{
    float m = (float) (p2.y - p1.y) / (p2.x - p1.x);
    float b = (float) p1.y - m * p1.x;

    printf("\nReta -> Y = %4.2f X + %4.2f \n", m, b);

    if((p3.y) == (m * p3.x + b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}