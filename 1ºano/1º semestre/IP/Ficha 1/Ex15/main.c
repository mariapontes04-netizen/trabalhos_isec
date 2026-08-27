#include <stdio.h>

int main(void)
{
    int nl, l, A = 0, P = 0;

    do
    {
        printf("Indique o numero de lados: ");
        scanf("%d", &nl);
        printf("Indique o tamanho do lado: ");
        scanf("%d", &l);
    }
    while (nl < 3 || nl > 5);

    if (nl == 5)
    {
        printf("Pentagono\n");
    }
    else
    {
        if (nl == 4)
        {
            A = l * l;
            printf("Quadrado: %d\n", A);
        }
        else
        {
            P = 3 * l; // Perimeter of a triangle with equal sides
            printf("Triangulo: %d\n", P);
        }
    }
    return 0;
}