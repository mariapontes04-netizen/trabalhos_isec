#include <stdio.h>
#define TAM 100

void mostrar_linha_fgets(char *nome_fich, int nl){
    FILE *f = fopen(nome_fich,"rt");
    if(f == NULL){
        printf("Erro a abrir o ficheiro %s\n",nome_fich);
        return;
    }
    char linha[TAM];
    int n=1;
    while(fgets(linha,TAM,f) && n<nl){
        n++;
        if(n == nl){
            fputs(linha,stdout);
        }
        else{
            fputs("\n Linha inexistente\n", stdout);
        }
    }
    fclose(f);
}

int main(){
    char nome[80];
    int n;
    printf("\nNome do ficheiro -> ");
    gets(nome);

    puts("\n Mostrar Linha a Linha \n");
    mostrar_linha_fgets(nome, n);

}