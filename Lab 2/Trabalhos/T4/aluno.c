#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "fila.h"

Aluno* aloca_aluno(int prioritario)
{
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    printf("Digite o ticket(matricula) de no max 10 digitos do aluno: ");
    fgets(novo->ticket, 10, stdin);
    for (int i = 0; i < 10; i++)
    {
        tolower(novo->ticket[i]);
        if(novo->ticket[i] == '\n')
        {
            novo->ticket[i] = '\0';
        }
    }
    novo->prioritario = prioritario;
    novo->prox = NULL;
    novo->codigo_bandeja = NULL;
    return novo;
}

Refeitorio* cria_refeitorio()
{
    Refeitorio *novo = (Refeitorio*)malloc(sizeof(Refeitorio));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    novo->prox = NULL;
    return novo;
}

Refeitorio senta_refeitorio(Aluno *aluno, Refeitorio *r)
{
    if(r->prox == NULL)
    {
        r->prox = aluno;
    }
    else
    {
        Aluno *aux = r->prox;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = aluno;
    }
    
    return *r;
}

/*Refeitorio senta_refeitorio(Aluno *aluno, Refeitorio *r)
{
    Aluno *copia = aloca_aluno(aluno->prioritario);
    strcpy(copia->ticket, aluno->ticket);
    copia->codigo_bandeja = aluno->codigo_bandeja;
    copia->prox =NULL;

    if(r->prox == NULL)
    {
        r->prox = copia;
    }
    else
    {
        Aluno *aux = r->prox;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = copia;
    }
    
    return *r;
}*/

Refeitorio libera_refeitorio(Refeitorio *r)
{
    if(r->prox == NULL)
    {
        printf("Refeitorio vazio\n");
    }
    else
    {
        Aluno *aux = r->prox;

        while(aux != NULL)
        {
            Aluno *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }

        r->prox = NULL;
    }

    return *r;
}

void imprime_refeitorio(Refeitorio *r)
{
    if(r->prox == NULL)
    {
        printf("Refeitorio vazio\n");
    }
    else
    {
        Aluno *aux = r->prox;
        while(aux != NULL)
        {
            printf("Ticket: %s\n", aux->ticket);
            aux = aux->prox;
        }
    }
}