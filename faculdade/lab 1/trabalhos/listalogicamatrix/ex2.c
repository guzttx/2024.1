/*crie um algoritmo que receba uma matriz e a imprima*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizex, sizey, i, j, soma = 0;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &sizex);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &sizey);

    int matriz[sizex][sizey];

    for (i = 0; i < sizex; i++)
    {
        for (j = 0; j < sizey; j++)
        {
            printf("Digite o valor da posicao [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0; i < sizex; i++)
    {
        for(j=0; j < sizey; j++)
        {
            if(i==j)
            {
                soma = soma + matriz[i][j];
            }
        }
    }
    if (soma > 10)
    {
        printf("Diagonal principal:\n");
        for(i=0; i < sizex; i++)
        {
            for(j=0; j < sizey; j++)
            {
                if(i==j)
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
    }
    else
    {
        printf("Soma da diag principal menor que 10\n");
    }
    return 0;

}