#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados_veiculo
{
    char placa[8];
    char marca[20];
    char modelo[20];
    int ano;
    float km;
    float diaria;
    int disponivel;
};  
typedef struct dados_veiculo Car;

struct lista_veiculos
{
    Car data_car;
    struct lista_veiculos *prox;
}; 
typedef struct lista_veiculos Veiculos;

Veiculos* add_carro(Veiculos *lista_veiculos);

void print_listaveiculos(Veiculos *lista_veiculos);