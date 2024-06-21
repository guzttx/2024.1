#ifndef ALUNO_h
#define ALUNO_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados_aluno
{
    char primeiro_nome[15];
    char matricula[10];
    int prioritario;
    struct dados_aluno *prox;
};
typedef struct dados_aluno Aluno;

Aluno* aloca_aluno();

#endif