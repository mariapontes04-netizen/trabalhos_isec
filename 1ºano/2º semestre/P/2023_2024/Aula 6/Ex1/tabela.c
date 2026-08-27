#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("Existem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i);
        printRet(a[i]);
    }
}

int addRet(ret tr[], int *total){
    if(*total >= TMP_MAX){
        return 0;
    }
    initRet(&tr[*total]);
    (*total)++;
    return 1;
}

int duplicaAltLarg(ret tr[], int total){
    int p=0;
    for(int i=0;i<total;i++){
        if(areaR(tr[i]) %2 == 0){
            tr[i].alt *= 2;
            tr[i].larg *= 2;
            p++;
        }
    }
    return p;
}

int quadrante1(ret tr[], int total){
    int p = 0;
    for(int i=0;i<total;i++){
        if(quadrante(tr[i].canto)==1){
            p++;
        }
    }
    return p;
}

/*void eliminaMenor(ret tr[], int *total){
    int p = procurar_mais_pequeno(tr,*total);
    if(p==-1){
        printf("\n Não existem retangulos\n");
    }
    else{
        printf("\n Retangulo com a menor area");
        *total= eliminaVarios(rt,*total,p);
    }
    return;
}
static int procurar_mais_pequeno(ret tr[], int *total){
    if(total==0){
        return -1;
    }
    int index=0;
    for(int i=0;i)
}*/

void eliminaVarios(ret rt[], int *total, int index){
    rt[index]=rt[*total-1];
    (*total)--;
}
