/*Implemente  quatro  funções  que  alocam,  desalocam,  preenchem  e  mostram  uma  matriz  de 
tamanho mxn, respectivamente (considere que a matriz seja armazenada como um vetor de 
ponteiros). Estas funções devem obedecer aos protótipos: 
int** aloca_matriz (int m, int n) 
void desaloca_matriz (int m, int** mat) 
void preenche_matriz (int m, int n, int **mat) 
void mostra_matriz (int m, int n, int **mat)*/

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

int main() 
{
    int row, col;
    int **mat;

        printf("Digite o numero de linhas da matriz: ");
        scanf("%d", &row);
        printf("Digite o numero de colunas da matriz: ");
        scanf("%d", &col);

        mat = matrix_alloc(row, col);
        fill_matrix(row, col, mat);
        print_matrix(row, col, mat);
        free_matrix(row, mat);
    
    return 0;
}