#ifndef CURSO_H
#define CURSO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct arvore
{
    int codigo_curso;
    char nome_curso[30];
    char predio[40];
    Aluno *lista_alunos;
    struct arvore *esq;
    struct arvore *dir;
};
typedef struct arvore Curso;

Curso* cria_curso();

Curso* insere_curso(Curso *raiz, Curso *novo);

Curso* remove_curso(Curso *pai, int codigo_curso);

Curso* busca_curso(Curso *busca, int codigo_curso);

void imprime_curso(Curso *curso);

void imprime_arvore_curso(Curso *raiz);

void imprime_alunos_curso(Curso *raiz);

void imprime_vinculos(Curso *raiz);

#endif