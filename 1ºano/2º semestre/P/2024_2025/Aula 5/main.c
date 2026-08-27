#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

int main(){

    /*ponto2D p1 = {3, 5}, p2;

    printPonto(p1);

    initPonto(&p2);
    printPonto(p2);

    movePonto(&p1, -4, -1);
    printPonto(p1);
    printf("Quadrante deste ponto: %d\n", quadrante(p1));*/

    ret r1={{2,3},5,10}, r2;
    ponto2D p = {5,5};
    printRet(r1);
    initRet(&r2);
    printRet(r2);
    printf("Area: %d\n", areaR(r1));
    printf("Dentro: %d\n",dentroR(r1, p));
    printf("Over: %d\n", overlap(r1, r2));

    return 0;
}
