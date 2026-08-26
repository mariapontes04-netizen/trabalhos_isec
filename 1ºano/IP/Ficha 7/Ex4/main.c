#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // Para a funcao tolower
#define MAX_SIZE 256
#define MAX_WORD_SIZE 64

void to_lower_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char frase_original[MAX_SIZE];
    char frase_copia[MAX_SIZE];
    char primeira_palavra[MAX_WORD_SIZE] = "";
    const char delimitadores[] = " ";

    printf("Introduza uma frase:\n");

    if (fgets(frase_original, MAX_SIZE, stdin) == NULL) {
        printf("Erro ao ler a frase.\n");
        return 1;
    }

    size_t len = strlen(frase_original);
    if (len > 0 && frase_original[len - 1] == '\n') {
        frase_original[len - 1] = '\0';
    }
    strcpy(frase_copia, frase_original);
    char *token = strtok(frase_copia, delimitadores);

    if (token == NULL) {
        printf("A frase esta vazia ou contem apenas espaços.\n");
        return 0;
    }

    strncpy(primeira_palavra, token, MAX_WORD_SIZE - 1);
    primeira_palavra[MAX_WORD_SIZE - 1] = '\0';
    to_lower_case(primeira_palavra);
    strcpy(frase_copia, frase_original);
    token = strtok(frase_copia, delimitadores);

    int contador = 0;

    while (token != NULL) {
        to_lower_case(token);
        if (strcmp(token, primeira_palavra) == 0) {
            contador++;
        }
        token = strtok(NULL, delimitadores);
    }
    printf("A palavra %s repete-se %d vez%s.\n",
           primeira_palavra,
           contador,
           (contador == 1) ? "" : "es");

    return 0;
}