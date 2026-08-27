#include "funcao.h"
#include <string.h>
#include <stdio.h>
// Nome: Maria Ana da Cruz Candeias Matos Pontes
// Número: 2023133420

// Deve cumprir todas as regras de submissão (ver enunciado), caso contrário o trabalho poderá não ser avaliado

void mostraTab(projeto a[], int tam){
    int i;

    for(i=0; i<tam; i++){
        printf("Projeto %d:\n", i);
        printf("Inicio: %2.2d:%2.2d:%4d\tFinal: %2.2d:%2.2d:%4d\tDuracao: %d\n",
               a[i].inicio.dia, a[i].inicio.mes, a[i].inicio.ano,a[i].final.dia, a[i].final.mes, a[i].final.ano, a[i].duracao);
        printf("Palavras chave: {%s, %s, %s, %s}\n", a[i].palavras[0], a[i].palavras[1], a[i].palavras[2], a[i].palavras[3]);
        printf("Orcamento: %d\n\n", a[i].valor);
    }
}

int conta_vogais(const char *palavra) {
    int count = 0;
    while (*palavra) {
        if (strchr("aeiou", *palavra)) count++;
        palavra++;
    }
    return count;
}

// Função auxiliar para calcular a contribuição da palavra-chave para o orçamento
int calcula_contribuicao(const char *palavra) {
    int n_vogais = conta_vogais(palavra);
    char primeiro = palavra[0], ultimo = palavra[strlen(palavra) - 1];

    if (n_vogais == 2 && strchr("aeiou", primeiro) && strchr("aeiou", ultimo)) return 10;
    if (n_vogais == 1) return 5;
    if (n_vogais > 3) return 1;

    return 0;
}
// Escreva o codigo da função:
// void desafio2(projeto a[], int tam);

// Recebe:
// Tabela de estruturas do tipo projeto (a)
// Dimensão da tabela (tam)

// As estruturas armazenadas na tabela têm os campos inicio, final e pal completamente preenchidos.
// Para cada uma destas estruturas, a função deve preencher os campos duracao e valor:
// 1.Colocar no campo duracao o número de dias que decorreram entre o início e o final do projeto
// 2. Colocar no campo valor o orçamento total do projeto.


void desafio2(projeto a[], int tam){
    for (int i = 0; i < tam; i++) {
        // Calcula a duração do projeto
        if(a[i].inicio.mes == a[i].final.mes){
            a[i].duracao = a[i].final.dia - a[i].inicio.dia;
        }
        else{
            a[i].duracao = a[i].final.dia - a[i].inicio.dia + ((a[i].final.mes - a[i].inicio.mes) * 30) + 1;
        }


        // Calcula o orçamento total do projeto
        a[i].valor = 0;
        for (int j = 0; j < tam; j++) {
            a[i].valor += calcula_contribuicao(a[i].palavras[j]);
        }
    }
}