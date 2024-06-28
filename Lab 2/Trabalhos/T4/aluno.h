#ifndef __ALUNOH_INCLUDED__
#define __ALUNOH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct aluno
{
    char ticket[10];
    int prioritario;
    struct aluno *prox;
    int codigo_bandeja;
};
typedef struct aluno Aluno;

struct refeitorio
{
    struct aluno *prox;
};
typedef struct refeitorio Refeitorio;

Refeitorio* cria_refeitorio();

Aluno* aloca_aluno(int prioritario);

Refeitorio* senta_refeitorio(Aluno *a, Refeitorio *r);

Refeitorio* libera_refeitorio(Refeitorio *r);

void imprime_refeitorio(Refeitorio *r);

#endif