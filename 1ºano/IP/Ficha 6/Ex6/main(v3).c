#include <stdio.h>
#define TAM 6

int somaMaior(int [], int);
int somaMaior(int x[], int comp) {
    
    int somaOcurrencias, i, maior;
    
    somaOcurrencias = x[0];
    maior = 0;

    for (i = 1; i < comp; i++)
    {
        if (x[i] > maior)
        {
            maior = x[i];
            somaOcurrencias = x[i];
        }
        else
        {
            if (x[i] == maior)
            {
                somaOcurrencias += x[i];
            }
        }
    }
    return somaOcurrencias;
}

int main() {
    int i, vetor[TAM];
    
    for(i=0; i<TAM; i++){
        printf("Indique o seu valor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("A soma do maior numero do vetor e: %d\n", somaMaior(vetor,TAM));

    return 0;
}