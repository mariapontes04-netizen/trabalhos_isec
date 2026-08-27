#include <stdio.h>

void rotacao_direita(float *n1, float *n2, float *n3){
    float temp=*n3;
    *n3=*n2;
    *n2=*n1;
    *n1=temp;
}
void rotacao_esquerda(float *n1, float *n2, float *n3){
    float temp=*n1;
    *n1=*n2;
    *n2=*n3;
    *n3=temp;
}

void conta(int *v,int tam, int *np,int *ni,int *maior,int *pos){
    *np=*ni=*pos=0;

    for(int i=0;i<tam;i++){
        if(*(v+i)%2==0){
            (*np)++;
        }
        else{
            (*ni)++;
        }
        if(*(v+i)>*(v+*pos)){
            *pos=i;
        }
    }
    *maior=*(v+*pos);
}

void procuraDupla(int *a, int tam, int *prim, int *seg){
    if(tam<2){
        printf("\n O vetor precisa ter, pelo menos, dois elementos.\n");
    }
    int pmax=0,smax=0;
    if(*(a+1)>*a){
        pmax=1;
    }
    else{
        smax=1;
    }
    for(int i=2;i<tam;i++){
        if(*(a+i)>*(a+pmax)){
            smax=pmax,
            pmax=i;
        }
        else{
            if(*(a+i)>*(a+smax)){
                smax=i;
            }
        }
    }
    *prim=*(a+pmax);
    *seg=*(a+smax);
}

void f2(int x, int *p){
    printf("F2: Endereco/Localizacao: x=%p\tb=%p\n", &x, p);
    x++;
    (*p)++;
    printf("Valores em F2: a=%d\tb=%d\n", x, *p);
}

int main(){
    float x=1.2, y=4.9, z=-2.3;
    int a=1,b=2;

    int tab1[10] = {12, 7, 9, 4, 1, 4, 41, 7, 21, 14};
    int tab2[5] = {-2, -7, -8, -9, -1};
    int tab3[8] = {12, 10, 11, 5, 8, 3, -4, -1};

    int pares=0, impares=0, maior=0, posMaior=0;
    int prim=0, seg=0;

    printf("Antes: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);
    rotacao_direita(&x,&y,&z);
    rotacao_esquerda(&x,&y,&z);
    printf("Depois: X=%.1f; Y=%.1f; Z=%.1f\n", x, y, z);
    printf("Depois: X=%.1f\tY=%.1f\tZ=%.1f\n", x, y, z);

    f2(a, &b);

    conta(tab1, 10, &pares, &impares, &maior, &posMaior);
    printf("Pares: %d\tImpares: %d\t, Maior: %d\t, Posicao: %d\n", pares, impares, maior, posMaior);

    procuraDupla(tab3, 8, &prim, &seg);
    printf("Maior: %d\t, Segundo Maior: %d\n", prim, seg);
}