#include <stdio.h>
#include <string.h>

struct paragem{
    char nome[50];
    int minutos;
};

// 2a)
int soma_media_valores(char *nome_fich, int *p_soma, float *p_med){
    int valor, n = 0;
    *p_soma = 0;
    *p_med = 0;

    FILE *f = fopen(nome_fich,"rb");
    if(f == NULL){
        printf("\nErro");
        return n;
    }
    while (fread(&valor, sizeof(int),1,f)==1){
        *p_soma += valor;
        n++;
    }
    *p_med=(float)(*p_soma)/n;
    fclose(f);

    return n;
}
//*******

//2b)
int valores_crescentes(char *nome_fich){
    FILE *f = fopen(nome_fich, "rb");
    if(f == NULL){
        printf("\nERRO");
        return 0;
    }
    int valor, prev;
    if(fread(&valor, sizeof(int),1,f) == 1){
        prev = valor;
    }
    else{
        fclose(f);
        return 0;
    }
    while (fread(&valor, sizeof(int),1,f) == 1){
        if(valor <= prev){
            fclose(f);
            return 0;
        }
        else{
            prev = valor;
        }
    }
    fclose(f);
    return 1;
}
//****


// Recebe nome do ficheiro binário e nomes de 2 paragens
// Verifica se é possivel efetuar a ligação entre as 2 paragens
// Devolve número de minutos que demora a ligar as 2 paragens ou -1, caso seja impossivel
int liga(char *nome, char *or, char *dest){

        return -1;
}

// Recebe nome do ficheiro binário e nome de paragem
// Verifica se paragem faz parte do percurso ou não. Devolve 1(Sim) ou 0 (Não)
int existeParagem(char *nomeF, char *paragem){
    return 0;
}

// Recebe nome do ficheiro binário
// Escreve na consola o nome da origem e do destino do percurso
void orDest(char *nomeF){

}

// Recebe nome do ficheiro binário
// Escreve na consola as varias paragens do percurso armazenado
void mostraPercurso(char *nomeF) {
    FILE *f;
    struct paragem p;

    f = fopen(nomeF, "rb");
    if(f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    while(fread(&p, sizeof(struct paragem), 1, f) == 1)
        printf("%s: %d\n", p.nome, p.minutos);

    fclose(f);
}

int main() {

    // 2a)
    char *nome_fich = "valoresEx2.bin";
    int soma;
    float media;
    int n = soma_media_valores(nome_fich, &soma, &media);
    printf("\n**** 2a) **** \n");
    printf("Soma dos %d valores = %d e Media = %0.2f", n, soma, media);
    // *****

    //2b
    int n2 = valores_crescentes(nome_fich);
    printf("\n**** 2b) **** \n");
    printf("\n %d",n2);
    // *****

    //mostraPercurso("cp_ex3.dat");

    //orDest("cp_ex3.dat");

    //printf("\nParagem: %d\n", existeParagem("cp_ex3.dat", "Porto"));

    //printf("\nLigacao: %d\n", liga("cp_ex3.dat", "Coimbra", "Porto"));


    return 0;
}
