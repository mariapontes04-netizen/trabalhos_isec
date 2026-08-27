#include <stdio.h>

int main()
{
    const float IVA_Alimentar = 0.06, IVA_Nao_Alimentar = 0.23;
    char tipoProd;
    float preco, precoSemIVA = 0, precoComIVA = 0;
    int nProdAlimentar = 0, nProdNaoAlimentar = 0, totalProd = 0;
    do
    {
        printf("Introduza o preco: ");
        scanf("%f", &preco);
        if(preco > 0)
        {
            do
            {
                printf("Tipo de produto (A-alimentar) ou (N-nao alimentar)");
                scanf("\n%c", &tipoProd);
            
            }
            while(tipoProd!='a' && tipoProd!='A' && tipoProd!='n' && tipoProd!='N');
        
            precoSemIVA += preco;
            
           if(tipoProd=='a' || tipoProd=='A')
           {
               nProdAlimentar ++;
               precoComIVA = precoComIVA  + (preco * (1 + IVA_Alimentar));
           }
           else
           {
               nProdNaoAlimentar ++;
               precoComIVA = precoComIVA  + (preco * (1 + IVA_Nao_Alimentar));
           }
        }
    }
    while(preco > 0);
    totalProd = nProdAlimentar + nProdNaoAlimentar;
    
    printf("Produtos alimentares: %d \n", nProdAlimentar);
    printf("Produtos nao alimentares: %d \n", nProdNaoAlimentar);
    printf("Total produtos : %d \n", totalProd);
    printf("Preco sem IVA: %.2f \n", precoSemIVA);
    printf("Preco com IVA: %.2f \n", precoComIVA);

    return 0;
}