// Programação 2025/26
// Aula Prática 1

#include <stdio.h>

// Recebe: Tabela de inteiros a com tamanho tam
// Mostra na consola os valores armazenados na tabela
void mostraTab(int a[], int tam){
    int i;

    for(i=0; i<tam; i++)
        printf("%d\t", a[i]);
    putchar('\n');
}

// Exercicio 1
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve maior valor armazenado na tabela
int maior(int a[], int tam){
    int i, m = a[0];
    for(i=1; i<tam; i++)
        if(a[i] > m)
            m = a[i];
    return m;
}

// Exercicio 2
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve posição do maior valor armazenado na tabela
int posMaior(int a[], int tam){
    int i, pos = 0, m = a[0];
    for(i = 1; i < tam; i++){
        if(a[i] > m){
            m = a[i];
            pos = i;
        }
    }
    return pos;
}

// Exercicio 3
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve número de ocorrências do maior valor na tabela
int contaMaior(int a[], int tam){
    int i, m = a[0], cont = 1;
    for(i = 1; i < tam; i++){
        if(a[i] > m){
            m = a[i];
            cont = 1;
        }
        else if(a[i] == m){
            cont++;
        }
    }
    return cont;
}


// Exercicio 4
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve o elemento mais comum da tabela
int maisComum(int a[], int tam){
    int i, j, freq_max = 0, res = a[0];
    for(i = 0; i < tam; i++){
        int atual = a[i];
        int cont = 0;
        for(j = 0; j < tam; j++){
            if(a[j] == atual){
                cont++;
            }
        }
        if(cont > freq_max){
            freq_max = cont;
            res = atual;
        }
        else if(cont == freq_max){
            if(atual > res){
                res = atual;
            }
        }
    }
    return res;
}


int main(){

    int tab1[8] = {3, 6, 8, 8, 10, 1, 4, 2};
    int tab2[6] = {5, 5, 5, 9, 1, 9};

    printf("Tabela 1:\n");
    mostraTab(tab1, 8);
    printf("Maior: %d\n", maior(tab1, 8));
    printf("Pos Maior: %d\n", posMaior(tab1, 8));
    printf("Conta Maior: %d\n", contaMaior(tab1, 8));
    printf("Mais comum: %d\n\n", maisComum(tab1, 8));

    printf("Tabela 2:\n");
    mostraTab(tab2, 6);
    printf("Maior: %d\n", maior(tab2, 6));
    printf("Pos Maior: %d\n", posMaior(tab2, 6));
    printf("Conta Maior: %d\n", contaMaior(tab2, 6));
    printf("Mais comum: %d\n\n", maisComum(tab2, 6));

    return 0;
}
