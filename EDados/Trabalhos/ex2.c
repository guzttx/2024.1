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
            printf("Informe o valor para a posicao (%d, %d): ", i, j);
            scanf("%d", &valor);

            if(valor != 0)
            {
                List* novo = (List*)malloc(sizeof(List));
                if(novo == NULL)
                {
                    printf("Erro ao alocar no\n");
                    exit(1);
                }
                novo->linha = i;
                novo->coluna = j;
                novo->info = valor;
                if(matriz->prim == NULL)   
                {
                    novo->prox = matriz->prim;
                    matriz->prim = novo;
                }
                else
                {
                    List* aux;   
                    for(aux = matriz->prim; aux->prox != NULL; aux = aux->prox);
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
    printf("Elementos da nao nulos da matriz Esparsa:\n");

    for(pointer = matriz->prim; pointer != NULL; pointer = pointer->prox)
    {
        printf("L:%d\t", pointer->linha);
        printf("C:%d\t", pointer->coluna);
        printf("V:%d\n", pointer->info);
    }
    printf("\n");

    printf("Matriz Esparsa:\n");
    pointer = matriz->prim;
    for(int i = 0; i < matriz->linhas; i++)
    {
        for(int j = 0; j < matriz->colunas; j++)
        {
            if(pointer != NULL && pointer->linha == i && pointer->coluna == j)
            {
                printf("%d\t", pointer->info);
                pointer = pointer->prox;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void line_sum(Esparsa *matriz, int line)
{
    List *pointer;
    int sum = 0;

    for(pointer = matriz->prim; pointer != NULL; pointer = pointer->prox)
    {
        if(pointer->linha == line)
        {
            sum += pointer->info;
        }
    }

    printf("Somatorio da linha %d: %d\n\n", line, sum);
}

void percent_not_null(Esparsa *matriz)
{
    List *pointer;
    int count = 0;

    for(pointer = matriz->prim; pointer != NULL; pointer = pointer->prox)
    {
        count++;
    }

    float percent = ((float)count / (matriz->linhas * matriz->colunas)) * 100;
    printf("Percentual de elementos nao nulos: %.2f%%\n", percent);
}

void search_element(Esparsa *matriz, int row, int column)
{
    List *pointer;
    int found = 0;

    for(pointer = matriz->prim; pointer != NULL; pointer = pointer->prox)
    {
        if(pointer->linha == row && pointer->coluna == column)
        {
            printf("Elemento encontrado, (%d, %d): %d\n", row, column, pointer->info);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Elemento encontrado, (%d, %d): 0\n", row, column);
    }
    
    printf("\n");
}

void free_matrix(Esparsa *matriz)
{
    List *pointer, *aux;

    for(pointer = matriz->prim; pointer != NULL; pointer = aux)
    {
        aux = pointer->prox;
        free(pointer);
    }
    free(matriz);
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

    if (rows <= 0 || cols <= 0)
    {
        printf("Valores invalidos\n");
        exit(1);
    }
    else
    {
        matriz = create_matrix(rows, cols);
    }
    
    matriz_insertno(matriz);

    int option, row, column;
    do
    {
        printf("Escolha uma opcao;\n");
        printf("1 - Imprimir matriz;\n");
        printf("2 - Consultar um elemento da matriz;\n");
        printf("3 - Imprimir somatorio de uma linha;\n");
        printf("4 - Imprimir percentual de elementos nao nulos na matriz;\n");
        printf("5 - Sair.\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                print_listamatriz(matriz);
                break;
            case 2:
                printf("Informe a linha para consulta (de 0 a %d): ", matriz->linhas - 1);
                scanf("%d", &row);
                printf("Informe a coluna para consulta (de 0 a %d): ", matriz->colunas - 1);
                scanf("%d", &column);
                if(row >= 0 && row < matriz->linhas && column >= 0 && column < matriz->colunas)
                    search_element(matriz, row, column);
                else
                    printf("Elemento invalido\n\n");
                break;
            case 3:
                printf("Informe a linha para somatorio (de 0 a %d): ", matriz->linhas - 1);
                scanf("%d", &row);
                if(row >= 0 && row < matriz->linhas)
                    line_sum(matriz, row);
                else
                    printf("Linha invalida\n\n");
                break;
            case 4:
                percent_not_null(matriz);
                break;
            case 5:
                printf("\nSaindo do programa!\n");
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }   while(option != 5);

    free_matrix(matriz);

    return 0;
}

