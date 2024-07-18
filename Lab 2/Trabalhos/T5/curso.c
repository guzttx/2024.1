#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "curso.h"
#include "aluno.h"

Curso* cria_curso()
{
    Curso *novo = (Curso*) malloc(sizeof(Curso));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    printf("Digite o codigo do curso: ");
    scanf("%d", &novo->codigo_curso);

    printf("Digite o nome do curso: ");
    fflush(stdin);
    fgets(novo->nome_curso, 30, stdin);
    remove_nova_linha(novo->nome_curso);

    printf("Digite o predio: ");
    fflush(stdin);
    fgets(novo->predio, 40, stdin);
    remove_nova_linha(novo->predio);

    novo->lista_alunos = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Curso* insere_curso(Curso *pai, Curso *novo)
{
    if(pai == NULL)
    {
        return novo;
    }
    if(novo->codigo_curso < pai->codigo_curso)
    {
        pai->esq = insere_curso(pai->esq, novo);
    }
    else
    {
        pai->dir = insere_curso(pai->dir, novo);
    }
    return pai;
}

Curso* remove_curso(Curso *pai, int codigo_curso)
{
    if(pai == NULL)
    {
        return NULL;
    }
    if(codigo_curso < pai->codigo_curso)
    {
        pai->esq = remove_curso(pai->esq, codigo_curso);
    }
    else if(codigo_curso > pai->codigo_curso)
    {
        pai->dir = remove_curso(pai->dir, codigo_curso);
    }
    else
    {
        if(pai->esq == NULL && pai->dir == NULL)
        {
            free(pai);
            return NULL;
        }
        else if(pai->esq == NULL)
        {
            Curso *aux = pai->dir;
            free(pai);
            return aux;
        }
        else if(pai->dir == NULL)
        {
            Curso *aux = pai->esq;
            free(pai);
            return aux;
        }
        else
        {
            Curso *aux = pai->esq;
            while(aux->dir != NULL)
            {
                aux = aux->dir;
            }
            pai->codigo_curso = aux->codigo_curso;
            strcpy(pai->nome_curso, aux->nome_curso);
            strcpy(pai->predio, aux->predio);
            pai->lista_alunos = aux->lista_alunos;
            pai->esq = remove_curso(pai->esq, aux->codigo_curso);
        }
    }
    return pai;
}

Curso* busca_curso(Curso *busca, int codigo_curso)
{
    if(busca == NULL)
    {
        printf("Curso nao encontrado!\n");
        return NULL;
    }
    if(codigo_curso < busca->codigo_curso)
    {
        return busca_curso(busca->esq, codigo_curso);
    }
    else if(codigo_curso > busca->codigo_curso)
    {
        return busca_curso(busca->dir, codigo_curso);
    }
    else
    {
        printf("Curso encontrado!\n");
        return busca;
    }
}

void imprime_curso(Curso *curso)
{
    if(curso != NULL)
    {
        printf("Codigo do curso: %d\n", curso->codigo_curso);
        printf("Nome do curso: %s\n", curso->nome_curso);
        printf("Predio: %s\n", curso->predio);
    }
}

void imprime_arvore_curso(Curso *raiz)
{
    if(raiz != NULL)
    {
        imprime_arvore_curso(raiz->esq);
        imprime_curso(raiz);
        imprime_arvore_curso(raiz->dir);
    }
    else
    {
        printf("-\n");
    }
}

void imprime_alunos_curso(Curso *curso)
{
    if (curso->lista_alunos != NULL)
    {
        imprime_lista_aluno(curso->lista_alunos);
    }
    else
    {
        printf("Nenhum aluno cadastrado!\n");
    }
}

void imprime_vinculos(Curso *raiz)
{
    if(raiz != NULL)
    {
        imprime_vinculos(raiz->esq);
        printf("Codigo do curso: %d\n", raiz->codigo_curso);
        if(raiz->lista_alunos != NULL)
        {
            printf("Curso: %s\n", raiz->nome_curso);
            printf("Predio: %s\n", raiz->predio);
            printf("Alunos:\n");
            imprime_lista_aluno(raiz->lista_alunos);
        }
        imprime_vinculos(raiz->dir);
    }
    else
    {
        printf("-\n");
    }
}