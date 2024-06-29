#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* cria_fila()
{
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int fila_vazia(Fila *fila)
{
    if(fila->inicio == NULL)
    {
        return 1;
    }
    return 0;
}

Aluno* aloca_aluno()
{
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    novo->prox = NULL;
    return novo;
}

Fila* insere_fila(Fila *fila)
{
    Aluno *novo = aloca_aluno();
    printf("Digite o ticket do aluno: ");
    fflush(stdin);
    fgets(novo->ticket, 11, stdin);
    novo->ticket[strcspn(novo->ticket, "\n")] = '\0';

    novo->codigo_bandeja = 0;
    if(fila_vazia(fila) == 1)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        Aluno* aux = fila->fim;
        aux->prox = novo;
        fila->fim = novo;
    }
    return fila;
}

Fila* juntafila(Fila *fila_geral, Fila *fila)
{
    if(fila_vazia(fila) == 1)
    {
        return fila_geral;
    }

    Aluno *aux = fila->inicio;
    while(aux != NULL)
    {
        Aluno *novo = aloca_aluno();
        strcpy(novo->ticket, aux->ticket);
        novo->codigo_bandeja = aux->codigo_bandeja;

        if(fila_vazia(fila_geral))
        {
            fila_geral->inicio = novo;
            fila_geral->fim = novo;
        }
        else
        {
            fila_geral->fim->prox = novo;
            fila_geral->fim = novo;
        }

        aux = aux->prox;
    }

    return fila_geral;
}

int checa_bandeja(Aluno *aluno)
{
    if(aluno->codigo_bandeja == 0)
    {
        return 0;
    }
    return 1;
}

Fila* remove_aluno(Fila *fila)
{
    if(fila_vazia(fila) == 1)
    {
        printf("Fila vazia\n");
        return fila;
    }
    Aluno *aux = fila->inicio;
    if(checa_bandeja(aux) == 0)
    {
        printf("Aluno nao pode ser retirado, ainda nao tem bandeja\n\n");
        return fila;
    }
    else
    {
        fila->inicio = aux->prox;
        printf("Aluno %s saiu da fila, com a bandeja %d\n", aux->ticket, aux->codigo_bandeja);
        free(aux);
        return fila;
    }
}


void imprime_fila(Fila *fila)
{
    if(fila_vazia(fila) == 1)
    {
        printf("Fila vazia\n\n");
        return;
    }
    Aluno *aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->prox)
    {
        printf("Ticket: %s\n", aux->ticket);
    }
}

void liberar_fila(Fila *fila)
{
    Aluno *aux = fila->inicio;
    while(aux != NULL)
    {
        Aluno *liberado = aux;
        aux = aux->prox;
        free(liberado);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}
