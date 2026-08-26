#include <stdio.h>

int main() {
    int num, limitInf, limitSup;

    printf("Digite o numero: ");
    scanf("%d", &num);
    printf("Digite o limite inferior: ");
    scanf("%d", &limitInf);
    printf("Digite o limite superior: ");
    scanf("%d", &limitSup);

    if (num >= limitInf && num <= limitSup) {
        printf("O numero %d esta dentro dos limites [%d, %d].\n", num, limitInf, limitSup);
        return 1;
    } 
    else {
        printf("O numero %d esta fora dos limites [%d, %d].\n", num, limitInf, limitSup);
        return 0;
    }

    return 0;
}