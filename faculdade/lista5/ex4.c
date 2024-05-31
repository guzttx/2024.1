/*Crie um registro para guardar dados de um apartamento em uma locadora de imóveis.*/

#include <stdio.h>
#include <stdlib.h>

struct ficha_apartamento
{
    int numero;
    int andar;
    int quartos;
    int banheiros;
    int garagem;
    int valor;
} apartamento[10];


void imprime_pessoa(int apartamento)
{
    int i;
    int *p;

    for(i=0; i < 10; i++)
    {
        *p = &apartamento[i];
        printf("Apartamento %d\n", i+1);
        printf("Numero: %d\n", apartamento[i].numero);
        printf("Andar: %d\n", apartamento[i].andar);
        printf("Quartos: %d\n", apartamento[i].quartos);
        printf("Banheiros: %d\n", apartamento[i].banheiros);
        printf("Garagem: %d\n", apartamento[i].garagem);
        printf("Valor: %d\n", apartamento[i].valor);
    }
}

int main()
{
    int i;
    int n = 10;

    printf("Registro de apartamentos~\n");

    for(i=0; i < n; i++)
    {
        printf("Apartamento %d\n", i+1);
        printf("Numero: ");
        scanf("%d", &apartamento[i].numero);
        printf("Andar: ");
        scanf("%d", &apartamento[i].andar);
        printf("Quartos: ");
        scanf("%d", &apartamento[i].quartos);
        printf("Banheiros: ");
        scanf("%d", &apartamento[i].banheiros);
        printf("Garagem: ");
        scanf("%d", &apartamento[i].garagem);
        printf("Valor: ");
        scanf("%d", &apartamento[i].valor);
    }
    
    imprime_pessoa(apartamento);

    return 0;
}