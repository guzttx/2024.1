/*Crie um algoritmo chamado printEscadaDown para imprimir uma escada cujos degraus desçam da esquerda para a direita e sejam numerados.
A entrada da função deve ser apenas um inteiro contendo o tamanho da escada. Atente para a formatação dos caracteres.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n;

    printf("Digite o tamanho da escada: ");
    scanf("%d", &n);

    for(i=0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf("\t");
        }    
        printf("%d",i+1);
        printf("\n");
    }   
    return 0;
}