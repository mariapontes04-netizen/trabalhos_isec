// Programação 2024/25
// Aula Prática 1

#include <stdio.h>

// Recebe: Tabela de inteiros a com tamanho tam
// Mostra na consola os valores armazenados na tabela
void mostraTab(int a[], int tam){
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%d\t", a[i]);
    }
    putchar('\n');
}

// Exercicio 1
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve maior valor armazenado na tabela
int maior(int a[], int tam){
    int i, m = a[0];
    for(i = 1; i < tam; i++)
        if(a[i] > m)
        {
            m = i;
        }
    return a[m];
}

// Exercicio 2
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve posição do maior valor armazenado na tabela
int posMaior(int a[], int tam){
    int i, m = 0;
    for(i = 1; i < tam; i++){
        if(a[i] > a[m]){
            m = i;
        }
    }
    return m;
}

// Exercicio 3
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve número de ocorrências do maior valor na tabela
int contaMaior(int a[], int tam){
    int i, pmax = 0, cmax = 1;
    for(i = 1; i < tam; i++){
        if(a[i] > a[pmax]){
            pmax = i;
            cmax = 1;
        }
        else if(a[pmax] == a[i]){
            cmax++;
        }
    }
    return cmax;
}


// Exercicio 4
// Recebe: Tabela de inteiros a com tamanho tam
// Devolve o elemento mais comum da tabela
int maisComum(int v[], int n){
    int i, maior_mais_freq, num_vezes = 0;

    for(i = 0; i < n; i++){
        int conta = 1;

        for(int j = i + 1; j < n; j++){
            if(v[j] == v[i])
            {
                conta++;
            }
        }
        if(conta > num_vezes)
        {
            num_vezes = conta;
            maior_mais_freq = i;
        }
        else
        {
            if(conta == num_vezes && v[i] > v[maior_mais_freq])
            {
                maior_mais_freq = i;
            }
        }
    }
    return maior_mais_freq;
}

//Exercicio 5
void inverter(int a[], int n){
    for(int i = 0; i < n/2; i++){
        int tmp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = tmp;
    }
}


//Exercicio 6
void direita(int tab[], int dim){
    int ultimo=tab[dim-1];
    for(int i=dim-1;i>0;i--){
        tab[i]=tab[i-1];
    }
    tab[0]=ultimo;
    return;
}

int main(){

    int tab1[8] = {3, 6, 8, 8, 10, 1, 4, 2};
    int tab2[6] = {5, 5, 5, 9, 1, 9};

    printf("Tabela 1:\n");
    mostraTab(tab1, 8);
    printf("Maior: %d\n", maior(tab1, 8));
    printf("Pos Maior: %d\n", posMaior(tab1, 8));
    printf("Conta Maior: %d\n", contaMaior(tab1, 8));
    printf("Mais comum: %d\n\n", tab1[maisComum(tab1, 8)]);
    inverter(tab1, 8);
    direita(tab1, 8);

    printf("Tabela 2:\n");
    mostraTab(tab2, 6);
    printf("Maior: %d\n", maior(tab2, 6));
    printf("Pos Maior: %d\n", posMaior(tab2, 6));
    printf("Conta Maior: %d\n", contaMaior(tab2, 6));
    printf("Mais comum: %d\n\n", tab2[maisComum(tab2, 6)]);
    inverter(tab2, 8);
    direita(tab2, 8);

    return 0;
}
