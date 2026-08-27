#include<stdio.h>

void main (void)
{
    int n, soma_d, digito;

    printf("Introduza um numero inteiro: ");
    scanf("%d", &n);

    soma_d = 0;

    for(soma_d = 0; n > 0; n = n/10)
    {
        digito = n % 10;
        printf("\ndigito=%d", digito);
        soma_d += digito;
    }
    printf("\n \nsoma = %d\n", soma_d);
}