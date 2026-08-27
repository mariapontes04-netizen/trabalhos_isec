// Programação 2023/24
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
int posMaior(int a[], int tam) {
    int i,m=0;
    for(i=1;i<tam;i++){
        if(a[i]>a[m]){
            m=i;
        }
    }
    return m;
}


// Exercicio 3
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve número de ocorrências do maior valor na tabela
int contaMaior(int a[], int tam){
    int pmax=0,cmax=1;
    for(int i=1;i<tam;i++){
        if(a[i]>a[pmax]){
            pmax=i;
            cmax=1;
        }
        else if(a[pmax]==a[i]){
            cmax++;
        }
    }
    return cmax;
}


// Exercicio 4
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve elemento mais comum
int maior_valor_mais_frequente(int v[], int n){
    int maior_mais_freq;
    int num_vezes=0;
    for(int i=0;i<n;i++){
        int conta=1;
        for(int j=i+i;j<n;j++){
            if(v[j]==v[i]){
                conta++;
            }
        }
        if(conta>num_vezes){
            num_vezes=conta;
            maior_mais_freq=v[i];
        }
        else{
            if(conta==num_vezes && v[i]>maior_mais_freq){
                maior_mais_freq=v[i];
            }
        }
    }
    return maior_mais_freq;
}

int main(){

    int tab1[8] = {3, 6, 8, 8, 10, 1, 4, 2};
    int tab2[6] = {5, 5, 5, 9, 1, 9};

    printf("Tabela 1:\n");
    mostraTab(tab1, 8);
    printf("Maior: %d\n", maior(tab1, 8));
    printf("Pos Maior: %d\n", posMaior(tab1, 8));
    printf("Conta Maior: %d\n", contaMaior(tab1, 8));
    printf("Mais Comum: %d\n\n", maior_valor_mais_frequente(tab1, 8));

    printf("Tabela 2:\n");
    mostraTab(tab2, 6);
    printf("Maior: %d\n", maior(tab2, 6));
    printf("Pos Maior: %d\n", posMaior(tab2, 6));
    printf("Conta Maior: %d\n", contaMaior(tab2, 6));
    printf("Mais Comum: %d\n\n", maior_valor_mais_frequente(tab1, 6));

    return 0;
}
