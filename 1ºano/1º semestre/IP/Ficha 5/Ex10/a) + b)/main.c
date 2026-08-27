#include <stdio.h>

int calculaCubo(int num)
{
    return num * num * num;
}

int obtemNum()
{
    int num;
    do
    {
        printf("Digite um numero inteiro entre 100 e 999: ");
        scanf("%d", &num);

        if (num < 100 || num > 999)
        {
            printf("Numero invalido! Por favor, insira um valor entre 100 e 999.\n");
        }
    }
    while (num < 100 || num > 999);

    return num;
}

int main()
{
    int num = obtemNum();
    int cubo = calculaCubo(num);
    printf("O cubo de %d e %d.\n", num, cubo);

    return 0;
}