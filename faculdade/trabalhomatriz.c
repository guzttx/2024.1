/*Dada uma sequência de n (n > 0) números inteiros, definimos a mediana inteira da seguinte forma:
 se n é ímpar, a mediana inteira é o valor que ocupa a posição central na sequência quando
ordenada;
 se n é par, a mediana inteira é a parte inteira da média entre os valores que ocupam as posições
mais centrais na sequência quando ordenada.
Exemplos:
Sequência: 7 -3 7 1 3
Sequência ordenada: -3 1 3 7 7
Mediana inteira: 3
Sequência: 11 10 6 3 1 0
Sequência ordenada: 0 1 3 6 10 11
Mediana inteira: 4 (pois os dois elementos mais centrais são 3 e 6, resultando em média 4.5, cuja parte
inteira é 4).
Neste trabalho, considere que os vizinhos de uma posição qualquer de uma matriz são aqueles
definidos pela vizinhança do tipo rei (isto é, as 8 posições adjacentes).
Seja M uma matriz de inteiros. O objetivo é calcular uma matriz Med, também inteira, de mesma
dimensão da matriz M, na qual o elemento Med[i][j] é exatamente igual à mediana inteira dos valores
de M na vizinhança de [i][j] mais o valor em M[i][j].
Faça um programa que leia uma matriz M de inteiros com L linhas e C colunas (onde L e C são
maiores que zero e menores ou iguais a 100) e a imprima de modo formatado (impressão formatada
como matriz, obedecendo linhas e colunas, sem necessidade da grade que envolve os valores). A
seguir, para cada valor da matriz, o programa deve:
Laboratório de Programação I / 2023-2 Trabalho: Programa com matriz Profa Patrícia Pitthan
1- imprimir a sequência de valores a serem considerados no cálculo da mediana (incluindo o
próprio valor). Conforme o exemplo acima, nesta etapa devem ser impressos os valores que
se encontram apontados pelas flechinhas;
2- em seguida, ordenar crescentemente os valores impressos na etapa anterior, exibindo a
sequência ordenada;
3- no próximo passo, deve ser identificada e exibida a mediana inteira da sequência;
4- por fim, o programa deve gerar e exibir a matriz Med (formatada como explicado
anteriormente).*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int matriz[3][4] = {{1, 5, 2, 0}, {-1, 3, 10, 8}, {0, 4, 5, -2}};
    int med[3][4];
    int i, j, x, y, cont = 0, v;
    int limx, limy, auxx, auxy;
    int sizei, sizej;
    int k, m, u;
    int l, c;

    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%3d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    //for(i = 0; i < 3; i++)
    //{
        //for(j = 0; j < 4; j++)
        //{

        i = 1;
        j = 2;

            x = (i - 1);                     //         x = linha 0
            auxx = x;
            y = (j - 1);                     //         y = coluna 1
            auxy = y;
            limx = i+1;                 
            limy = j+1;
            if (x < 0)
            {
                x++;
                auxx = x;
            }
            if (y<0)
            {
                y++;
                auxy = y;
            }
            if (limx == 3)                                          //                                  substituir 3 e 4 por L e C dps
            {
                limx = i;
            }
            if (limy == 4)
            {
                limy = j;
            }

            //printf("%d %d %d %d %d %d \n\n",x ,y, limx, limy, auxx, auxy);

            for(x = auxx; x <= limx; x++)
            {
                for(y = auxy; y <= limy; y++)
                {
                    cont++;
                }
            }

            //printf("\n\n%d\n\n", cont);

            int vetor[cont];
            v=0;
            
            for (k = auxx; k <= limx; k++)
            {
                for(m = auxy; m <= limy; m++)
                {
                    vetor[v] = matriz[k][m];
                    v++;
                }
            }
    
            for(u = 0; u < cont; u++)
            {
                printf(" %2d ", vetor[u]);
            }

            printf("\n\n");

            cont = 0;

            printf("\n\n\n");
        //}
        printf("\n\n");
    //}


    return 0;

}