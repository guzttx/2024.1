/*2. Implemente uma função que receba como parâmetro um vetor de números reais (vet) de tamanho n e 
retorne  quantos  números  negativos  estão  armazenados  neste  vetor.  Esta  função  deve  obedecer  ao 
protótipo: int negativos (int n, float *vet)  Use alocação dinâmica. O valor de n é informado pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

int negatives(int size, float *vet)
{
    int i;
    int cont = 0;

    for(i = 0; i < size; i++)
    {
        if(vet[i] < 0)
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    int vetor_size;
    int i;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &vetor_size);

    float *vet = (float *)malloc(vetor_size * sizeof(float));
    
    if(vet == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for(i = 0; i < vetor_size; i++)
    {
        printf("Digite o valor %d do vetor:\n", i+1);
        scanf("%f", &vet[i]);
    }

    printf("O vetor tem %d numeros negativos\n", negatives(vetor_size, vet));

    free(vet);

    return 0;
}