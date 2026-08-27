#include <stdio.h>

int main(void)
{
    int n_p = 0, n_i = 0, n;

    do
    {
        printf("Indique um numero: ");
        scanf("%d", &n);
    }
    while(n < 0);

    while(n > 0)
    {
         if(n % 2 == 0)
            {
                n_p = n_p + 1;
            }
            else
            {
                n_i = n_i + 1;
            }
       do
    {
        printf("Indique um numero: ");
        scanf("%d", &n);
    }
    while(n < 0);
    }
    printf(" ", n_p, n_i);
}