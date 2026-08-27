#include <stdio.h>
#define TAM 100

// a) Funcao que devolve a posicao do maior elemento do array
int posicaoMaiorElemento(int array[], int tamanho) {
    int posicao = 0;
    for (int i = 1; i < tamanho; i++) {
        if (array[i] >= array[posicao]) { // Escolhe a posicao de maior indice em caso de empate
            posicao = i;
        }
    }
    return posicao;
}

// b) Funcao que desloca todos os elementos uma posicao para a direita
void deslocarDireita(int array[], int tamanho) {
    int ultimo = array[tamanho - 1]; // Armazena o ultimo elemento
    for (int i = tamanho - 1; i > 0; i--) {
        array[i] = array[i - 1]; // Desloca os elementos para a direita
    }
    array[0] = ultimo; // Move o ultimo elemento para a primeira posicao
}

// c) Programa principal
int main() {
    int array[TAM];
    int tamanho;

    printf("Digite o tamanho do array (maximo %d): ", TAM);
    scanf("%d", &tamanho);

    if (tamanho > TAM || tamanho <= 0) {
        printf("Tamanho invalido! Certifique-se de que esta entre 1 e %d.\n", TAM);
        return 1;
    }

    // Ler os elementos do array
    printf("Digite %d valores inteiros para preencher o array:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    // Fazer rotacoes ate o maior elemento estar na ultima posicao
    while (posicaoMaiorElemento(array, tamanho) != tamanho - 1) {
        deslocarDireita(array, tamanho);
    }

    // Imprimir o array apos as rotacoes
    printf("Array apos deslocamentos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}