#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
#include "aluno.h"

/*1. Ingresso de alunos na fila de prioridade normal; 
2. Ingresso de alunos na fila de prioridade alta; 
3. Fusão  das  duas  filas  em  uma  fila  única  para  ingresso  no  restaurante,  obedecendo  ao 
critério de prioridade; 
4. Colocação de bandejas pelo funcionário do restaurante; 
5. Retirada de bandeja pelo aluno da fila única; 
6. Retirada de aluno da fila única após ter se servido no buffet; 
7. Impressão das 3 filas (normal, com prioridade e única) e da pilha.*/

int main()
{
    int opcao = 1;

    
    Fila *fila_normal = cria_fila();
    Fila *fila_prioritaria = cria_fila();
    Fila *fila_geral = cria_fila();

    Pilha *pilha_bandejas = cria_pilha();

    Refeitorio *refeitorio = cria_refeitorio();

    while(opcao != 0)
    {
        switch (opcao)
        {
            case 1:
            printf("Inserir fila normal\n");
            insere_fila(fila_normal, 0);
            break;
            
            case 2:
            printf("Inserir na fila prioritaria\n");
            insere_fila(fila_prioritaria, 1);            
            break;
            
            case 3:
            printf("Fundir filas\n");
            fila_geral = concatenar_filas(fila_normal, fila_prioritaria);
            break;

            case 4:
            printf("Completar pilha com bandejas\n");
            adiciona_bandejas(pilha_bandejas);
            break;

            case 5:
            printf("Retirar bandeja\n");
            remove_bandeja(pilha_bandejas);
            break;

            case 6:
            printf("Sentar aluno\n");
            Aluno *aux = tira_fila(fila_geral);
            senta_refeitorio(aux, refeitorio);            
            break;

            case 7:
            printf("Imprimir filas e pilha\n");
            imprime_fila(fila_normal);
            imprime_fila(fila_prioritaria);
            break;

            case 8:
            printf("Imprimir refeitorio\n");
            imprime_refeitorio(refeitorio);
            break;

            case 0:
            printf("Sair\n");
            opcao = 0;
            break;

            default:
            printf("Opcao invalida\n");
            break;
        }
    }
    
    return 0;
}