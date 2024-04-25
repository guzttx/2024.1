//Crie uma função que recebe como parâmetro um vetor de inteiros e retorna o último elemento deste vetor.

#include <stdio.h>
#include <stdlib.h>

int ultimoElemento(int *vetor, int tamanho){
    return vetor[tamanho-1];
}

int main(){
    int vetor[5] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    printf("O ultimo elemento do vetor eh: %d\n", ultimoElemento(vetor, tamanho));
    return 0;
}