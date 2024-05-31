/* Crie um algoritmo chamado printEscada para imprimir uma escada cujos degraus 
subam da esquerda para a direita. A entrada da função deve ser apenas um inteiro 
contendo o tamanho daescada. Atente para a formatação dos caracteres. 
Ex*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i, j, n, cont;

    printf("Digite o tamanho da escada: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
    {
        cont = i;
        for (j = i; j < n; j++) 
        {
            printf(" ");
        }
        while(cont > 0)
        {
            printf("#");
            cont--;
        }

        printf("\n");
    }
    
    return 0;
}