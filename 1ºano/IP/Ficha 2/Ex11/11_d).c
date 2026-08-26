#include <stdio.h>

void main(void)
{
    int x, y, z;
    x = y = z = -1;
    ++x || ++y || ++z;
    printf("%d %d %d\n", x, y, z);
    x = y = z = -1;
    ++x && ++y && ++z;
    printf("%d %d %d\n", x, y, z);
}