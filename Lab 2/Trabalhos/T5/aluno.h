#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno 
{
    int matricula;
    char nome[50];
    int ano_ingresso;
    struct aluno *ant;
    struct aluno *prox;
}; 
typedef struct aluno Aluno;

Aluno* cria_aluno();

Aluno* insere_aluno_alfabetico(Aluno *lista, Aluno *novo);

Aluno* remove_aluno(Aluno *lista, int matricula);

void imprime_lista_aluno(Aluno *lista);

void remove_nova_linha(char *string);

#endif