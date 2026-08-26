#include<stdio.h>

int factorial(int num)
{
    int f = 1;
    while(num <= 1)
    {
        f *= num--;
        for(f = 1; num >= 1; num--)
        {
            f *= num--;
        }
        return f;
    }
}

void (main) void
{
    int n, p, fn, fp;
    float resultado;
    do
    {
        printf("Introduza n e p:");
        scanf("%d %d", &n, &p);
    }
    while(p>n || n<0 || p>0);
    fn = factorial(n);
    fp = factorial(p);

    printf("%d!=%d\t%d!=%d\n", n, fn, p, fp);
    printf("resultado=%f\n", (float)fn/(fp*factorial(n-p)));
}