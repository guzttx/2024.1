/*Exercício 2) Matriz Esparsa 
Faça  um  programa  que  trate  uma  matriz  Esparsa  de  inteiros.  O  programa  deve  armazenar  os  valores  não  nulos  da 
matriz Esparsa em uma Lista simplesmente encadeada (ver struct Lista), e os demais valores (que são nulos) não devem 
ser lidos nem armazenados em lugar algum. O programa deve contemplar as operações de: 
- criação da matriz; 
- preenchimento da matriz (ler apenas os valores não nulos); 
- impressão da matriz; 
- consulta de um determinado elemento da matriz (para consultar um elemento, informe a linha e a coluna onde ele se 
encontra); 
- impressão de somatório de uma linha i (informada pelo usuário); 
- percentual de elementos não nulos na matriz lida. 
Use as seguintes definições para as structs:  */

#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista* prox;
}; 
typedef struct lista List;

struct espars
{
    int linhas;
    int colunas;
    struct lista* prim;
};
typedef struct espars Esparsa;

Esparsa* create_matrix(int rows, int cols)
{
    Esparsa* matriz = (Esparsa*)malloc(sizeof(Esparsa));
    if(matriz == NULL)
    {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }
    matriz->linhas = rows;
    matriz->colunas = cols;
    if(matriz->linhas <= 0 || matriz->colunas <= 0)
    {
        printf("Matriz invalida\n");
        exit(1);
    }
    matriz->prim = NULL;

    return matriz;
}

void matriz_insertno(Esparsa* matriz)
{
    int i, j, valor;
    for(i = 0; i < matriz->linhas; i++)
    {
        for(j = 0; j < matriz->colunas; j++)
        {
            printf("Informe o valor para a posicao (%d, %d):\n", i, j);
            scanf("%d", &valor);

            if(valor != 0)
            {
                List* novo = (List*)malloc(sizeof(List));
                if(novo == NULL)
                {
                    printf("Erro ao alocar no\n");
                    exit(1);
                }
                if(matriz->prim == NULL)    //    insercao do primeiro elemento no inicio da lista
                {
                    novo->linha = i;
                    novo->coluna = j;
                    novo->info = valor;
                    novo->prox = matriz->prim;
                    matriz->prim = novo;
                }
                else
                {
                    List* aux;      //  insercao dos demais elementos no final da lista
                    for(aux = matriz->prim; aux->prox != NULL; aux = aux->prox);
                    novo->linha = i;
                    novo->coluna = j;
                    novo->info = valor;
                    novo->prox = NULL;
                    aux->prox = novo;
                }
            }
        }
    }
}

void print_listamatriz(Esparsa *matriz)
{
    List *pointer;

    printf("Numero de linhas: %d\n", matriz->linhas);
    printf("Numero de colunas: %d\n", matriz->colunas);
    printf("Elementos da matriz Esparsa:\n");

    for(pointer = matriz->prim; pointer != NULL; pointer = pointer->prox)
    {
        printf("L:%d\t", pointer->linha);
        printf("C:%d\t", pointer->coluna);
        printf("V:%d\n", pointer->info);
    }
}

int main()
{
    Esparsa *matriz;
    List *Lo_lista;
    int rows, cols;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &rows);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &cols);

    matriz = create_matrix(rows, cols);

    matriz_insertno(matriz);

    int option;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Imprimir matriz\n");
        printf("2 - Consultar um elemento da matriz\n");
        printf("3 - Imprimir somatorio de uma linha i\n");
        printf("4 - Imprimir percentual de elementos nao nulos na matriz\n");
        printf("5 - Sair\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                print_listamatriz(matriz);
                break;
            case 2:
                //consulta de um determinado elemento da matriz
                break;
            case 3:
                //impressão de somatório de uma linha i
                break;
            case 4:
                //percentual de elementos não nulos na matriz lida
                break;
            case 5:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while(option != 5);

    return 0;
}
