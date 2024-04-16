/*Implemente uma função que receba como parâmetro uma matriz de inteiros de tamanho m x 
n  (alocada  dinamicamente  como  um  vetor  de  ponteiros)  e  imprima  na  tela  os  elementos 
armazenados nesta matriz. Esta função deve obedecer ao protótipo:  
void imprime_matriz (int m, int n, int** mat)*/

#include<stdio.h>
#include<stdlib.h>

void print_matrix(int row, int column, int **matrix)
{
    int i, j;
    for (i=0;i < row; i++)
    {
        for(j=0; j < column; j++)
        {
            printf("matrix[%d][%d]: ", i+1, j+1);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int rows, cols;
    int i, j;

    printf("Digite o numero de linhas da matrix:\n");
    scanf("%d",&rows);
    printf("Digite o numero de colunas da matrix: \n");
    scanf("%d", &cols);

    int **matrix;
    matrix = (int**) malloc(rows*sizeof(int));

    for(i=0; i < rows; i++)
    {
        matrix[i] = (int*) malloc(cols*sizeof(int));
    }

    if(matrix == NULL)
    {
        printf("Malloc error\n");
        exit (1);
    }

    for(i=0; i < rows; i++)
    {
        for(j=0; j < cols; j++)
        {
            printf("Digite o valor da posicao matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    print_matrix(rows, cols, matrix);

    return 0;
}