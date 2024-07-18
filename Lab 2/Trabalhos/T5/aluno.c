#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"


Aluno* cria_aluno()
{
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }


    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(novo->nome, 50, stdin);
    remove_nova_linha(novo->nome);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo->matricula);

    printf("Digite o ano de ingresso do aluno na instituicao: ");
    scanf("%d", &novo->ano_ingresso);

    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

Aluno* insere_aluno_alfabetico(Aluno *lista, Aluno *novo)
{
    if(lista == NULL)
    {
        return novo;
    }
    if(strcmp(novo->nome, lista->nome) < 0)
    {
        novo->prox = lista;
        lista->ant = novo;
        return novo;
    }
    Aluno *aux = lista;
    while(aux->prox != NULL && strcmp(novo->nome, aux->prox->nome) > 0)
    {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    if(aux->prox != NULL)
    {
        aux->prox->ant = novo;
    }
    aux->prox = novo;
    novo->ant = aux;
    return lista;
}

Aluno* remove_aluno(Aluno *lista, int matricula)
{
    Aluno *aux = lista;
    while(aux != NULL && aux->matricula != matricula)
    {
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        return lista;
    }
    if(aux->ant == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        aux->ant->prox = aux->prox;
    }
    if(aux->prox != NULL)
    {
        aux->prox->ant = aux->ant;
    }
    printf("%s foi removido do curso", aux->nome);
    free(aux);
    return lista;
}

void imprime_lista_aluno(Aluno *lista)
{
    Aluno *aux = lista;
    if (aux==NULL)
    {
        printf("Nenhum aluno cadastrado no curso.\n");
    }
    while(aux != NULL)
    {
        printf("Nome: %s\n", aux->nome);
        printf("Matricula: %d\n", aux->matricula);
        printf("Ano de ingresso: %d\n", aux->ano_ingresso);
        aux = aux->prox;
    }
}

void remove_nova_linha(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
        i++;
    }
}