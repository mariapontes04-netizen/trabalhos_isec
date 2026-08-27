#include <stdio.h>
#include <string.h>
#define MAX_SIZE 256

int main() {
    char frase[MAX_SIZE];
    printf("Introduza uma frase:\n");
    if (fgets(frase, MAX_SIZE, stdin) == NULL) {
        printf("Erro ao ler a frase.\n");
        return 1;
    }
    size_t len = strlen(frase);
    if (len > 0 && frase[len - 1] == '\n') {
        frase[len - 1] = '\0';
    }
    const char delimitadores[] = " ";
    char *palavra;
    palavra = strtok(frase, delimitadores);
    while (palavra != NULL) {
        printf("%s\n", palavra);
        palavra = strtok(NULL, delimitadores);
    }
    return 0;
}