// Programação 2024-25
// Aula 4 - Strings Constantes

#include <stdio.h>
#include <string.h>

// Exercicio 8
// Recebe um mês escrito em português
// Escreve na consola o nome do mês traduzido para ingles
void traduz(char *mes){
    char *pt[12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *eng[12] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};
	int i;
	for(i = 0; i < 12; i++){
		if(strcmp(mes, pt[i]) == 0){
			printf("%s - %s\n", pt[i], eng[i]);
		return;
		}
	}
	printf("Mes invalido!\n");
}

// 10 a)
// Recebe a matriz de sinonimos e a indicacao do numero de linhas (sabe-se que são 2 colunas)
// Escreve na consola todos os pares de sinonimos
void escreve_sin(char *sin[][2], int tot_lin){
	int i;
	for(i = 0; i < tot_lin; i++){
		printf("%s - %s\n", sin[i][0], sin[i][1]);
	}
}

// 10 b)
// Recebe a matriz de sinonimos, a indicacao do numero de linhas e a palavra a pesquisar
// Devolve ponteiro para sinonimo da palavra recebida por parametro (NULL se não existir sinonimo)
char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p){
	int i;
    for(i = 0; i < tot_lin; i++){
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
// Recebe a matriz de sinonimos e a indicacao do numero de linhas
// Devolve ponteiro para a palavra alfabeticamente mais pequena que se encontra na matriz (NULL se não existirem palavras)
char* alfaMin(char *sin[][2], int tot_lin){
    return NULL;
}

// 10 d)
void contaVogais(char *sin[][2], int tot_lin){
	int i, j, k, contagem[5] = {0, 0, 0, 0, 0};
	for(i = 0; i < tot_lin; i++){
		for(j = 0; j < 2; j++){
			for(k = 0; sin[i][j][k] != '\0'; k++){
				char c = tolower(sin[i][j][k]);
				switch(c){
					case 'a': contagem[0]++; break;
					case 'e': contagem[1]++; break;
					case 'i': contagem[2]++; break;
					case 'o': contagem[3]++; break;
					case 'u': contagem[4]++; break;
				}
			}
		}
	}
	printf("Ocorrencias de vogais:\n");
    printf("A: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", contagem[0], contagem[1], contagem[2], contagem[3], contagem[4]);
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
        printf("A palavra %s e sinonimo de %s\n", p, palavra);

    q = alfaMin(s, 5);

    if(q == NULL)
        printf("Nao existem palavras na tabela\n");
    else
        printf("A palavra alfabeticamente mais pequena e %s\n", q);

    contaVogais(s, 5);

    return 0;
}