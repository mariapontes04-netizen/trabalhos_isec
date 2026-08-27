#include <stdio.h>
#include "retangulo.h"

void printRet(ret r){
    printf("\ncanto 1: %d\t%d\n",r.canto.x,r.canto.y);
    printf("canto 2: %d\t%d\n",r.canto.x,r.canto.y+r.alt);
    printf("canto 3: %d\t%d\n",r.canto.x+r.larg,r.canto.y+r.alt);
    printf("canto 4: %d\t%d\n",r.canto.x+r.larg,r.canto.y);
}

void initRet(ret* p){
    printf("coordenadas do ponto: ");
    scanf("%d %d",&p->canto.x, &p->canto.y);
    printf(" altura e largura: ");
    scanf("%d %d",&p->alt,&p->larg);
}

int areaR(ret r){
    return r.alt*r.larg;
}

int dentroR(ret r, ponto2D a){
    if(a.x< r.canto.x+r.larg && a.x>r.canto.x && a.y<r.canto.y+r.alt && a.y > r.canto.y)
        return 1;
    else
        return 0;
}

void moveR(ret* p, int dx, int dy){
    p->canto.x+=dx;
    p->canto.y+=dy;
}

int contemretangulo (ret r1, ret r2)
{
    if(r1.canto.x+r1.larg<r2.canto.x || r2.canto.x+r2.larg<r1.canto.x)
        return 0;
    if(r1.canto.y+r1.alt<r2.canto.y || r2.canto.y+r2.alt<r1.canto.y)
        return 0;
}

int area_of_ovelap( ret r1, ret r2)
{
    int larg, alt;
    if(r2.canto.x>=r1.canto.x)
        larg= r1.canto.x + r1.larg - r2.canto.x;
    else
        larg= r2.canto.x + r2.larg - r1.canto.x;
    if(r2.canto.y>=r1.canto.y)
        larg= r1.canto.y + r1.alt - r2.canto.y;
    else
        larg= r2.canto.y + r2.alt - r1.canto.y;
    return larg*alt;
}

int area_of_union(ret r1, ret r2)
{
    return areaR(r1) + areaR(r2) - area_of_ovelap(r1,r2);
}

int intersection_over_union( ret r1, ret r2, double* ao, double* au)
{
    *ao = area_of_ovelap(r1,r2);
    *au = area_of_union(r1,r2);

    return (*ao)/(*au);
}
