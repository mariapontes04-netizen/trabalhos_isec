#include <stdio.h>

int main()
{
    //declaração das variáveis e das constantes
    const float PI = 3.14;
    float raio, area, perimetro;
    
    //leitura de dados
    printf("Raio = ");
    scanf("%f", &raio);
    
    area = PI * raio * raio;
    printf("Area = %.2f\n", area);
    
    perimetro = 2 * PI * raio;
    printf("Perimetro = %.2f\n", perimetro);

    return 0;
}