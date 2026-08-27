#include <stdio.h>

int main()
{
    int n, maximo = 0, posicao = 0, tamanho = 0;
    printf("Indique uma sequencia de numeros: ");

    do{
        scanf("%d", &n);
        if(n > 0){
            tamanho++;
            
            if(n > maximo){
                maximo = n;
                posicao = tamanho;
            }
        }
    }while(n != 0);
    printf("Maximo: %d Posicao: %d Tamanho: %d \n", maximo, posicao, tamanho);
    
    return 0;
}