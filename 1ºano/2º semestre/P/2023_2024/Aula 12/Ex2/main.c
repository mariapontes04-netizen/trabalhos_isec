#include "stdbool.h"
#include <stdio.h>
#define TAM 100

void numerar_ficheiro_linhas(char *nome_fich){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char linha[TAM];
    int n=1;
    while(fgets(linha,TAM,f)){
        fprintf(stdout,"%d %s",n++,linha);
    }
    fclose(f);
}

void numerar_ficheiro_caracteres(char *nome_fich){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char car;
    int n = 1;
    bool novalinha = true;

    while((car= fgetc(f)) != EOF){
        if(novalinha){
            fprintf(stdout,"%d",n++);
        }
        fputc(car,stdout);
        novalinha = (car == '\n');
    }
    printf("\n");
    fclose(f);
}

int main(){
    char nome[80];
    printf("\nNome do ficheiro -> ");
    gets(nome);

    puts("\n Numerar Linha a Linha \n");
    numerar_ficheiro_linhas(nome);

    puts("\n Numerar Caracter a Caracter \n");
    numerar_ficheiro_caracteres(nome);
}