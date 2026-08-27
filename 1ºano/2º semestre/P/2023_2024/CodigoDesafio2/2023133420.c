#include "funcao.h"

// Nome: Maria Ana da Cruz Candeias Matos Pontes
// Número: 2023133420

// Recebe:
// Endereço inicial de uma variável do tipo data (limD)
// Variável do tipo submissao (sub)

// Devolve a classificação obtida pela submissão

// Regras para calcular a classificação:
// 1. Submissão sub deve ter sido submetida na data indicada por limD, até às 11.55. Se cumprir estas restrições, devolve 10.
// Se tiver sido submetida na data indicada, mas depois das 11.55, perde 1 ponto por cada minuto de atraso. A partir das 12.05 passa a ter cotação 0
// Se a submissão tiver data diferente da referenciada por limD, deve ser devolvido o valor 0

// A função deve igualmente atualizar a data referenciada por limD, passando-a para o dia seguinte.
// Esta atualização deve ser efetuada depois de calcular a nota a atribuir à submissão

int calculaNota(data *limD, submissao sub) {
    int d1, d2, d3;
    d2 = 11 * 60 + 55;

    if (limD->dia != sub.dataSub.dia || limD->mes != sub.dataSub.mes || limD->ano != sub.dataSub.ano) {
        return 0;
    } else {
        d1 = sub.horaSub.h * 60 + sub.horaSub.m;
        if (d1 <= d2) {
            // Se a submissão foi feita antes de 11:55 incrementa o dia
            limD->dia++;
            // Verifica se o dia é maior do que o total de dias do mês e ajusta para o próximo mês
            if (limD->dia > 30) { // Supondo que cada mês tem 30 dias
                limD->dia = 1;
                // Verifica se estamos no último mês do ano e ajusta para o próximo ano e o primeiro mês
                if (limD->mes == 12) {
                    limD->mes = 1;
                    limD->ano++;
                } else {
                    limD->mes++;
                }
            }
            return 10;
        } else {
            d3 = 10 - (d1 - d2);
            if (d3 < 0) d3 = 0; // Verifica se a nota é negativa, se a submissão foi feita depois de 11:55 incrementa o dia
            limD->dia++;
            // Verifica se o dia é maior do que o total de dias do mês e ajusta para o próximo mês
            if (limD->dia > 30) { // Supondo que cada mês tem 30 dias
                limD->dia = 1;
                // Verifica se estamos no último mês do ano e ajusta para o próximo ano e o primeiro mês
                if (limD->mes == 12) {
                    limD->mes = 1;
                    limD->ano++;
                } else {
                    limD->mes++;
                }
            }
            return d3;
        }
    }
}


int datacmp(data a, data b)
{
    int d1,d2,d3;
    if(a.dia == b.dia && a.mes == b.mes && a.ano == b.ano){
        return 0;
    }
    else{
        if(a.dia < b.dia || a.mes < b.mes || a.ano < b.ano){
            return -1;
        }
        else{
            if(a.dia > b.dia || a.mes > b.mes || a.ano > b.ano){
                return 1;
            }
        }
    }
}