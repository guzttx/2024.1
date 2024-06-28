#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "aluno.h"

Fila *cria_fila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

Fila insere_fila(Fila *f, int prioridade)
{
    Aluno *novo = aloca_aluno(prioridade);
    if(f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return *f;
}

/*Fila *tira_fila(Fila *f, Refeitorio *r)
{
    if(f->inicio == NULL)
    {
        printf("Fila vazia\n");
        return NULL;
    }
    Aluno *aux = f->inicio;
    senta_refeitorio(aux, r);
    f->inicio = aux->prox;
    free(aux);
    return f;
}*/

Aluno *tira_fila(Fila *f)
{
    if(f->inicio == NULL)
    {
        printf("Fila vazia\n");
        return NULL;
    }
    Aluno *aux = f->inicio;
    f->inicio = aux->prox;
    return aux;
}

Fila* concatenar_filas(Fila *fila1, Fila *fila2)
{
    if(fila1->inicio == NULL)
    {
        return fila2;
    }
    if(fila2->inicio == NULL)
    {
        return fila1;
    }
    fila1->fim->prox = fila2->inicio;
    fila1->fim = fila2->fim;
    return fila1;
}

void imprime_fila(Fila *f)
{
    Aluno *aux = f->inicio;
    while(aux != NULL)
    {
        printf("Aluno %s\n", aux->ticket);
        aux = aux->prox;
    }
}

void free_fila(Fila *f)
{
    Aluno *aux = f->inicio;
    while(aux != NULL)
    {
        Aluno *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(f);
}