#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int sizei,sizej, i, j, cont = 0;

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
            if(i == j && matriz[i][j] < 9)
            {
                cont++;
            }
        }
    }
    
    if (cont != 0)
    {
        printf("Ha numeros menores que 9 na diag principal\n");
    }
    
    else
    {
        printf("Diagonal principal:\n");
        for(i = 0; i< sizei; i++)
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
    }
    
    return 0;

}