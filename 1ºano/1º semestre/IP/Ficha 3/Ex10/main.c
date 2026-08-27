#include <stdio.h>

int main()
{
    int diaI, mesI, anoI;
    int diaF, mesF, anoF;
    
    printf("Indique Dia/Mes/Ano \n");
    scanf("%d/%d/%d", &diaI, &mesI, &anoI);
    
    if(mesI==12 && diaI==31){
        diaF = 1;
        mesF = 1;
        anoF = anoI + 1;
    }
    
    else if(diaI==28 && mesI==2 || 
            (diaI==30 && (mesI==4 || mesI==6 || mesI==9 || mesI==11)) || 
            (diaI==31 && (mesI==1 || mesI==3 || mesI==5 || mesI==7 || mesI==8 || mesI==10))){
                
        diaF = 1;
        mesF = mesI + 1;
        anoF = anoI;
    }
    else{
        diaF = diaI + 1;
        mesF = mesI;
        anoF = anoI;
    }
    
    printf("O dia seguinte e %d/%d/%d", diaF, mesF, anoF);
    return 0;
}