#include <stdio.h>
#include <stdlib.h>

int ehCapicua(int numero)
{
    int tamanho = 0;
    int original = numero;

    while (numero > 0)
    {
        numero /= 10;
        tamanho++;
    }

    int *digitos = (int *)malloc(tamanho * sizeof(int));
    if (digitos == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    numero = original;

    for (int i = 0; i < tamanho; i++)
    {
        digitos[i] = numero % 10;
        numero /= 10;
    }

    for (int i = 0, j = tamanho - 1; i < j; i++, j--)
    {
        if (digitos[i] != digitos[j])
        {
            free(digitos);
            return 0;
        }
    }
    free(digitos);
    return 1;
}

int main()
{
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (ehCapicua(numero))
    {
        printf("%d e um numero capicua.\n", numero);
    }
    else
    {
        printf("%d nao e um numero capicua.\n", numero);
    }

    return 0;
}