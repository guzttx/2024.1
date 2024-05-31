/*A Média Geral Acumulada (MGA) é um indicador de desempenho acadêmico que reflete a
média aritmética das médias finais das disciplinas aprovadas com nota. Estão excluídas do
cálculo da MGA as reprovações e aprovações sem nota final, tal como dispensas e
aproveitamentos sem nota. O programa deve ler os valores necessários para o cálculo da
MGA, conforme a fórmula:
MGA = (MFD1 + MFD2 + … + MFDn) / n*/

#include<stdio.h>
#include<stdlib.h>

int mga(int aprovadas, int mediaAprovadas)
{
    int mga;

    mga = mediaAprovadas / aprovadas;

    return mga;
}