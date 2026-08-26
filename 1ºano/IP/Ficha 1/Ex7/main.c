#include <stdio.h>

int main()
{
    //declaração das variáveis e das constantes
    const float PrecoLitro = 1.3;
    int kmInicial, kmFinal, LitroConsumido;
    float ValorRecebido, Lucro, ConsumoMedio;
    
    //leitura de dados
    printf("Km iniciais: ");
    scanf("%li", &kmInicial);
    
    printf("Km finais: ");
    scanf("%li", &kmFinal);
    
    printf("Litros consumidos: ");
    scanf("%li", &LitroConsumido);
    
    printf("Total faturado: ");
    scanf("%f", &ValorRecebido);
    
    ConsumoMedio = (kmFinal - kmInicial) / LitroConsumido;
    Lucro = ValorRecebido - LitroConsumido * PrecoLitro;
    
    printf("Consumo médio: %.2f km/h\n", ConsumoMedio);
    printf("Lucro: %.2f EUR\n", ConsumoMedio);

    return 0;
}