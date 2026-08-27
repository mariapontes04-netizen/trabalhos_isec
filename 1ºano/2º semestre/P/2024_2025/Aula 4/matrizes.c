// Programação 2024-25
// Aula 4 - Matrizes

#include <stdio.h>

// Exercicio 1
void printMat(int nLin, int nCol, int m[][nCol]){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%d\t", m[i][j]);
        putchar('\n');
    }
}

// Exercicio 2
void calcMediaCol(int nLin, int nCol, int m[][nCol], int* iMin, int* iMax)
{
    float min, max, media;
    for(int i = 0; i < nCol; i++)
    {
        media = 0.0;
        for(int j = 0; j < nLin; j++)
        {
            media += m[j][i];
        }
        media /= nLin;
        printf("\n%.2f", media);
        if(i == 0 || min > media)
        {
            min = media;
            *iMin = i;
        }
        else if(i == 0 || max < media)
        {
            max = media;
            *iMax = i;
        }
    }
}

// Exercicio 3
void trocar_int(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void tMat(int n, int mat[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            trocar_int(&mat[j][i], &mat[i][j]);
        }
    }
    return;
}

int main() {

    int mat1[3][3] = {{1,2,3},{7,8,9},{12,13,14}};
    int mat2[2][5] = {{10,2,13,4,8},{5, 9, 12, 1, 0}};

    int a=-1,b=-1;

    printf("Mat 1:\n");
    printMat(3, 3, mat1);
    printf("\nMat 2:\n");
    printMat(2, 5, mat2);

    calcMediaCol(2, 5, mat2, &a, &b);
    printf("\n\nCol. com menor media: %d\nCol. com maior media: %d\n", a, b);

    tMat(3, mat1);
    printf("\nMat 1 Transposta:\n");
    printMat(3, 3, mat1);
    return 0;
}
