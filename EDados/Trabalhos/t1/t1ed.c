/*Exercício 1) Matriz diagonal 
Faça  um  programa  que  trate  uma  matriz  diagonal  de  inteiros.  O  programa  deve  armazenar  os  valores  da  diagonal 
principal  (que  são  os  não  nulos)  em  um  vetor  v,  e  os  demais  valores  (que  são  nulos)  não  devem  ser  lidos  nem 
armazenados em lugar algum. O programa deve contemplar as operações de: 
- criação da matriz; 
- preenchimento da matriz; 
- impressão da matriz; 
- consulta de um determinado elemento da matriz (para consultar um elemento, informe a linha e a coluna onde ele se 
encontra); 
Use a seguinte definição para a struct:  
struct diagonal 
{ 
    int ordem; //ordem da matriz 
    int* v; //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados 
neste vetor 
}; 
typedef struct diagonal Diagonal*/



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
ordem valores da diagonal 
3 4 3 7 
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



/* Exercício 4) Matriz de n dimensões 
Faça um programa que trate uma matriz de inteiros de 3 dimensões (linhas, colunas e profundidade), conforme figura 
abaixo: 
O programa deve contemplar as operações de: 
- criação da matriz; 
- preenchimento da matriz; 
- impressão da matriz. 
Os seguintes protótipos de funções devem ser usados: 
int*** aloca_matriz (int m, int n, int z); 
void preenche_matriz (int m, int n, int z, int ***mat); 
void imprime_matriz (int m, int n, int z, int ***mat); */