#include <stdio.h>
#define TAM 10

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
    int x[TAM];
    int comp;

    printf("Digite o tamanho do array (maximo %d): ", TAM);
    scanf("%d", &comp);

    if (comp > TAM || comp <= 0) {
        printf("Tamanho invalido! Certifique-se de que esta entre 1 e %d.\n", TAM);
        return 1;
    }

    // Preencher o array com valores fornecidos pelo utilizador
    printf("Digite %d valores inteiros para preencher o array:\n", comp);
    for (int i = 0; i < comp; i++) {
        scanf("%d", &x[i]);
    }

    int resultado = somaMaior(x, comp);
    printf("A soma de todas as ocorrencias do maior numero e: %d\n", resultado);

    return 0;
}