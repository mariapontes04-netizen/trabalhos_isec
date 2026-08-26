#include <stdio.h>
#define TAM 6

// a) Funcao que devolve a posicao do maior elemento do array
int PosicaoMaior(int x[], int comp)
{
    int i, maiorValor = x[0], maiorPosicao = 0;
    
    for (i = 1; i < comp; i++)
    {
        if (x[i] >= maiorValor)
        {
            maiorValor = x[i];
            maiorPosicao = i;
        }
    }
    return maiorPosicao;
}

// b) Funcao que desloca todos os elementos uma posicao para a direita
void DeslocaDireita(int x[], int comp)
{
    int j, aux;
    aux = x[comp - 1];
    
    for (j = comp - 1; j > 0; j--)
    {
        x[j] = x[j - 1];
    }
    x[0] = aux;
}

void MostraVetor(int x[], int comp)
{
    int j;
    for(j = 0; j < comp; j++)
    {
        printf("%d",x[j]);
    }
    printf("\n");
}

// c) Programa principal
int main()
{
    int i, v[TAM];
    
    for(i = 0; i < TAM; i++)
    {
        printf("Indique %d valor: ", i + 1);
        scanf("%d", &v[i]);
    }
    printf("Vetor inicial: ");
    MostraVetor(v, TAM);
    while(PosicaoMaior(v,TAM) != TAM - 1)
    {
        DeslocaDireita(v, TAM);
        MostraVetor(v, TAM);
    }
    printf("\nVetor final: ");
    MostraVetor(v, TAM);
}