// Programação 2024-25
// Aula 4 - Strings Constantes

#include <stdio.h>
#include <string.h>

// Exercicio 8
int indice_mes(char *mes, char *meses[], int m)
{
    for(int i = 0; i < m; i++)
    {
        if(stricmp(mes, meses[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}
void traduz(char *mes)
{
    char *pt[12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *eng[12] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};

    int p = indice_mes(mes, pt, 12);
    if(p > -1)
    {
        fprintf(stdout, "\nMes em EN --> %s\n", eng[p]);
    }
    else
    {
        fprintf(stdout, "\nMes invalido\n");
    }
}


// 10 a)
void escreve_sin(char *sin[][2], int nLin){
    for(int i = 0; i < nLin; i++){
        printf("%s <=> %s\n", sin[i][0], sin[i][1]);
    }
    printf("\n");
}

// 10 b)
char *pesquisa_sinonimo(char *sin[][2], int nLin, char *p){
    for(int i = 0; i < nLin; i++){
        if(stricmp(sin[i][0], p) == 0){
            return sin[i][1];
        }
        else if(stricmp(sin[i][1], p) == 0){
            return sin[i][0];
        }
    }
    return NULL;
}

// 10 c)
char *encontra_menor_palavra(char *v[], int n){
    if(n <= 0)
    {
        return NULL;
    }
    int menor = 0;
    for(int i = 1; i < n; i++)
    {
        if(strcmp(v[i], v[menor]) < 0)
        {
            menor = i;
        }
    }
    return v[menor];
}
char* alfaMin(char *sin[][2], int nLin)
{
    return encontra_menor_palavra(&sin[0][0], nLin*2);
}

// 10 d)
void contaVogais(char *sin[][2], int nLin){

}

int main(){
    char palavra[50], *p, *q;

    char *s[5][2] = {{"estranho", "bizarro"},
                     {"desconfiar", "suspeitar"},
                     {"vermelho", "encarnado"},
                     {"duvidar", "desconfiar"},
                     {"carro", "automovel"}};

    char st[20];

    // Chamada do exercicio 8
    printf("Mes: "); scanf("%s", st);
    traduz(st);

    // Chamadas das funcoes do exercicio 10 a partir daqui.
    escreve_sin(s, 5);

    printf("Palavra a pesquisar: ");
    scanf(" %s", palavra);

    p = pesquisa_sinonimo(s, 5, palavra);

    if(p == NULL)
        printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
    else
        printf("A palavra %s e' sinonimo de %s\n", p, palavra);

    q = alfaMin(s, 5);

    if(q == NULL)
        printf("Nao existem palavras na tabela\n");
    else
        printf("A palavra alfabeticamente mais pequena e %s\n", q);

    contaVogais(s, 5);

    return 0;
}