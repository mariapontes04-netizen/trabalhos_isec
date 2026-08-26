#include <stdio.h>

void main(void)
{
    int x, y = 1, z;
    x = 0;
    z = 1;
    x = x && y || z;
    printf("%d\n", x);
    printf("%d\n", x || !y && z);
    printf("%d\n", z >= y && y >= x);
}