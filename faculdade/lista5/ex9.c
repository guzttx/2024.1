#include<stdio.h>
#include<stdlib.h>

int numeroNaSequencia(int indice) {
    if (indice > 2) {
        return numeroNaSequencia(indice - 1) + numeroNaSequencia(indice - 2) + 1;
    } else {
        return 1;
    }
}

int main() {

    int numero;

    printf("Digite o indice do numero na sequencia: ");
    scanf("%d", &numero);

    int resultado = numeroNaSequencia(numero);
    printf("Para o indice %d, o numero na sequencia e: %d\n", numero, resultado);
    return 0;
}