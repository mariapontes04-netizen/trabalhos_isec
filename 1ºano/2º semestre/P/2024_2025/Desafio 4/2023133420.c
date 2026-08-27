
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parque.h"

// Nome: Maria Ana da Cruz Candeias Matos Pontes
// Número: 2023133420


void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso auxA;

    while(p != NULL){
        while(p->lista != NULL){
            auxA = p->lista;
            p->lista = p->lista->prox;
            free(auxA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);
    }
}

pCliente criaExemploED(cliente a[], acesso b[], int totC){
    int i, j, k=-1;

    pCliente lista = NULL, novoC;
    pAcesso novoA;

    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }
    }
    return lista;
}

void mostraTudo(pCliente p){
    pAcesso auxA;

    while(p != NULL){
        printf("\nUtilizador com id %d efetuou %d acessos\n", p->id, p->contador);
        auxA = p->lista;
        while(auxA != NULL){
            printf("Entrou as %2.2d:%2.2d. ", auxA->in.h, auxA->in.m);
            if(auxA->out.h == -1)
                printf("Ainda nao saiu do parque\n");
            else
                printf("Saiu as %2.2d:%2.2d\n", auxA->out.h, auxA->out.m);
            auxA = auxA->prox;
        }
        p = p->prox;
    }
}

pCliente desafio4(pCliente lista, hora *x, int id, int *valor) {
    pCliente atual = lista, anterior = NULL;
    pCliente primeiroCliente = lista;
    pAcesso primeiroAcesso = NULL;
    pAcesso acessoAtual, acessoAnterior;

    // 1. Determinar a hora da primeira entrada no parque
    if (lista == NULL) {
        x->h = -1;
        x->m = -1;
    } else {
        // Encontrar o primeiro acesso de todos os clientes
        pCliente tempCliente = lista;
        primeiroAcesso = NULL;

        while (tempCliente != NULL) {
            if (tempCliente->lista != NULL) {
                pAcesso tempAcesso = tempCliente->lista;
                while (tempAcesso != NULL) {
                    if (primeiroAcesso == NULL ||
                        (tempAcesso->in.h < primeiroAcesso->in.h) ||
                        (tempAcesso->in.h == primeiroAcesso->in.h && tempAcesso->in.m < primeiroAcesso->in.m)) {
                        primeiroAcesso = tempAcesso;
                    }
                    tempAcesso = tempAcesso->prox;
                }
            }
            tempCliente = tempCliente->prox;
        }

        if (primeiroAcesso != NULL) {
            *x = primeiroAcesso->in;
        } else {
            x->h = -1;
            x->m = -1;
        }
    }

    // 2. Calcular valor a pagar pelo cliente com identificador id
    *valor = 0;
    while (atual != NULL && atual->id != id) {
        atual = atual->prox;
    }

    if (atual != NULL) {
        acessoAtual = atual->lista;
        while (acessoAtual != NULL) {
            if (acessoAtual->out.h != -1 || acessoAtual->out.m != -1) {
                // Utilização completa - calcular minutos
                int minutosEntrada = acessoAtual->in.h * 60 + acessoAtual->in.m;
                int minutosSaida = acessoAtual->out.h * 60 + acessoAtual->out.m;
                *valor += (minutosSaida - minutosEntrada) * 10;
            }
            acessoAtual = acessoAtual->prox;
        }
    }

    // 3. Remover todas as utilizações completas do cliente id
    atual = lista;
    anterior = NULL;
    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        acessoAtual = atual->lista;
        acessoAnterior = NULL;

        while (acessoAtual != NULL) {
            if (acessoAtual->out.h != -1 || acessoAtual->out.m != -1) {
                // Utilização completa - remover
                pAcesso temp = acessoAtual;

                if (acessoAnterior == NULL) {
                    // Primeiro acesso da lista
                    atual->lista = acessoAtual->prox;
                } else {
                    acessoAnterior->prox = acessoAtual->prox;
                }

                acessoAtual = acessoAtual->prox;
                free(temp);
                atual->contador--;
            } else {
                acessoAnterior = acessoAtual;
                acessoAtual = acessoAtual->prox;
            }
        }

        // Se cliente ficou sem utilizações, remover da lista principal
        if (atual->contador == 0) {
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
        }
    }

    return lista;
}
