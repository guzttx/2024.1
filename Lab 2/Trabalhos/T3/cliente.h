#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
    char cnh[12];
    char nome[20];
    char telefone[12];
};
typedef struct cliente Customer;

struct lista_clientes
{
    Customer data_customer;
    struct lista_cliente *prox;
};
typedef struct lista_clientes Clientes;