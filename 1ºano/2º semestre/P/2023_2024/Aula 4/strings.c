#include <stdio.h>
#include <string.h>

// Recebe um mês escrito em português
// Escreve na consola o nome do mês traduzido para ingles
int indice_mes(char*mes, char*meses[], int m){
    for(int i=0;i<m;i++){
        if(stricmp(mes,*(meses+i))==0){
            return i;
        }
    }
    return -1;
}
void traduz(char *mes){
    char *pt[12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *eng[12] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};


    int p=indice_mes(mes,pt,12);
    if(p>-1 && p<12){
        printf("\n %s\n",*(eng+p));
    }
    else{
        printf("ERRO!!!!!");
    }
}

// Recebe a matriz de sinonimos e a indicacao do numero de linhas (sabe-se que são 2 colunas)
// Escreve na consola todos os pares de sinonimos
void escreve_sin(char *sin[][2], int tot_lin){

}

// Recebe a matriz de sinonimos, a indicacao do numero de linhas e a palavra a pesquisar
// Devolve ponteiro para sinonimo da palavra recebida por parametro (NULL se não existir sinonimo)
char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p){
    return NULL;
}

// Recebe a matriz de sinonimos e a indicacao do numero de linhas
// Devolve ponteiro para a palavra alfabeticamente mais pequena que se encontra na matriz (NULL se não existirem palavras)
char* alfaMin(char *sin[][2], int tot_lin){
    return NULL;
}

int main(){
    char palavra[50], *p, *q;

    char *s[5][2] = {{"estranho", "bizarro"},
                     {"desconfiar", "suspeitar"},
                     {"vermelho", "encarnado"},
                     {"duvidar", "desconfiar"},
                     {"carro", "automovel"}};

    // Exercicio 9

    char st[20];

    printf("Mes: "); scanf("%s", st);
    traduz(st);

    //return 0;
    // Exercicio 10 a partir daqui. Retirar a instrução da linha anterior para testar o código

    escreve_sin(s, 5);

    printf("Palavra a pesquisar: ");
    scanf(" %s", palavra);

    p = pesquisa_sinonimo(s, 5, palavra);

    if(p == NULL)
        printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
    else
        printf("A palavra %s e sinonimo de %s\n", p, palavra);

    q = alfaMin(s, 5);

    if(p == NULL)
        printf("Nao existem palavras na tabela\n");
    else
        printf("A palavra alfabeticamente mais pequena e %s\n", q);

    // Escrever e testar as restantes funções


    return 0;
}