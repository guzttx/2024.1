/*crie um algoritmo que receba uma matriz e a imprima sua diagonal principal*/

#include <stdio.h>
#include <stdlib.h>


int main() 
{
    int sizei,sizej, i, j;

    printf("Digite o numero de linhas da matriz: ");    
    scanf("%d", &sizei);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &sizej);

    int matriz[sizei][sizej];

    for (i = 0; i < sizei; i++)
    {
        for (j = 0; j < sizej; j++)
        {
            printf("Digite o valor da posicao [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < sizei; i++)
    {
        for(j = 0; j < sizej; j++)
        {
            if(i == j)
            {
                printf("%d ", matriz[i][j]);
            }

            else 
            {
                printf("  ");
            }

        }
        printf("\n");
    }



    return 0;    
}