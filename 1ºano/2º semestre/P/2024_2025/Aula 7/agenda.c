#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

// Escreve os dados de todos os contactos na agenda
// Recebe endereço do vetor e numero de contactos armazenados
void listaC(pct p, int total){
    int i;

    printf("Existem %d contactos na agenda\n", total);
    for(i=0; i<total; i++)
        printf("%s\t%d\n", p[i].nome, p[i].num);
}

// Adiciona um novo contacto ao vetor dinamico. Os dados são indicados pelo utilizador
// Recebe endereço do vetor e endereço de variavel inteira contento o numero de contactos
// Devolve endereço de vetor depois de efetuada a atualizacao
pct addC(pct p, int *total){
    char nome[200];
    int num;
    pct aux;

    printf("Nome do novo contacto: ");
    scanf(" %[^\n]", nome);
    if (getTel(p, *total, nome) != -1) {
        printf("Erro: ja existe um contacto com o nome '%s'.\n", nome);
        return p;
    }
    printf("Numero do novo contacto: ");
    scanf(" %d", &num);

    // Completar funcao
    aux=realloc(p, sizeof(ct) * (*total+1));
    if (aux == NULL) {
        printf("Erro: sem memoria disponivel.\n");
        return p;
    }
    p=aux;
    strcpy(p[*total].nome, nome);
    p[*total].num = num;
    (*total)++;

    return p;
}

// Recebe endereço do vetor, numero de contactos armazenados e nome do contacto a pesquisar
// Devolve o numero de telemovel de um contacto
int getTel(pct p, int total, char *nome){
    for (int i = 0; i < total; i++) {
        if (strcmp(p[i].nome, nome) == 0)
        {
            return p[i].num;
        }
    }
    return -1;
}

// Atualiza numero de telemovel de um contacto
// Recebe endereço do vetor, numero de contactos armazenados, nome do contacto a atualizar e novo numero
// Devolve 1 se a atualizacao for efetuada, ou 0, caso contrario
int atualizaTel(pct p, int total, char *nome, int novoT){
    for (int i = 0; i < total; i++) {
        if (strcmp(p[i].nome, nome) == 0)
        {
            p[i].num = novoT;
            return 1;
        }
    }
    return 0;
}

// Recebe endereço do vetor e numero de contactos armazenados 
// Devolve o numero de operadores moveis diferentes que existem no array
int getOperador(pct p, int total){
    return 0;
}

// Eliminar um novo contacto do vetor dinamico
// Recebe endereço do vetor, endereço de variavel inteira contento o numero de contactos e nome do contacto a eliminar
// Devolve endereço de vetor depois de efetuada a atualizacao
pct eliminaC(pct p, int *total, char *nome){
    int i, j;
    int enc = -1;

    for (i = 0; i < *total; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            enc = i;
            break;
        }
    }
    if (enc == -1) {
        printf("Contacto nao encontrado.\n");
        return p;
    }
    for (j = enc; j < (*total) - 1; j++) {
        p[j] = p[j + 1];
    }
    (*total)--;

    if (*total > 0) {
        pct temp = (pct)realloc(p, sizeof(ct) * (*total));
        if (temp != NULL) {
            p = temp;
        }
    } else {
        free(p);
        return NULL;
    }
    printf("Contacto eliminado com sucesso!\n");
    return p;
}
