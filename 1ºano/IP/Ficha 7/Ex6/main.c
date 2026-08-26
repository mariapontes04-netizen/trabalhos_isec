#include <stdio.h>
#include <string.h>

int duplicar_caractere(char *str, int dimensao, char c) {
    int len_original = strlen(str);
    int modificada = 0;

    for (int i = 0; i < len_original; i++) {
        if (str[i] == c) {
            if (len_original + modificada + 1 >= dimensao) {
                break;
            }
            int j;
            for (j = len_original + modificada; j > i + modificada; j--) {
                str[j] = str[j - 1];
            }
            str[i + modificada + 1] = c;
            modificada++;
            i++;
        }
    }
    str[len_original + modificada] = '\0';

    return (modificada > 0) ? 1 : 0;
}

int main() {
#define BUFFER_SIZE 50
    char frase1[BUFFER_SIZE] = "Como vai o amigo?";
    char frase2[BUFFER_SIZE] = "Abcde";
    char frase3[BUFFER_SIZE] = "Nada a duplicar.";
    char frase_limitada[15] = "Teste longo";

    char caractere1 = 'o';
    char caractere2 = 'c';
    char caractere3 = 'z';
    char caractere4 = 'e';

    printf("--- Exemplo 1 (Obrigatorio) ---\n");
    printf("String Original: \"%s\"\n", frase1);
    printf("Caractere a duplicar: '%c'\n", caractere1);

    int resultado1 = duplicar_caractere(frase1, BUFFER_SIZE, caractere1);

    printf("String Modificada: \"%s\"\n", frase1);
    printf("Resultado da Funcao: %d (1 = Modificada)\n\n", resultado1);

    printf("--- Exemplo 2 (Nenhuma Modificacao) ---\n");
    printf("String Original: \"%s\"\n", frase3);
    printf("Caractere a duplicar: '%c'\n", caractere3);

    int resultado3 = duplicar_caractere(frase3, BUFFER_SIZE, caractere3);

    printf("String Modificada: \"%s\"\n", frase3);
    printf("Resultado da Funcao: %d (0 = Nao modificada)\n\n", resultado3);

    printf("--- Exemplo 3 (Teste de Limite/Overflow - Buffer 15) ---\n");
    printf("String Original: \"%s\" (Dimensao Maxima: 15)\n", frase_limitada);
    printf("Caractere a duplicar: '%c'\n", caractere4);

    int resultado4 = duplicar_caractere(frase_limitada, 15, caractere4);

    printf("String Modificada: \"%s\"\n", frase_limitada);
    printf("Resultado da Funcao: %d (1 = Modificada, mas parou no limite)\n", resultado4);

    return 0;
}