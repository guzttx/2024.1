#ifndef __PILHAH_INCLUDED__
#define __PILHAH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>


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

void adiciona_bandejas(Pilha *p);

int remove_bandeja(Pilha *p);

int pilha_vazia(Pilha *p);

void libera_pilha(Pilha *p);

void imprime_pilha(Pilha *p);


#endif