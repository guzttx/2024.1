#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"


int main()
{
    int opcao = 1;

    
    Fila *fila_normal = cria_fila();
    Fila *fila_prioritaria = cria_fila();
    Fila *fila_geral = cria_fila();

    Pilha *pilha_bandejas = cria_pilha();

    while(opcao != 0)
    {
        printf("1 - Inserir fila normal\n");
        printf("2 - Inserir na fila prioritaria\n");
        printf("3 - Fundir filas\n");
        printf("4 - Completar pilha com bandejas\n");
        printf("5 - Retirar bandeja\n");
        printf("6 - Sentar aluno\n");
        printf("7 - Imprimir filas e pilha\n");
        printf("0 - Sair\n\n");

        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
            printf("Inserindo na fila normal...\n");
            insere_fila(fila_normal);
            break;
            
            case 2:
            printf("Inserindo na fila prioritaria...\n");
            insere_fila(fila_prioritaria);            
            break;
            
            case 3:
            printf("Fundindo filas...\n");
            if(fila_vazia(fila_normal) == 1 && fila_vazia(fila_prioritaria) == 1)
            {
                printf("Filas vazias\n");
                break;
            }
            fila_geral = juntafila(fila_geral, fila_prioritaria);
            fila_geral = juntafila(fila_geral, fila_normal);
            liberar_fila(fila_normal);
            liberar_fila(fila_prioritaria);
            break;

            case 4:
            printf("Completando pilha com bandejas...\n");
            adiciona_bandejas(pilha_bandejas);
            break;

            case 5:
            printf("Retirando bandeja do topo da pilha...\n");
            if(fila_vazia(fila_geral) == 0)
            {
                int codigo = retira_bandeja(pilha_bandejas, fila_geral);
                printf("Bandeja retirada: %d\n", codigo);
            }
            else
            {
                printf("Fila vazia, impossivel retirar bandeja do topo\n");
            }
            break;

            case 6:
            printf("Sentando aluno...\n");
            fila_geral = remove_aluno(fila_geral);        
            break;

            case 7:
            printf("Fila normal:\n");
            imprime_fila(fila_normal);
            printf("Fila prioritaria:\n");
            imprime_fila(fila_prioritaria);
            printf("Fila geral:\n");
            imprime_fila(fila_geral);
            printf("\nPilha de bandejas com seus codigos:\n");
            imprime_pilha(pilha_bandejas);
            break;

            case 0:
            printf("Saindo do programa!\n");
            opcao = 0;
            break;

            default:
            printf("Opcao invalida\n");
            break;
        }
    }
    
    return 0;
}