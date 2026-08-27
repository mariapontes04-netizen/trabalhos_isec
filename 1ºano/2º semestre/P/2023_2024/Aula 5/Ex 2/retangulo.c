#include "retangulo.h"
#include <stdio.h>

void printRet(ret rt){
    printf("\n (%3d,%3d)",(rt.canto.x),(rt.c.y)+rt.alt);
    printf("\t\t (%3d,%3d)\n",(rt.c.x)+rt.larg,(rt.c.y)+rt.alt);
    printf("\n (%3d,%3d)",rt.c.x,rt.c.y);
    //printf("(%3d,%3d)\n\n",(rt.c.x)+rt.larg);
}

void initRet(ret* p){

}

int areaR(ret r){
    return 0;
}

int dentroR(ret r, ponto2D a){
    return 0;
}

void moveR(ret* rt, int dx, int dy){
    rt->c.x+=dx;
    rt->c.y+=dy;
}
