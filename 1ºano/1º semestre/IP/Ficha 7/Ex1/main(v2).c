#include <stdio.h>
#include <string.h>
#define TAM 30

int main()
{
    char txt[TAM];
    int i, j;

    printf("Introduza uma frase: ");
    scanf("%[^\n]", txt);

    for(j = 0; txt[j] != '\0'; j++);
    for(i = strlen(txt)-1; i >= 0; i--)
    {
        printf("%c", txt[i]);
    }
    return 0;
}