#include <stdio.h>

int saoIguais(int array1[], int dimensao1, int array2[], int dimensao2)
{
    if (dimensao1 != dimensao2)
    {
        return 0;
    }

    for (int i = 0; i < dimensao1; i++)
    {
        if (array1[i] != array2[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int arrayA[] = {1, 2, 3, 4, 5};
    int dimensaoA = 5;

    int arrayB[] = {1, 2, 3, 4, 5};
    int dimensaoB = 5;

    int resultado = saoIguais(arrayA, dimensaoA, arrayB, dimensaoB);

    if (resultado)
    {
        printf("Os arrays sao iguais.\n");
    }
    else
    {
        printf("Os arrays sao diferentes.\n");
    }

    return 0;
}