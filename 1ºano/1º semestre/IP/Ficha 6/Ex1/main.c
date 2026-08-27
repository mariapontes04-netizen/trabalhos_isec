#include <stdio.h>

void main (void)
{
    int a[N];
    int i, soma;
    float media;

    for(i = 0; i < N; i++)
    {
        printf("Introduza um numero: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < N; i++)
    {
        printf("\ta[%d]=%d", i, a[i]);
    }

    for(i = 0, soma = 0; i < N; i++)
    {
        soma += a[i];
    }

    return 0;
}