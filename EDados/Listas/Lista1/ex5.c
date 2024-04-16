/*5. Fazer  um  programa  que  leia  n  números  reais,  armazene-os  num  vetor  e  escreva  o  percentual  de 
números que são maiores que a média dos mesmos. O programa deve ser estruturado nas seguintes funções:  
a. Main: lê o tamanho do vetor, chama as outras funções e mostra o percentual na tela 
b. Função 1: aloca o vetor c. 
Função 2: faz a leitura do vetor d. 
Função 3: faz o cálculo da média e. 
Função 4: verifica o percentual de números que são maiores que a média 
Use alocação dinâmica. Não se esqueça de desalocar o vetor tão logo seja possível.*/

#include<stdio.h>
#include<stdlib.h>

void vetor_alloc(int size, float *v)
{
    v = (float *)malloc(size * sizeof(float));
    if(v == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
}

void read_vetor(int size, float *vetor)
{
    for(int i = 0; i < size; i++)
    {
        printf("Digite o valor do elemento %d do vetor:\n", i+1);
        scanf("%f", &vetor[i]);
    }
}

float media_vetor(int size, float *vetor)
{
    float soma = 0;
    for(int i = 0; i < size; i++)
    {
        soma += vetor[i];
    }
    soma = soma/size;
    return soma;
}

float percent_overaverage(int size, float *vetor, float media)
{
    float cont = 0;
    for(int i = 0; i < size; i++)
    {
        if(vetor[i] > media)
        {
            cont++;
        }
    }

    return (cont/(float)size)*100;
}

int main()
{
    float *vetor;
    int array_size;
    float media, percentage;

    printf("Digite o numero de elementos a serem adicionados no vetor:\n");
    scanf("%d", &array_size);

    vetor_alloc(array_size, vetor);
    read_vetor(array_size, vetor);

    media = media_vetor(array_size, vetor);
    printf("A media dos elementos do vetor eh: %.2f\n", media);

    percentage = percent_overaverage(array_size, vetor, media);
    printf("O percentual de elementos maiores que a media eh: %.2f%%\n", percentage);


    free(vetor);
}