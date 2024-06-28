#ifndef __FILAH_INCLUDED__
#define __FILAH_INCLUDED__


#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct fila 
{
    struct aluno *inicio;
    struct aluno *fim;
};
typedef struct fila Fila;

Fila *cria_fila();

Fila insere_fila(Fila *f, int prioridade);

struct aluno *tira_fila(Fila *f);

Fila* concatenar_filas(Fila *f1, Fila *f2);

void imprime_fila(Fila *f);

void free_fila(Fila *f);

#endif