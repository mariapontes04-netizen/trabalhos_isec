#include <stdio.h>
#define TAM 100

int somaMaiores(int array[], int tamanho) {
    if (tamanho <= 0) return 0;
    
    int maior = array[0];
    int soma = 0;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (array[i] == maior) {
            soma += array[i];
        }
    }
    return soma;
}

int main() {
    int array[TAM];
    int tamanho;

    printf("Digite o tamanho do array (maximo %d): ", TAM);
    scanf("%d", &tamanho);

    if (tamanho > TAM || tamanho <= 0) {
        printf("Tamanho invalido! Certifique-se de que esta entre 1 e %d.\n", TAM);
        return 1;
    }

    // Preencher o array com valores fornecidos pelo utilizador
    printf("Digite %d valores inteiros para preencher o array:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
    int resultado = somaMaiores(array, tamanho);

    printf("A soma de todas as ocorrencias do maior numero e: %d\n", resultado);

    return 0;
}