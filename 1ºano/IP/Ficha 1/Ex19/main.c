#include <stdio.h>

int main()
{
    float taxa, montante_inicial;
    char data;

    printf("Informacao necessaria: ");
    printf("\nData Atual (dd/mm/yyyy): ");
    scanf("%s", &data);
    printf("\nMontante inicial: ");
    scanf("%f", &montante_inicial);
    printf("\nTaxa: ");
    scanf("%f", &taxa);

    montante_inicial = montante_inicial * taxa;

    printf("\nCalculo do montante: ");
    printf("\nNo dia ",data," vai ter no banco € %.2f",montante_inicial);
    return 0;
}