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
    } while (num < 100 || num > 999);

    return num;
}

#include <stdio.h>

int verificacubos(int i)
{
    int cd1, cd2, cd3;
    cd1 = cubo(i / 100);
    cd2 = cubo(i / 10 % 10);
    cd3 = cubo(i % 10);
    return (i == cd1 + cd2 + cd3);
}

int main()
{
    int num = obtemNum();
    int cubo = calculaCubo(num);
    printf("O cubo de %d e %d.\n", num, cubo);
    char cont;
    int num;

    do
    {
        printf("%d \n",verificacubos(numeroutilizador()));
        printf("Deseja continuar (S/N)? ");
        scanf("%c", &cont);
    } while(cont == 's' || cont == 'S');

    return 0;
}