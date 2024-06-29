#ifndef __FILAH_INCLUDED__
#define __FILAH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char ticket[11];
    struct aluno *prox;
    int codigo_bandeja;
};
typedef struct aluno Aluno;

struct fila 
{
    struct aluno *inicio;
    struct aluno *fim;
};
typedef struct fila Fila;

Fila* cria_fila();

Fila* insere_fila(Fila *fila);

Aluno* aloca_aluno();

Fila* remove_aluno(Fila *fila);

Fila* juntafila(Fila *fila_geral, Fila *fila);

int checa_bandeja(Aluno *aluno);

int fila_vazia(Fila *fila);

void imprime_fila(Fila *fila);

void liberar_fila(Fila *fila);

#endif