#include <stdio.h>

void desenhaTrianguloInvertido(int linhas)
{
    for (int i = linhas; i >= 1; i--)
    {
        for (int j = 0; j < linhas - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main()
{
    int linhas;

    printf("Digite o numero de linhas (entre 2 e 9): ");
    scanf("%d", &linhas);

    if (linhas > 1 && linhas <= 9)
    {
        desenhaTrianguloInvertido(linhas);
    } 
    else
    {
        printf("Numero invalido de linhas. Deve estar entre 2 e 9.\n");
    }

    return 0;
}