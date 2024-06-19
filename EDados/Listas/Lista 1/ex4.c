/*Fazer um programa que leia dez números e escreva-os na ordem contrária à ordem de leitura. Exemplo: 
lê:   7  40  3  9  21  0  63  31  7  22 
escreve:  22  7  31  63  0  21  9  3  40  7  
Use alocação dinâmica. O programa deve ser estruturado nas seguintes funções:  
a. Main: aloca o vetor e faz a leitura do vetor  
b. Função 1: escreve o vetor na ordem contrária*/

#include<stdio.h>
#include<stdlib.h>

void print_inverted(int size, int *vetor)
{
    int i;
    for (i = size-1 ; i >= 0; i--)
    {
        printf("%d ", vetor[i]);
    }
}

int main ()
{
    int vetor_size, i;

    printf("Digite o numero de elementos do vetor: \n");
    scanf("%d", &vetor_size);

    int *vetor = (int *)malloc(vetor_size * sizeof(int));

    for(i=0; i < vetor_size; i++)
    {
        printf("Digite o elemento %d do vetor:\n",i+1);
        scanf("%d",&vetor[i]);
    }

    printf("O vetor invertido eh:\n");

    print_inverted(vetor_size, vetor);

    free(vetor);

    return 0;
}

