
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Nome: Maria Ana da Cruz Candeias Matos Pontes
// Número: 2023133420

void eliminaLista(pno lista){
    pno aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

pno criaLista(no tab[], int tam){
    int i;
    pno lista=NULL, novo;

    for(i=tam-1; i>=0; i--){
        novo = malloc(sizeof(no));
        if(novo == NULL){
            eliminaLista(lista);
            return NULL;
        }
        *novo = tab[i];
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

void mostraLista(pno lista){
    printf("{ ");
    while(lista != NULL){
        printf("%s-%d", lista->id, lista->v);
        lista = lista->prox;
        if(lista!=NULL)
            printf(",\t");
    }
    printf("}");
}


pno desafio3(pno lista, char *velhoID, char* novoID){

    if (lista == NULL || lista->prox == NULL || lista->prox->prox == NULL) {
        return lista; // Não faz alterações
    }

    pno prev = NULL;
    pno atual = lista;
    int posicao = 1;

    // Remover os nós em posições pares
    while (atual != NULL) {
        if (posicao % 2 == 0) { // Se a posição é par
            if (prev == NULL) { // Se o nó a ser removido é o primeiro da lista
                lista = atual->prox;
                free(atual);
                atual = lista;
            } else {
                prev->prox = atual->prox;
                free(atual);
                atual = prev->prox;
            }
        } else {
            prev = atual;
            atual = atual->prox;
        }
        posicao++;
    }

    // Verificar se existe um nó com id igual a velhoID e fazer a alteração
    atual = lista;
    prev = NULL;
    pno noVelhoID = NULL;

    while (atual != NULL) {
        if (strcmp(atual->id, velhoID) == 0) {
            noVelhoID = atual;
            if (prev == NULL) { // Se o nó é o primeiro da lista
                lista = atual->prox;
            } else {
                prev->prox = atual->prox;
            }
            break;
        }
        prev = atual;
        atual = atual->prox;
    }

    if (noVelhoID != NULL) {
        strcpy(noVelhoID->id, novoID);

        // Reposicionar o nó na lista para manter a ordem alfabética
        pno anterior = NULL;
        pno atual = lista;

        while (atual != NULL && strcmp(atual->id, novoID) < 0) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            noVelhoID->prox = lista;
            lista = noVelhoID;
        } else {
            noVelhoID->prox = anterior->prox;
            anterior->prox = noVelhoID;
        }
    }

    return lista;
}
