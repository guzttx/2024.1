/*Exercício 2) Matriz esparsa 
Faça  um  programa  que  trate  uma  matriz  esparsa  de  inteiros.  O  programa  deve  armazenar  os  valores  não  nulos  da 
matriz esparsa em uma lista simplesmente encadeada (ver struct Lista), e os demais valores (que são nulos) não devem 
ser lidos nem armazenados em lugar algum. O programa deve contemplar as operações de: 
- criação da matriz; 
- preenchimento da matriz (ler apenas os valores não nulos); 
- impressão da matriz; 
- consulta de um determinado elemento da matriz (para consultar um elemento, informe a linha e a coluna onde ele se 
encontra); 
- impressão de somatório de uma linha i (informada pelo usuário); 
- percentual de elementos não nulos na matriz lida. 
Use as seguintes definições para as structs:  
struct  lista  //lista  de  valores  não  nulos  da matriz  esparsa.  Os  elementos  não nulos da  matriz  são  armazenados  nesta 
lista. Os valores restantes, q são nulos, não são armazenados em nenhum lugar. 
{ 
    int linha; // linha onde se encontra o elemento não nulo 
    int coluna; // coluna onde se encontra o elemento não nulo 
    int info; // valor do  elemento não nulo 
struct lista* prox; // apontador para o proximo elemento não nulo da matriz 
}; 
typedef struct lista Lista; 
struct esparsa 
{ 
    int linhas; //numero de linhas da matriz 
    int colunas; //numero de colunas da matriz 
    struct lista* prim; //apontador para o primeiro noh não nulo da matriz  
}; 
typedef struct esparsa Esparsa;*/

#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
}; 
typedef struct lista list;

struct espars
{
    int linhas;
    int colunas;
    struct lista *prim;
};
typedef struct espars esparsa;

esparsa* cria_matriz()
{
    return NULL;
}