/*3. Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho 
n e inverta a ordem dos elementos armazenados neste vetor. 
Esta função deve obedecer ao protótipo:  void inverte (int n, int *vet)*/

#include<stdio.h>
#include<stdlib.h>

void invert(int size, int *vetor)
{
    int i, j, aux;
    j = size - 1;
    size = size/2;

    for(i = 0; i < size; i++,j--)
    {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

void print_vetor(int size, int *vetor)
{
    int i;
    for(i = 0; i<size; i++)
    {
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int i, vetor_size;
    int *vet;

    printf("Digite o numero de elementos do vetor:\n");
    scanf("%d", &vetor_size);
    
    vet = (int *)malloc(vetor_size*sizeof(int));

    for (i=0; i < vetor_size; i++)
    {
        printf("Digite o valor do elemento %d do vetor:\n", i+1);
        scanf("%d", &vet[i]);
    }

    print_vetor(vetor_size, vet);

    printf("\n");

    invert(vetor_size, vet);
    
    printf("\n");

    print_vetor(vetor_size, vet);

    free(vet);

    return 0;
}