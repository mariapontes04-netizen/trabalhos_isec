#include <stdio.h>

int num_divisores(int n) {
    int i, cont = 0;
    for (i = 1; i <= n; i++){
        if (n % i == 0)
            cont++;
    }
    return cont;
}

int main() {
    int x;
    while (1) {
        printf("Introduza um numero inteiro: ");
        scanf("%d", &x);

        if (x <= 0) {
            printf("Programa terminado.\n");
            break;
        }

        if (num_divisores(x) == 2) {
            printf("O numero que introduziu e primo!\n");
        }
    }
    return 0;
}