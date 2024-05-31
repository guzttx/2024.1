/*Faça um programa que leia os 5 últimos dígitos do número de matrícula de um aluno (os
dígitos devem ser lidos em uma única variável – não usar vetor!). A seguir, o programa deve
calcular o dígito verificador (DV) do número lido da seguinte maneira:
a) multiplica-se o número lido, com 5 dígitos, pelos multiplicadores 9, 8, 7, 6, 5, em ordem;
b) soma-se os resultados das multiplicações parciais. Veja um exemplo dos passos a e b:
Matrícula: 2 0 1 2 3
Peso: 9 8 7 6 5
18 0 7 12 15 = 52
c) multiplica-se o resultado da soma realizada no passo b por 10. No exemplo, 52 * 10 = 520;
d) aplica-se o resto inteiro da divisão no resultado do passo c. No exemplo, 520 % 11 = 3.
O resto obtido no passo d é o DV do número de matrícula lido. Se o resto possuir dois dígitos,
apenas o último dígito deve ser considerado. Por exemplo, se o resultado do passo d for 10, o
DV será 0. Após calculado o DV, o programa deve exibir o número de matrícula formatado
como xxxxx-x, onde o último ‘x’ refere-se ao DV.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int soma, dv, d1, d2, d3, d4, d5;

    d1 = matricula / 10000;
    d2 = (matricula % 10000) / 1000;                                        /* separa os digitos da matricula em variaveis (preparacao para o passo a) */
    d3 = (matricula % 1000) / 100;
    d4 = (matricula % 100) / 10;
    d5 = matricula % 10;

    soma = (d1 * 9) + (d2 * 8) + (d3 * 7) + (d4 * 6) + (d5 * 5);            /*execucao passo a + passo b(mult dos numeros da matricula e realizacao da soma dos valores encontrados)*/

    soma = soma * 10;                                                       /*execucao passo c(multiplicacao da soma por 10)*/

    dv = soma % 11;                                                         /*execucao passo d(resto da divisao da soma por 11)*/
    if(dv >= 10)
    {
        dv = dv % 10;
    }

    return 0;
}
