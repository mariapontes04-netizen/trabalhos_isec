#include <stdio.h>

int main(void)
{
    int a[N];
    int i, soma = 0;
    float media;

    for (i = 0; i < N; i++)
    {
        printf("Introduza um numero: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < N; i++)
    {
        soma += a[i];
    }

    media = (float)soma / N;

    printf("Soma dos elementos: %d\n", soma);
    printf("Media dos elementos: %.2f\n", media);

    for (i = 0; i < N; i++)
    {
        if (a[i] < media)
        {
            a[i] = 0;
        }
    }

    printf("Elementos do array apos a modificacao:\n");
    for (i = 0; i < N; i++)
    {
        printf("\ta[%d]=%d\n", i, a[i]);
    }

    return 0;
}