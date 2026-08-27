#include <stdio.h>
#define TAM 100

void mostrar_ficheiro_linhas(char *nome_fich){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char linha[TAM];
    while(fgets(linha,TAM,f)){
        fputs(linha,stdout);
    }
    fclose(f);
}

void mostrar_ficheiro_caracteres(char *nome_fich){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char c;
    while((c = fgetc(f)) != EOF){
        putchar(c);
    }
    fclose(f);
}

void mostrar_ficheiro_fscanf(char *nome_fich){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char c;
    while(fscanf(f,"%c",&c) && !feof(f)){
        fprintf(stdout,"%c",c);
    }
    printf("\n");
    fclose(f);
}

int main(){
    char nome[80];
    printf("\nNome do ficheiro -> ");
    gets(nome);

    puts("\n Linha a Linha \n");
    mostrar_ficheiro_linhas(nome);

    puts("\n Caracter a Caracter \n");
    mostrar_ficheiro_caracteres(nome);

    puts("\n Fscanf \n");
    mostrar_ficheiro_fscanf(nome);
}
