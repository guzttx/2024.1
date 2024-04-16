/*Implemente uma função que receba como parâmetro duas matrizes de inteiros de tamanho m 
x  n  (alocadas  dinamicamente  como  vetor  de  ponteiros),  soma  as  duas  matrizes  (nas 
respectivas posições), armazene esta soma numa terceira matriz e retorne a matriz resultante. 
Esta função deve obedecer ao protótipo: 
int** soma_matriz (int m, int n, int** mat1, int** mat2) 
Use as funções anteriormente criadas para alocar, desalocar, preencher e mostrar as matrizes, 
quando necessário.*/

#include <stdio.h>
#include <stdlib.h>

int** matrix_alloc(int rows, int cols)
{
    int i;
    int **mat;

    mat = (int**)malloc(rows*sizeof(int));

    if(mat == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        system("pause");
        exit(1);
    }    
    
    for(i=0; i<rows; i++)
    {
        mat[i] = (int*)malloc(cols*sizeof(int));
        if(mat[i] == NULL)
        {
            printf("Erro na alocacao de memoria\n");
            system("pause");
            exit(1);
        }
    }
    
    return mat;
}

void free_matrix(int rows, int **matrix)
{
    int i;
    for (i=0;i<rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int rows, int cols, int **matrix)
{
    int i, j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<rows; j++)
        {
            printf("Digite o valor da posicao matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int rows, int cols, int **matrix)
{
    int i, j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<rows; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** matrix_add(int rows, int cols, int**mat1, int**mat2)
{
    int i, j, **soma;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            soma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return soma;
}

int main() 
{
    int row, col;
    int **mat1, **mat2, **soma;

        printf("Digite o numero de linhas das matrizes: ");
        scanf("%d", &row);
        printf("Digite o numero de colunas das matrizes: ");
        scanf("%d", &col);

        printf("Matriz 1:\n");
        mat1 = matrix_alloc(row, col);
        fill_matrix(row, col, mat1);
        print_matrix(row, col, mat1);

        printf("Matriz 2:\n");
        mat2 = matrix_alloc(row, col);
        fill_matrix(row, col, mat2);
        print_matrix(row, col, mat2);

        soma = matrix_alloc(row, col);
        soma = matrix_add(row, col, mat1, mat2);

        free_matrix(row, mat1);
        free_matrix(row, mat2);
    
        printf("Matriz soma:\n");
        print_matrix(row, col, soma);

        free_matrix(row, soma);

    return 0;
}