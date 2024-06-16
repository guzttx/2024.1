#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"


Veiculos* add_carro(Veiculos* lista_veiculos)
{
    Veiculos *novo = (Veiculos*)malloc(sizeof(Veiculos));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    printf("Digite a placa do veiculo: ");
    fgets(novo->data_car.placa, 8, stdin);
    for(int i = 0; i < 8; i++)
    getchar();
    
    printf("Digite a marca do veiculo: ");
    fgets(novo->data_car.marca, 20, stdin);
    for (int i = 0; i < 20; i++)
    {
        if(novo->data_car.marca[i] == '\n')
        {
            novo->data_car.marca[i] = '\0';
        }
    }
    
    printf("Digite o modelo do veiculo: ");
    fgets(novo->data_car.modelo, 20, stdin);
    for (int i = 0; i < 20; i++)
    {
        if(novo->data_car.modelo[i] == '\n')
        {
            novo->data_car.modelo[i] = '\0';
        }
    }
    
    printf("Digite o ano do veiculo: ");
    scanf("%d", &novo->data_car.ano);
    
    printf("Digite a quilometragem do veiculo: ");
    scanf("%f", &novo->data_car.km);

    printf("Digite o valor da diaria do veiculo: ");
    scanf("%f", &novo->data_car.diaria);

    novo->data_car.disponivel = 1;

    Veiculos *aux = lista_veiculos;
    if(aux == NULL)
    {
        novo->prox = NULL;
        return novo;
    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
        return lista_veiculos;
    }
}

void print_listaveiculos(Veiculos* lista_veiculos)
{
    Veiculos *aux = lista_veiculos;
    if(aux == NULL)
    {
        printf("Nenhum veiculo cadastrado\n");
    }
    else
    {
        while(aux != NULL)
        {
            printf("Placa: %s\n", aux->data_car.placa);
            printf("Marca: %s\n", aux->data_car.marca);
            printf("Modelo: %s\n", aux->data_car.modelo);
            printf("Ano: %d\n", aux->data_car.ano);
            printf("Quilometragem: %.2f\n", aux->data_car.km);
            printf("Diaria: %.2f\n", aux->data_car.diaria);
            if(aux->data_car.disponivel == 1)
            {
                printf("Disponivel\n");
            }
            else
            {
                printf("Indisponivel\n");
            }
            printf("\n");
            aux = aux->prox;
        }
    }
}
