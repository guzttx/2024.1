#ifndef __PILHAH_INCLUDED__
#define __PILHAH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


struct bandeja
{
    int codigo;
    struct bandeja *prox;
};  
typedef struct bandeja Bandeja;

struct pilha
{
    Bandeja *topo;
}; 
typedef struct pilha Pilha;


Pilha *cria_pilha();

Bandeja *aloca_bandeja();

void* adiciona_bandejas(Pilha *pilha);

int retira_bandeja(Pilha *pilha, Fila* fila);

int pilha_vazia(Pilha *pilha);

void imprime_pilha(Pilha *pilha);


#endif