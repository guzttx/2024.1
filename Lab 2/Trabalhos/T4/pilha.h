#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct bandeja
{
    int codigo;
    struct bandeja *prox;
};  typedef struct bandeja Pilha;


Pilha *cria_pilha();

void push(Pilha *p, int codigo);

int pop(Pilha *p);

int pilha_vazia(Pilha *p);

void libera_pilha(Pilha *p);

void imprime_pilha(Pilha *p);


#endif