#ifndef LOCACAO_H
#define LOCACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct locadora
{
    Clientes *cliente;
    Veiculos *veiculo;
    char dia_retirada[12];
    char dia_devolucao[12];
    float valor_total;
    int ativa;
};
typedef struct locadora Rent;

struct lista_locacoes
{
    Rent data_locacao;
    struct lista_locacoes *prox;
};
typedef struct lista_locacoes Locacoes;

#endif