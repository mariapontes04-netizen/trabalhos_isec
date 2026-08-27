// Programação 2025/26
// Aula Prática 2B - Strings

#include <stdio.h>
#include <string.h>

// Exercicio 6
// Recebe string
// Mostra na consola a string escrita por ordem inversa
// A função não recebe o número de caracteres da strings, pelo que essa é a sua primeira tarefa
void printInv(char s[]){
    int i;

    for(i=0; s[i]!='\0'; i++)
        ;
    i--;

    // Possivel alternativa ao código que surge nas linhas anteriores: i = strlen(s)-1;

    while(i>=0)
        putchar(s[i--]);
}

// Exercicio 7
// Recebe string
// Mostra na consola as várias palavras da string, uma em cada linha
void printPal(char s[]){
    printf("\nFalta implementar a funcao\n");
}

void ex8(char st1[], char st2[], char st3[])
{
    if (strcmp(st1, st2) == 0)
    {
        strcpy(st3, "IGUAIS");
    }
    else if (strlen(st1) == strlen(st2))
    {
        strcpy(st3, "TAM IGUAL");
    }
    else if (strcmp(st1, st2) < 0)
    {
        strcpy(st3, st1);
        strcat(st3, st2);
    }
    else
    {
        strcpy(st3, st2);
        strcat(st3, st1);
    }
}

int main(){
    char st1[15] = "Ola Mundo!";

    //printInv(st1);
    ///printPal(st1);

    char s1[20]="AAA", s2[20]="BBB", s3[50];
    ex8(s1,s2,s3);
    printf("");

    //printPal(st1);

    return 0;
}