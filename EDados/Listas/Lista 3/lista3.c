/*1. Implemente uma função que tenha como valor de retorno o comprimento de uma lista 
encadeada, isto é calcule o número de nós de uma lista. Esta função deve obedecer ao 
protótipo:  int comprimento (Lista* l);*/

/*2. Considere listas encadeadas de valores inteiros e implemente uma função para 
retornar o número de nós da lista que possuem o campo info com valores maiores do 
que n. Esta função deve obedecer ao protótipo:  int maiores (Lista* l, int n); */

/*3. Implemente uma função que tenha como valor de retorno o ponteiro para o último nó 
de uma lista encadeada. Esta função deve obedecer ao protótipo:  Lista* ultimo (Lista* l);*/

/*4. Implemente  uma  função  que  receba  duas  listas  encadeadas  de  valores  inteiros  e 
retorne  a lista resultante  da concatenação  das duas listas recebidas como parâmetros, 
isto  é,  após  a  concatenação,  o  último  elemento  da  primeira  lista  deve  apontar  para  o 
primeiro elemento da segunda lista. Esta função deve obedecer ao protótipo: Lista* concatena (Lista* l1, Lista* l2); */

#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info; // campo para armazenar a informação
    struct lista *next;  // ponteiro para o próximo elemento da lista
};
typedef struct lista list; 

list* cria_lista()
{
    return NULL;
}

list* insert_list(list* lista, int numero)
{
    list* novo = (list*) malloc(sizeof(list));
    novo->info = numero;
    novo->next = lista;
    return novo;
}

void imprime_lista(list* lista)
{
    list* pointer;
    for (pointer = lista; pointer != NULL; pointer = pointer -> next)
    {
        printf("%d", pointer->info);
        if(pointer -> next != NULL)
        {
            printf(", ");
        }   
        else
        {
            printf("\n");
        }
    }
}

int comprimento(list* lista)
{
    int cont = 0;
    list *pointer;
    for(pointer = lista; pointer != NULL; pointer = pointer -> next)
    {
        cont++;
    }
    return cont;
}

int maiores(list* lista, int n)
{
    list *pointer;
    int cont = 0;
    for(pointer = lista; pointer != NULL; pointer = pointer->next)
    {
        if(pointer->info > n)
        {
            cont++;
        }
    }
    return cont;
}

int ultimo(list* lista)
{
    list *pointer;
    for(pointer = lista; pointer -> next != NULL; pointer = pointer->next);
    return pointer->info;
}

list* concat_list(list* lista1, list* lista2)
{
    list* pointer;
    for(pointer = lista1; pointer -> next != NULL; pointer = pointer->next);
    pointer->next = lista2;
    return lista1;
    //Faz um for que percorre a lista1 até o último elemento(quando pointer->next == null) 
    //e faz o ponteiro do último elemento apontar para o primeiro elemento da lista2
}

int main()
{
    list* lista = cria_lista();

    int n;
    do
    {
        printf("Digite um numero a ser inserido na lista ou digite -1 para sair: ");
        scanf("%d", &n);
        if (n != -1)
        {
            lista = insert_list(lista, n);
        }
    } while (n != -1);

    imprime_lista(lista);

    int list_size = comprimento(lista);
    printf("%d eh o tamanho da lista", list_size);

    int greater, numero;
    printf("\nDigite um numero para verificar quantos numeros maiores que ele existem na lista: ");
    scanf("%d", &numero);
    greater = maiores(lista, numero);
    printf("\nExistem %d numeros maiores que %d na lista", greater, numero);

    int last = ultimo(lista);
    printf("\nO ultimo numero da lista eh %d", last);

    list* lista2 = cria_lista();
    
    do
    {
        printf("\nDigite um numero a ser inserido na segunda lista ou digite -1 para sair: ");
        scanf("%d", &n);
        if (n != -1)
        {
            lista2 = insert_list(lista2, n);
        }
    } while (n != -1);

    lista = concat_list(lista, lista2);
    imprime_lista(lista);

    return 0;
}