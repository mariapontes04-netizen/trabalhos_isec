#include <stdio.h>

void main(void)
{
    int x = 2, y, z;
    x *= 3 + 2;
    printf("%d\n", x);
    x *= y = 4;
    printf("%d\t%d\n", x, y);
    z = (x == y);
    printf("%d\t%d\t%d\n", x, y, z);
}