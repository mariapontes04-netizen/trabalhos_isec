#include<stdio.h>

void main (void)
{
    int d, m, a;
    printf("Indique a data (dd/mm/aa) : ");
    scanf("%d/%d/%d", &d, &m, &a);

    if(d == 28 && m == 2)
    {
        d = 1;
        m++;
    }
    else
    {
        if(d == 30 && (m==4 || m==6 || m==9 || m==11))
        {
            d = 1;
            m++;
        }
        else
        {
            if(d == 31)
            {
                if(m == 12)
                {
                    d = 1;
                    m = 1;
                    a++;
                }
                else
                {
                    d = 1;
                    m++;
                }
            }
            else
            {
                d++;
            }
        }
    }
    printf("%d/%d/%d", d, m, a);
}