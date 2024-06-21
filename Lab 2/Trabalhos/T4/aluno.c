#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aluno.h"

Aluno* aloca_aluno()
{
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    printf("Digite o primeiro nome do aluno: ");
    fgets(novo->primeiro_nome, 15, stdin);
    for(int i = 0; i < 15; i++)
    getchar();
    
    printf("Digite a matricula do aluno: ");
    fgets(novo->matricula, 10, stdin);
    for (int i = 0; i < 10; i++)
    {
        if(novo->matricula[i] == '\n')
        {
            novo->matricula[i] = '\0';
        }
    }
    
    while (novo->prioritario != 0 && novo->prioritario != 1)
    {
        printf("O aluno e prioritario (Gestante, PCD, idoso)? (1 - Sim, 0 - Nao): ");
        scanf("%d", &novo->prioritario);

        if(novo->prioritario != 0 && novo->prioritario != 1)
        {
            printf("Opcao invalida\n");
        }
    }
    
    return novo;
}
