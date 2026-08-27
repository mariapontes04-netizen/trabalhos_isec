#include <stdio.h>
#include "banco.h"
#include <string.h>

// Escreve conteudo do ficheiro binario na consola
// O nome do ficheiro érecebido como parâmetro
void printFile(char *nomeF)
{
    cliente a;
    FILE *f;

    f = fopen(nomeF, "rb");
    if(f == NULL)
    {
        printf("Erro no acceso ao ficheiro.\n");
        return;
    }
    while(fread(&a, sizeof(cliente), 1, f) == 1)
        printf("Nome: %s - Morada: %s - Conta: %d - Montante: %d\n", a.nome, a.morada, a.conta, a.montante);

    fclose(f);
}

// Escreve tamanho do ficheiro binario e numero de clientes armazenados na consola
// O nome do ficheiro érecebido como parâmetro
void printDados(char *nomeF)
{
    FILE *f;

    f = fopen(nomeF, "rb");
    if(f == NULL)
    {
        printf("Erro no acesso ao ficheiro.\n"); return;
    }
    fseek(f, 0, SEEK_END);
    printf("\nTamanho do ficheiro: %ld\n", ftell(f));
    printf("Numero de clientes: %ld\n", ftell(f) / sizeof(cliente));

    fclose(f);
}

// Corrige morada de um cliente armazenado no ficheiro
// Recebe nome do ficheiro, nome do cliente e nova morada
// Devolve 1 se a correcao for efetuada com sucesso, ou 0, caso contrario
int corrigeMorada(char *nomeF, char *nomeC, char *nMorada)
{
    FILE *f;
    cliente a;
    f = fopen(nomeF, "r+b");

    if(f == NULL)
    {
        printf("Erro");return 0;
    }
    while(fread(&a, sizeof(cliente), 1, f) == 1)
    {
        if(strcmp(a.nome, nomeC) == 0)
        {
            strcpy(a.morada, nMorada);
            fseek(f, -sizeof(cliente), SEEK_CUR);
            fwrite(&a, sizeof(cliente), 1, f);
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

// Escreve conteudo do ficheiro binario na consola. A informação deve ser listada por ordem alfabética inversa
// O nome do ficheiro érecebido como parâmetro
void printFileInv(char *nomeF)
{
    cliente a;
    FILE *f;

    f = fopen(nomeF, "rb");
    if (f == NULL)
    {
        printf("Erro no acceso ao ficheiro.\n");
        return;
    }
    fseek(f, 0, SEEK_END);
    long total_bytes = ftell(f);
    long num_clientes = total_bytes / sizeof(cliente);

    for (long i = 1; i <= num_clientes; i++)
    {
        fseek(f, -i * sizeof(cliente), SEEK_END);
        fread(&a, sizeof(cliente), 1, f);
        printf("Nome: %s - Morada: %s - Conta: %d - Montante: %d\n", a.nome, a.morada, a.conta, a.montante);
    }
    fclose(f);
}

// Transfere montante entre 2 clientes
// Recebe nome do ficheiro, identificacaos clientes envolvidos na operacaa e montante a transferir
// Devolve 1 se a transferencia for efetuada com sucesso, ou 0, caso contrario
int transfere(char *nomeF, char *or, char *dest, int valor)
{
    FILE *f;
    cliente o, d, x;
    int por = -1, pdest = -1;

    f = fopen(nomeF, "r+b");
    if (f == NULL) {
        return 0;
    }
    while (fread(&x, sizeof(cliente), 1, f) == 1)
    {
        if (strcmp(x.nome, or) == 0) {
            o = x;
            por = ftell(f) - sizeof(cliente);
        }
        else if (strcmp(x.nome, dest) == 0)
        {
            d = x;
            pdest = ftell(f) - sizeof(cliente);
        }
    }
    if (por == -1 || pdest == -1)
    {
        fclose(f);
        return -1;
    }
    if (o.montante < valor)
    {
        fclose(f);
        return -2;
    }

    // atualizar montantes origem e destino
    o.montante -= valor;
    d.montante += valor;

    // colocar na posicao origem
    fseek(f, por, SEEK_SET);
    // escrever na origem
    fwrite(&o, sizeof(cliente), 1, f);

    // colocar na posicao destino
    fseek(f, pdest, SEEK_SET);
    // escrever no destino
    fwrite(&d, sizeof(cliente), 1, f);

    fclose(f);
    return 1;
}

// Elimina um cliente do ficheiro, mantendo a ordem alfabetica
// Recebe nome do ficheiro e nome do cliente a eliminar
// Devolve 1 se a eliminação for efetuada com sucesso, ou 0, caso contrario
int eliminaC(char *nomeF, char *nome){
    FILE *f, *g;
    cliente a;

    f = fopen(nomeF, "rb");
    if(f == NULL)
    {
        return 0;
    }
    g = fopen("temp.dat", "wb");
    if(g == NULL)
    {
        fclose(f);
        return 0;
    }

    while(fread(&a, sizeof(cliente), 1, f) == 1)
    {
        if (strcmp(a.nome, nome) != 0)
        {
            fwrite(&a, sizeof(cliente), 1, g);
        }
    }
    fclose(f);
    fclose(g);
    printf("Remove: %d\n", remove(nomeF));
    printf("Rename: %d\n", rename("temp.dat", nomeF));

    return 1;
}