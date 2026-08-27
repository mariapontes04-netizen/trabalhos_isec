#include <stdio.h>

void main(void)
{
    int x;
    x = 3 + 4 * 5 - 6;
    printf("%d\n",x);
    x = 3 * 4 % 5 - 6;
    printf("%d\n",x);
    x = (7 + 6) % 5 / 2;
    printf("%d\n",x);
}