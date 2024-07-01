#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

Pilha* cria_pilha()
{
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    pilha->topo = NULL;
    return pilha;
}

Bandeja* aloca_bandeja()
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

int pilha_vazia(Pilha *pilha)
{
    if(pilha->topo == NULL)
    {
        return 1;
    }
    return 0;
}

void* adiciona_bandejas(Pilha *pilha)
{
    int cont = 0;
    Bandeja *novo;
    for(novo = pilha->topo; novo != NULL; novo = novo->prox)
    {
        cont++;
    }

    if(cont >= 15)
    {
        printf("Pilha cheia\n");
    }

    else
    {
        for(int i = 0; i < 15 - cont; i++)
        {
            Bandeja *novo = aloca_bandeja();
            novo->prox = pilha->topo;
            pilha->topo = novo;
        }
    }
}

int retira_bandeja(Pilha *pilha, Fila *fila_geral)
{
    if(checa_bandeja(fila_geral->inicio) == 1)
    {
        printf("Aluno ja tem bandeja\n");
        return fila_geral->inicio->codigo_bandeja;
    }
    int codigo;
    if(pilha_vazia(pilha) == 1)
    {
        printf("Pilha vazia\n");
        return 0;
    }
    Bandeja *aux = pilha->topo;
    codigo = aux->codigo;
    pilha->topo = aux->prox;
    free(aux);
    fila_geral->inicio->codigo_bandeja = codigo;
    return codigo;
}

void imprime_pilha(Pilha *pilha)
{
    if(pilha_vazia(pilha) == 1)
    {
        printf("Pilha vazia\n\n");
    }
    else
    {
        Bandeja *aux;
        for(aux = pilha->topo; aux != NULL; aux = aux->prox)
        {
            printf("Codigo da bandeja: %d\n", aux->codigo);
        }
    }
}