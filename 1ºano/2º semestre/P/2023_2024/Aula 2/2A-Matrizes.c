// Programação 2023/24
// Aula Prática 2A - Matrizes

#include <stdio.h>

// Recebe: Matriz de inteiros mat com 3 colunas e nLin linhas
// Mostra na consola os valores armazenados na matriz
void printMat(int mat[][3], int nLin){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<3; j++){
            printf("%d\t", mat[i][j]);
        }
        putchar('\n');
    }
}

// Recebe: Matriz de inteiros mat com 3 colunas e nLin linhas
// Preenche a matriz de acordo com as regras definidas nos exercícios 2 e 3 da ficha prática 2
void preencheMat(int mat[][3], int nLin)
{
    for(int i=0; i<nLin; i++)
    {
        int erro=0;
        do
        {
            printf("Valor da coluna 1 da linha %d -->", i+1);
            scanf("%d", &mat[i][0]);

            erro=(mat[i][0]<1 || mat[i][0]>100);

            for(int k=0; k<i && !erro; k++)
            {
                erro=(mat[k][0] == mat[i][0]);
                if(erro)
                {
                    printf("Valor inválido\n");
                }
            }
        } while (erro);
        mat[i][1]=mat[i][0]*mat[i][0];
        mat[i][2]=mat[i][0]*mat[i][1];
    }
    return;
}

int main(){

    int m1[4][3] = {{1,2,3},{6,7,8},{10,11,12},{20,30,40}};
    int m2[10][3] = {0};

    printMat(m1, 4);

    // Chamada da função do exercicio 2
    preencheMat(m2, 10);
    printf("\nMatriz preenchida:\n");
    printMat(m2, 10);

    return 0;
}
