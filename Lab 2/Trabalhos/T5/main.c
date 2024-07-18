/*
TRABALHO 5 LABORATORIO DE PROGRAMACAO 2
AUTORES: GUSTAVO MACHADO TEIXEIRA
    JOAO HENRIQUE SCHERER WOLSKI
PROFESSORA: DEISE DE BRUM SACCOL
*/

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "curso.h"

int main()
{
    int opcao = 0;
    int codigo_curso;
    int matricula;

    Curso *arvore = NULL;
    Curso *curso;
    Aluno *aluno;

    while(opcao != 8)
    {
        printf("\n1. Inserir curso\n");
        printf("2. Excluir curso\n");
        printf("3. Imprimir arvore de cursos\n");
        printf("4. Inserir aluno em um curso\n");
        printf("5. Excluir aluno de um curso\n");
        printf("6. Imprimir lista de alunos de um curso\n");
        printf("7. Impressao de dados de vinculos entre alunos e cursos\n");
        printf("8. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                curso = cria_curso();
                arvore = insere_curso(arvore, curso);
                printf("\n\n");
                break;
            
            case 2:
                printf("Digite o codigo do curso que deseja excluir: ");
                scanf("%d", &codigo_curso);
                arvore = remove_curso(arvore, codigo_curso);
                printf("\n\n");
                break;
            
            case 3:
                if(arvore == NULL)
                {
                    printf("Nenhum curso cadastrado");
                }
                else
                {
                    imprime_arvore_curso(arvore);
                }
                printf("\n\n");
                break;

            case 4:
                printf("Digite o codigo do curso que deseja inserir o aluno: ");
                scanf("%d", &codigo_curso);
                curso = busca_curso(arvore, codigo_curso);
                if(curso != NULL)
                {
                    aluno = cria_aluno();
                    curso->lista_alunos = insere_aluno_alfabetico(curso->lista_alunos, aluno);
                }
                printf("\n\n");
                break;
            
            case 5:
                printf("Digite o codigo do curso que deseja excluir o aluno: ");
                scanf("%d", &codigo_curso);
                curso = busca_curso(arvore, codigo_curso);
                if(curso != NULL)
                {
                    if(curso->lista_alunos == NULL)
                    {
                        printf("Nao ha alunos matriculados neste curso\n");
                        break;
                    }
                    else
                    {
                        printf("Alunos matriculados no curso:\n");
                        imprime_lista_aluno(curso->lista_alunos);

                        printf("Digite a matricula do aluno que deseja excluir: ");
                        scanf("%d", &matricula);
                        curso->lista_alunos = remove_aluno(curso->lista_alunos, matricula);
                    }
                }
                printf("\n\n");
                break;
            
            case 6:
                printf("Digite o codigo do curso que deseja imprimir os alunos: ");
                scanf("%d", &codigo_curso);
                curso = busca_curso(arvore, codigo_curso);
                if(curso != NULL)
                {
                    imprime_lista_aluno(curso->lista_alunos);
                }
                printf("\n\n");
                break;
            

            case 7:
                imprime_vinculos(arvore);
                printf("\n\n");
                break;

            case 8:
                printf("Saindo...\n");
                break;
            
            default:
                printf("Opcao invalida\n");
                printf("\n\n");
                break;
        }
    }

    return 0;

}