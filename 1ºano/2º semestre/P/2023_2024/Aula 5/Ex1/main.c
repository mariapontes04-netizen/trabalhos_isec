#include <stdio.h>
#include "ponto.h"

int main(){

    ponto2D p1 = {3, 5}, p2;

    printPonto(p1);

    initPonto(&p2);
    printPonto(p2);

    movePonto(&p1, -4, -1);
    printPonto(p1);
    printf("Quadrante deste ponto: %d\n", quadrante(p1));

    return 0;
}
