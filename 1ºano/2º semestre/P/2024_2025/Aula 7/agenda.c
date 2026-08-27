#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include <stdbool.h>

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
    char nome[100];
    int num;
    ct novo;
    pct aux;

    printf("Nome do novo contacto: ");
    scanf(" %[^\n]", novo.nome);
    printf("Numero do novo contacto: ");
    scanf(" %d", &(novo.num));

    for(int i =0;i<*total;i++){
        if(p[i].nome == nome)
            return p;
    }
    aux = realloc(p,sizeof(pct)*(*total+1));
    if(aux == NULL)
        printf("Erro");
    else {
        p=aux;
        p[*total]= novo;
        (*total)++;
    }
    return p;
}

// Recebe endereço do vetor, numero de contactos armazenados e nome do contacto a pesquisar
// Devolve o numero de telemovel de um contacto
int getTel(pct p, int total, char *nome){
    return -1;
}

// Atualiza numero de telemovel de um contacto
// Recebe endereço do vetor, numero de contactos armazenados, nome do contacto a atualizar e novo numero
// Devolve 1 se a atualizacao for efetuada, ou 0, caso contrario
int atualizaTel(pct p, int total, char *nome, int novoT){
    return 0;
}

// Recebe endereço do vetor e numero de contactos armazenados 
// Devolve o numero de operadores moveis diferentes que existem no array
int getOperador(pct p, int total){
    int* opp=NULL;
    int nop=0, div=10000000;
    for(int i=0;i<total;i++){
            int op =(p[i].num)/div;
            bool novo = true;
            for(int j=0;j<nop && novo;j++){
                if(opp[j]==op) novo= false;
            }
            if(novo) {
                int *aux = realloc(opp, sizeof(int)*(nop + 1));
                if(aux == NULL) printf("erro");
                else{
                    opp = aux;
                    opp[nop] = op;
                    nop++;
                }
            }

    }
    free(opp);
    return nop;
}

// Eliminar um novo contacto do vetor dinamico
// Recebe endereço do vetor, endereço de variavel inteira contento o numero de contactos e nome do contacto a eliminar
// Devolve endereço de vetor depois de efetuada a atualizacao
contacto* eliminaC(contacto *tab, int *tam){
    int indice=pre_eliminarC(tab,tam);
    if(indice>-1){
        if(*tam==1){
            free(tab);
            *tam=0;
            return NULL;
        } else{
            contacto temp=tab[indice];
            tab[indice]=tab[*tam-1];
        }
        contacto *aux= realloc(tab,sizeof (contacto)*(*tam-1));
        if(aux==NULL){
            printf("Erro");
            tab[indice]=temp;
        } else{
            tab=aux;
            (*tam)--;
            printf("\nContacto eliminado");
        }
    }
    return tab;
}
