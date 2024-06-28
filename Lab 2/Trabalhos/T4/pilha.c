#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

Pilha *cria_pilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    p->topo = NULL;
    return p;
}

Bandeja *aloca_bandeja()
{
    Bandeja *novo = (Bandeja*)malloc(sizeof(Bandeja));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    novo->codigo = rand() % 1000;
    novo->prox = NULL;
    return novo;
}

void adiciona_bandejas(Pilha *p)
{
    int cont = 10;
    Bandeja *aux = p;
    for(aux = p->topo; aux->prox != NULL; aux = aux->prox)
    {
        cont--;
    }

    if(cont == 0)
    {
        printf("Pilha cheia\n");
        return;
    }

    for(int i = 0; i < cont; i++)
    {
        Bandeja *novo = aloca_bandeja();
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int remove_bandeja(Pilha *p)
{
    if(pilha_vazia(p) == 1)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    int codigo;
    Bandeja *aux = p->topo;
    p->topo = aux->prox;
    codigo = aux->codigo;
    free(aux);
    return codigo;
}

int pilha_vazia(Pilha *p)
{
    if(p->topo == NULL)
    {
        return 1;
    }
}

void libera_pilha(Pilha *p)
{
    Bandeja *aux = p->topo;
    while(aux != NULL)
    {
        Bandeja *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(p);
}

void imprime_pilha(Pilha *p)
{
    Bandeja *aux = p->topo;
    while(aux != NULL)
    {
        printf("Codigo da bandeja: %d\n", aux->codigo);
        aux = aux->prox;
    }
}