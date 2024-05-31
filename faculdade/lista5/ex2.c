/*Crie um algoritmo que receba uma matriz e imprima os números de sua 
diagonal principal caso todos os números da diagonal secundária sejam maiores do que 3. 
Caso contrário, imprima a somados elementos da primeira coluna.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ordem, i, j, soma = 0, cont = 0;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    int matriz[ordem][ordem];

    for(i=0; i < ordem; i++)
    {
        for(j=0; j < ordem; j++)
        {
            printf("Digite o valor da posicao [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }


    for(i=0; i < ordem; i++)
    {
        for(j = 0; j < ordem; j++)
        {
            if(j == 0)
            {
                soma = soma +matriz[i][j];
            }
            if(i + j == ordem - 1)
            {
                if(matriz[i][j] > 3)
                {
                    cont++;
                }
            }
        }
    }

    if(cont == ordem)
    {
        printf("Diagonal principal: \n");
        for (i = 0; i < ordem; i++)
        {
            printf("%d\n", matriz[i][i]);
        }
    }

    else
    {
        printf("Soma da primeira coluna: %d\n", soma);
    }

    return 0;
}