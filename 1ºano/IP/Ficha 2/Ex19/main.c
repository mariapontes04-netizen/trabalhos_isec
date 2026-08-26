#include <stdio.h>

int main() {
    
    // Declaracao de variaveis
    int dia, mes, anoI, anoF;
    float montante, taxa;

    // Informacoes necessarias
    printf("Indique Dia/Mes/Ano \n");
    scanf("%i/%i/%i", &dia, &mes, &anoI);
    printf("Indique montante: ");
    scanf("%f", &montante);
    printf("Indique taxa de juro: ");
    scanf("%f", &taxa);
    
    // Calculo do montante final apos 1 ano
    anoF = anoI + 1;
    montante = montante * (1 + taxa/100);

    // Exibicao do resultado
    printf("No dia %i/%i/%i o saldo sera %.2f\n", dia, mes, anoF, montante);
    
    return 0;
}