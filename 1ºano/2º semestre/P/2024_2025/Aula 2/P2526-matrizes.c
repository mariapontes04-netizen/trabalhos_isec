// Programação 2025/26
// Aula Prática 2A - Matrizes

#include <stdio.h>

// Recebe: Matriz de inteiros mat com 3 colunas e nLin linhas
// Mostra na consola os valores armazenados na matriz
void printMat(int mat[][3], int nLin){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<3; j++)
            printf("%d\t", mat[i][j]);
        putchar('\n');
    }
}

// Recebe: Matriz de inteiros mat com 3 colunas e nLin linhas
// Preenche a matriz de acordo com as regras definidas nos exercícios 2 e 3 da ficha prática 2
int primo(int x) {return 1;}
int valido(int val, int mat[][3], int lin)
{
    int i;
    if (val<1 || val>100) return 0;
    for (i=0; i<lin; i++)
    {
        if (mat[i][0]==val) return 0;
    }
    if (primo(val)==0)
    {
        return 0;
    }
    return 1;
}
void preencheMat(int mat[][3], int nLin){
    int i, val;
    for (i=0; i<nLin; i++)
    {
        do
        {
            printf("Introduza um numero primo [1, 100] para a linha %d: ", i);
            scanf("%d", &val);
        }while (valido(val,mat,i)==0);
        mat[i][0] = val;
        mat[i][1] = val * val;
        mat[i][2] = val * val * val;
    }
}

int main(){

    int m1[4][3] = {{1,2,3},{6,7,8},{10,11,12},{20,30,40}};
    int m2[10][3] = {0};

    printMat(m1, 4);

    // Chamada da função dos exercicios 2 e 3
    preencheMat(m2, 10);
    printf("\nMatriz preenchida:\n");
    printMat(m2, 10);

    return 0;
}
