#include <stdio.h>

int main()
{
    int a, b, c, maximo;
    
    printf("Indique valores de A, B, C: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if(a >= b){
        if(a >= c){
            maximo = a;
        }
        else{
            maximo = c;
        }
    }
    else{
        if(b >= c){
            maximo = b;
        }
        else{
            maximo = c;
        }
    }
    
    printf("O maior numero e %d",maximo);
    return 0;
}