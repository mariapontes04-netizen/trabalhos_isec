
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


pno removeNo(pno lista, int lim){
    pno atual = lista, anterior = NULL;

    // Primeira parte: remover nós com id maior que lim
    while (atual != NULL) {
        if (strlen(atual->id) > lim) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                lista = atual->prox;
                free(atual);
                atual = lista;
            } else {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    return lista;
}

pno moveNo(pno lista){
    pno atual = lista, anterior = NULL;

    // Segunda parte: mover o nó com maior v para o início
    pno maxNo = lista, maxAnterior = NULL;
    atual = lista;
    anterior = NULL;

    while (atual != NULL) {
        if (atual->v > maxNo->v) {
            maxNo = atual;
            maxAnterior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Se o maior nó já for o primeiro, nada a fazer
    if (maxNo != lista) {
        // Retirar maxNo da lista
        if (maxAnterior != NULL)
            maxAnterior->prox = maxNo->prox;

        // Colocar maxNo no início
        maxNo->prox = lista;
        lista = maxNo;
    }
    return lista;
}

pno desafio3(pno lista, int lim) {

    lista= removeNo(lista, lim);

    int count = 0;
    pno atual = lista;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    // Se menos de 3 nós, não faz mais nada
    if (count < 3)
        return lista;

    lista= moveNo(lista);

    // Primeira parte: remover nós com id maior que lim
    /*while (atual != NULL) {
        if (strlen(atual->id) > lim) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                lista = atual->prox;
                free(atual);
                atual = lista;
            } else {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    // Contar quantos elementos sobraram
    int count = 0;
    atual = lista;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    // Se menos de 3 nós, não faz mais nada
    if (count < 3)
        return lista;

    // Segunda parte: mover o nó com maior v para o início
    pno maxNo = lista, maxAnterior = NULL;
    atual = lista;
    anterior = NULL;

    while (atual != NULL) {
        if (atual->v > maxNo->v) {
            maxNo = atual;
            maxAnterior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Se o maior nó já for o primeiro, nada a fazer
    if (maxNo != lista) {
        // Retirar maxNo da lista
        if (maxAnterior != NULL)
            maxAnterior->prox = maxNo->prox;

        // Colocar maxNo no início
        maxNo->prox = lista;
        lista = maxNo;
    }

    return lista;*/
}