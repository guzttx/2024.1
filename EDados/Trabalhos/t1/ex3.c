/* Exercicio 3
Faça  um  programa  que  trate  uma  matriz  quadrada  de  ordem  N.  O  programa  deve  armazenar  os  valores  da  matriz  e 
verificar se é uma matriz identidade. Se não for, mostrar quais elementos e suas respectivas posições (linha e coluna) 
que violaram a propriedade de matriz identidade.  
O programa deve contemplar as operações de: 
- criação da matriz; 
- preenchimento da matriz; 
- impressão da matriz; 
- mostra de elementos (com sua respectiva linha e coluna) que violam a propriedade da identidade.  
Proponha  uma  definição  para  a  struct  que  representa  a  matriz  identidade,  usando  listas,  de  uma  forma  otimizada  em 
termos de armazenamento. Não aloque espaços desnecessários.*/


#include<stdio.h>
#include<stdlib.h>

struct diferente
{
    int linha;
    int coluna;
    int valor;
    struct diferente *next;
};
typedef struct diferente Elemento;

struct matriz
{
    int ordem;
    struct diferente *first;
};
typedef struct matriz Diagonal;

Diagonal* create_matrix(int numero)
{
    Diagonal* matriz = (Diagonal*)malloc(sizeof(Diagonal));
    if(matriz ==  NULL)
    {
        printf("Erro na alocacao da matriz");
    }
    
    matriz->ordem = numero;
    matriz->first = NULL;
    
    return matriz;
}

void insert_diagonal(Diagonal *matriz, Elemento* diferente, int numero, int coordenada)
{
    diferente->linha = coordenada;
    diferente->coluna = coordenada;
    diferente->valor = numero;
    diferente->next = NULL;

    if(matriz->first == NULL)
    {
        matriz->first = diferente;
    }
    else
    {
        Elemento *aux;
        for(aux = matriz->first; aux->next != NULL; aux = aux->next);
        aux->next = diferente;
    }
}

void insert_randompos(Diagonal *matriz, Elemento* diferente, int numero, int row, int col)
{
    diferente->linha = row;
    diferente->coluna = col;
    diferente->valor = numero;
    diferente->next = NULL;

    if(matriz->first == NULL)
    {
        matriz->first = diferente;
    }
    else
    {
        Elemento *aux;
        for(aux = matriz->first; aux->next != NULL; aux = aux->next);
        aux->next = diferente;
    }
}

void insert_elements(Diagonal *matriz)
{
    int i, j;
    int numero;

    for(i=0; i<matriz->ordem; i++)
    {
        for (j=0; j<matriz->ordem; j++)
        {
            printf("Digite o valor da posicao (%d, %d): ", i, j);
            scanf("%d", &numero);
            if(i == j && numero != 1)
            {
                Elemento* diferente_diag = (Elemento*)malloc(sizeof(Elemento));
                if(diferente_diag == NULL)
                {
                    printf("Erro ao alocar memoria para elemento.\n");
                    exit(1);
                }

                insert_diagonal(matriz, diferente_diag, numero, i);
            }

            if(i != j && numero != 0)
            {
                Elemento* diferente = (Elemento*)malloc(sizeof(Elemento));
                if(diferente == NULL)
                {
                    printf("Erro ao alocar memoria para elemento.\n");
                    exit (1);
                }
                insert_randompos(matriz, diferente, numero, i, j);
            }
        }
    }
}

void print_matrix(Diagonal *matriz)
{
    if(matriz->first == NULL)
    {
        int i, j;
        printf("A matriz eh identidade e eh representada:\n");
        
        for (i = 0; i < matriz->ordem; i++)
        {
            for(j = 0; j < matriz->ordem; j++)
            {
                if(i==j)
                {
                    printf("1\t");
                }
                else
                {
                    printf("0\t");
                }
            }
            printf("\n");
        }
    }

    else
    {
        printf("A matriz nao eh identidade.\n");
        printf("Os elementos que nao estao de acordo com a matriz identidade sao:\n");
        Elemento *pointer;
        for(pointer = matriz->first; pointer != NULL; pointer = pointer->next)
        {
            printf("(%d, %d): %d\n",pointer->linha, pointer->coluna, pointer->valor);
        }
        printf("A matriz eh:\n");

        int i, j;
        pointer = matriz->first;

        for(i=0; i < matriz->ordem; i++)
        {
            for(j=0; j < matriz->ordem; j++)
            {
                if(pointer != NULL && pointer->linha == i && pointer->coluna == j)
                {
                    printf("%d\t", pointer->valor);
                    pointer = pointer->next;
                }
                else
                {
                    if(i == j)
                    {
                        printf("1\t");
                    }
                    else
                    {
                        printf("0\t");
                    }
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    Diagonal *matriz;
    int ordem;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    matriz = create_matrix(ordem);

    insert_elements(matriz);
    print_matrix(matriz);

    return 0;
}