#include <stdio.h>

void main(void)
{
    int i, j, k;
    i = j = k = 1;
    i -= j -= k;
    printf("%d\t%d\t%d\n", i, j, k);
    i = j = 1;
    printf("%d\n", i++ - ++j);
    printf("%d\t%d\n", i, j);
}