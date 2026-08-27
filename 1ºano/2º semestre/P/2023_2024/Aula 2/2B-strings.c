// Programação 2023/24
// Aula Prática 2B - Strings

#include <stdio.h>
#include <string.h>

// Recebe string
// Mostra na consola a string escrita por ordem inversa
// A função não recebe o número de caracteres da strings, pelo que essa é a sua primeira tarefa
void printInv(char s[])
{
    int i;
    for(i=0; s[i]!='\0'; i++);
        i--;
    // Possivel alternativa ao código que surge nas linhas anteriores: i = strlen(s)-1;
    while(i>=0)
    {
        putchar(s[i--]);
    }
    return;
}

// Recebe string
// Mostra na consola as várias palavras da string, uma em cada linha
void printPal(char s[])
{
    int i=0;
    while (s[i])
    {
        if(s[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            putchar(s[i]);
        }
        i++;
    }
    return;
}

void analisar_frases(char st1[], char st2[], char st3[]){
    if(strcmp(st1,st2)==0){
        strcpy(st3, "Conteudo Igual");
    }
    else if(strlen(st1)== strlen(st2)){
        strcpy(st3,"Tamanho igual");
    }
    else if(strcmp(st1,st2)<0){
        strcpy(st3,st1);
        strcat(st3,st2);
    }
    else{
        strcpy(st3,st2);
        strcat(st3,st1);
    }
    return;
}

int main()
{
    char st1[15] = "Hoje e Domingo";
    char st2[15] = "Hoje e Domingo";
    char st3[30] = "";
    printInv(st1);
    printf("\n");
    printPal(st1);
    analisar_frases(st1,st2,st3);
    return 0;
}